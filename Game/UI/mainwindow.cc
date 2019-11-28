#include "UI/mainwindow.hh"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent,
                     std::shared_ptr<Student::GameEventHandler> handler):
    QMainWindow(parent),
    m_ui_(new Ui::MainWindow),
    m_GEHandler_(handler),
    m_scene_(new Student::GameScene(this))
{
    m_ui_->setupUi(this);
    this->setWindowTitle("Colonizing Pirkanmaa");
    m_GEHandler_ = std::make_shared<Student::GameEventHandler>
            (Student::GameEventHandler());
    timer_ = new QTimer(this);
    Dialog dialogwindow;
    dialogwindow.setWindowTitle("Colonizing Pirkanmaa");

    connect(&dialogwindow, SIGNAL(sendMapValue(int)), this,
            SLOT(setGridSize(int)));
    connect(&dialogwindow, SIGNAL(sendRoundValue(int)), this,
            SLOT(setRounds(int)));
    connect(&dialogwindow,
            SIGNAL(sendPlayer(std::vector<std::shared_ptr<Student::Player>>)),
            this,
            SLOT(getPlayer(std::vector<std::shared_ptr<Student::Player>>)));
    connect(m_ui_->endTurnPushButton, SIGNAL(clicked(bool)), this,
            SLOT(changeTurn()));
    connect(m_ui_->buildPushButton, SIGNAL(clicked(bool)), this,
            SLOT(actionBuild()));
    connect(m_ui_->recruitPushButton, SIGNAL(clicked(bool)), this,
            SLOT(actionRecruit()));
    connect(m_scene_.get(), SIGNAL(sendID(unsigned int)), this,
            SLOT(getId(unsigned int)));
    connect(m_ui_->buildingsComboBox, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(updateBuildingInfo(QString)));
    connect(m_ui_->recruitsComboBox, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(updateWorkerInfo(QString)));
    connect(timer_,SIGNAL(timeout()), this, SLOT(timeOut()));

    if(dialogwindow.exec() == 0){
        exit(0);
    }

    QStringList buildings = {"HeadQuarters", "Outpost", "Farm", "Mine",
                             "Trawler", "Sawmill"};
    m_ui_->buildingsComboBox->addItems(buildings);

    QStringList workers = {"BasicWorker","Fisher", "Miner", "Lumberjack",
                           "PeatWorker", "Farmer"};
    m_ui_->recruitsComboBox->addItems(workers);


    this->setSize(2*m_size_, m_size_);
    this->setScale(50);
    m_ui_->graphicsView->setFrameStyle(0);
    m_ui_->graphicsView->setScene(m_scene_.get());
    m_ui_->graphicsView->setAutoFillBackground(true);
    m_ui_->graphicsView->setBackgroundBrush(Qt::lightGray);

    m_objM_ = std::make_shared<Student::ObjectManager>();
    m_GEHandler_->setObjectManager(m_objM_);

    Course::WorldGenerator* worldG = &Course::WorldGenerator::getInstance();
    worldG->addConstructor<Course::Forest>(8);
    worldG->addConstructor<Course::Grassland>(15);
    worldG->addConstructor<Student::Swamp>(4);
    worldG->addConstructor<Student::Water>(3);
    worldG->addConstructor<Student::Cobblestone>(2);
    worldG->generateMap(2*m_size_, m_size_,1, m_objM_, m_GEHandler_);

    std::vector<std::shared_ptr<Course::TileBase>> tiles =
            m_objM_->getTiles();

    for(auto brick : tiles)
    {
        m_scene_->drawItem(brick);
    }

    this->updateLabels();

    QPalette backgroundPalette;
    backgroundPalette.setBrush(QPalette::Background, Qt::lightGray);
    this->setPalette(backgroundPalette);

}

MainWindow::~MainWindow()
{
    delete m_ui_;
}

int MainWindow::getGridSize()
{
    return m_size_;
}

int MainWindow::getRoundSize()
{
    return gameRounds_;
}

void MainWindow::setGridSize(int size)
{
    m_size_ = size;
}

void MainWindow::setRounds(int amount)
{
    gameRounds_ = amount;
}

void MainWindow::getPlayer(
        std::vector<std::shared_ptr<Student::Player>> players)
{
    m_GEHandler_->addPlayers(players);
}

void MainWindow::changeTurn()
{

    m_GEHandler_->changeTurn();


    if(m_GEHandler_->getRoundNumber() > gameRounds_){
        EndDialog ending(this,m_GEHandler_->getScores());
        connect(&ending, SIGNAL(finished(int)),
                this, SLOT(exitGame(int)));
        ending.exec();

    }
    this->updateLabels();
    clickedTileObj_ = nullptr;
    m_ui_->tileInfoLabel->clear();
    m_scene_->removeMarker();
    timeOut();
}

void MainWindow::getId(unsigned int Id)
{
    clickedTileObj_ = m_objM_->getTile(Id);
    this->updateTileInfo();
    m_scene_->drawMarker(clickedTileObj_->getCoordinate().asQpoint());
}

void MainWindow::actionBuild()
{
    if (!clickedTileObj_){
        updateGameInfo("Select a tile to build!");
        return;
    }

    if (clickedTileObj_->getOwner() != m_GEHandler_->getPlayerInTurn()){
        if(m_ui_->buildingsComboBox->currentText().toStdString() !=
                "HeadQuarters" &&
                m_ui_->buildingsComboBox->currentText().toStdString() !=
                "Outpost"){

            updateGameInfo("Cannot build on unowned tile!");
            return;
        }
    }

    std::shared_ptr<Course::BuildingBase> building;

    std::shared_ptr<Student::Player> tempPlayer = m_GEHandler_->
            getPlayerInTurn();
    if(tempPlayer->funcHasBuiltHq() &&
            m_ui_->buildingsComboBox->currentText().toStdString() ==
            "HeadQuarters"){
        updateGameInfo("Cannot build more than one HQ!");
        return;
    }
    constructWantedBuilding(building);

    if(!building->canBePlacedOnTile(clickedTileObj_)){
        updateGameInfo("Cannot build this building on the tile!");
        return;
    }

    if(!m_GEHandler_->modifyResources(m_GEHandler_->getPlayerInTurn(),
       m_GEHandler_->resourcemapMakeNegative(building->BUILD_COST)))
    {
        updateGameInfo("Too few resources to build!");
        return;
    }

    if(clickedTileObj_->getBuildingCount() != 0)
    {
        updateGameInfo("Building capacity is already maxed!");
        return;
    }

    clickedTileObj_->setOwner(m_GEHandler_->getPlayerInTurn());
    clickedTileObj_->addBuilding(building);
    m_GEHandler_->getPlayerInTurn()->addObject(building);

    m_objM_->addBuilding(building);
    building->onBuildAction();
    m_scene_->drawItem(building);

    this->updateLabels();
    this->updateTileInfo();
    updateTileBorders();

    if(m_ui_->buildingsComboBox->currentText().toStdString() ==
            "HeadQuarters"){
        tempPlayer->changeHQBuildStatus();
    }

}

void MainWindow::actionRecruit()
{
    if (!clickedTileObj_){
        return;
    }

    if (clickedTileObj_->getOwner() != m_GEHandler_->getPlayerInTurn()){
        return;
    }

    std::shared_ptr<Course::WorkerBase> recruit;
    constructWantedRecruit(recruit);

    if(!recruit->canBePlacedOnTile(clickedTileObj_)){
        return;
    }
    if(!m_GEHandler_->modifyResources(m_GEHandler_->getPlayerInTurn(),
           m_GEHandler_->resourcemapMakeNegative(recruit->RECRUITMENT_COST))){
        return;
    }
    clickedTileObj_->addWorker(recruit);
    m_GEHandler_->getPlayerInTurn()->addObject(recruit);
    m_objM_->addWorker(recruit);


    this->updateLabels();
    this->updateTileInfo();

}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    m_ui_->graphicsView->setFixedWidth(2*(m_ui_->graphicsView->height()));

    if(m_ui_->graphicsView->scene()){
        m_ui_->graphicsView->fitInView(
               m_ui_->graphicsView->scene()->sceneRect(),Qt::KeepAspectRatio);
    }
}

void MainWindow::updateBuildingInfo(QString buildingName)
{
    QImage image = m_scene_->getImage(buildingName.toStdString());
    m_ui_->buildingInfoLabel->setPixmap(QPixmap::fromImage(image));

    Course::ResourceMap resourcemap;

    if(buildingName == "HeadQuarters"){
        resourcemap = Course::ConstResourceMaps::HQ_BUILD_COST;
    }
    else if(buildingName == "Outpost"){
        resourcemap = Course::ConstResourceMaps::OUTPOST_BUILD_COST;
    }
    else if(buildingName == "Farm"){
        resourcemap = Course::ConstResourceMaps::FARM_BUILD_COST;
    }
    else if(buildingName == "Mine"){
        resourcemap = Course::ConstResourceMaps::MINE_BUILD_COST;
    }
    else if(buildingName == "Trawler"){
        resourcemap = Course::ConstResourceMaps::TRAWLER_BUILD_COST;
    }
    else if(buildingName == "Sawmill"){
        resourcemap = Course::ConstResourceMaps::SAWMILL_BUILD_COST;
    }

    m_ui_->BuildCostAmntLabel->setText(
        QString::number(resourcemap.at(Course::BasicResource::MONEY)) + "\n" +
        QString::number(resourcemap.at(Course::BasicResource::FOOD)) + "\n" +
        QString::number(resourcemap.at(Course::BasicResource::WOOD)) + "\n" +
        QString::number(resourcemap.at(Course::BasicResource::STONE)));
}

void MainWindow::updateWorkerInfo(QString workerName)
{
    Course::ResourceMap resourcemap;

    if(workerName == "BasicWorker"){
        resourcemap = Course::ConstResourceMaps::BW_RECRUITMENT_COST;
    }
    else if(workerName== "Fisher"){
        resourcemap = Course::ConstResourceMaps::FISHER_RECRUITMENT_COST;
    }
    else if(workerName == "Miner"){
        resourcemap = Course::ConstResourceMaps::MINER_RECRUITMENT_COST;
    }
    else if(workerName == "Lumberjack"){
        resourcemap = Course::ConstResourceMaps::LUMBERJACK_RECRUITMENT_COST;
    }
    else if(workerName == "PeatWorker"){
        resourcemap = Course::ConstResourceMaps::PEATWORKER_RECRUITMENT_COST;
    }
    else if(workerName == "Farmer"){
        resourcemap = Course::ConstResourceMaps::FARMER_RECRUITMENT_COST;
    }

    m_ui_->RecruitCostAmntLabel->setText(
        QString::number(resourcemap.at(Course::BasicResource::MONEY)) + "\n" +
        QString::number(resourcemap.at(Course::BasicResource::FOOD)) + "\n" +
        QString::number(resourcemap.at(Course::BasicResource::WOOD)) + "\n" +
        QString::number(resourcemap.at(Course::BasicResource::STONE)));
}

void MainWindow::exitGame(int code)
{
    if(code){
        qApp->exit(1000);
    }
    else{
        qApp->exit(0);
    }
}


void MainWindow::timeOut()
{
    timer_->stop();
    m_ui_->gameInfoLabel->setText("");
}

void MainWindow::constructWantedBuilding(
        std::shared_ptr<Course::BuildingBase>& building)
{
    std::string wantedBuilding = m_ui_->buildingsComboBox->
                                currentText().toStdString();

    if(wantedBuilding == "HeadQuarters" )
    {
        building = std::make_shared<Student::StudentHeadQuarters>(m_GEHandler_,
                                    m_objM_, m_GEHandler_->getPlayerInTurn());
    }
    else if(wantedBuilding == "Outpost")
    {
        building = std::make_shared<Student::StudentOutpost>(m_GEHandler_,
                                    m_objM_, m_GEHandler_->getPlayerInTurn());
    }
    else if(wantedBuilding == "Farm")
    {
        building = std::make_shared<Student::StudentFarm>(m_GEHandler_,
                                    m_objM_, m_GEHandler_->getPlayerInTurn());
    }
    else if(wantedBuilding == "Mine")
    {
        building = std::make_shared<Student::Mine>(m_GEHandler_,
                                    m_objM_, m_GEHandler_->getPlayerInTurn());
    }
    else if(wantedBuilding == "Trawler")
    {
        building = std::make_shared<Student::Trawler>(m_GEHandler_,
                                    m_objM_, m_GEHandler_->getPlayerInTurn());
    }
    else if(wantedBuilding == "Sawmill" )
    {
        building = std::make_shared<Student::Sawmill>(m_GEHandler_,
                                    m_objM_, m_GEHandler_->getPlayerInTurn());
    }
}

void MainWindow::constructWantedRecruit(std::shared_ptr<Course::WorkerBase> &worker)
{
    std::string wantedRecruit = m_ui_->recruitsComboBox->
            currentText().toStdString();
    if (wantedRecruit == "BasicWorker") {
            worker = std::make_shared<Course::BasicWorker>(m_GEHandler_,
                                                           m_objM_, m_GEHandler_->getPlayerInTurn());
    }
    else if (wantedRecruit == "Miner") {
            worker = std::make_shared<Student::Miner>(m_GEHandler_,
                                                           m_objM_, m_GEHandler_->getPlayerInTurn());
    }
    else if (wantedRecruit == "Fisher") {
            worker = std::make_shared<Student::Fisher>(m_GEHandler_,
                                                           m_objM_, m_GEHandler_->getPlayerInTurn());
    }
    else if (wantedRecruit == "Farmer") {
            worker = std::make_shared<Student::Farmer>(m_GEHandler_,
                                                           m_objM_, m_GEHandler_->getPlayerInTurn());
    }
    else if (wantedRecruit == "Lumberjack") {
            worker = std::make_shared<Student::Lumberjack>(m_GEHandler_,
                                                           m_objM_, m_GEHandler_->getPlayerInTurn());
    }
    else if (wantedRecruit == "PeatWorker") {
            worker = std::make_shared<Student::PeatWorker>(m_GEHandler_,
                                                           m_objM_, m_GEHandler_->getPlayerInTurn());
    }
}

void MainWindow::setGEHandler(std::shared_ptr<Student::GameEventHandler> nHandler)
{
    m_GEHandler_ = nHandler;
}

void MainWindow::setSize(int width, int height)
{
    m_scene_->setSize(width, height);
}

void MainWindow::setScale(double scale)
{
    m_scene_->setScale(scale);
}

void MainWindow::resize()
{
    m_scene_->resize();
}

void MainWindow::updateLabels()
{
    auto playerInTurn = m_GEHandler_->getPlayerInTurn();
    auto resources = playerInTurn->getResources();
    auto playerName = playerInTurn->getName();
    auto roundNumber = m_GEHandler_->getRoundNumber();

    m_ui_->turnNameLabel->setText
            (QString::fromStdString(playerName));

    m_ui_->roundNumberLabel->setText
            (QString::fromStdString(std::to_string(roundNumber)));

    std::string resource_amount = "";

    resource_amount = std::to_string(resources[Course::BasicResource::MONEY]);
    m_ui_->moneyAmountLabel->setText(QString::fromStdString(resource_amount));

    resource_amount = std::to_string(resources[Course::BasicResource::FOOD]);
    m_ui_->foodAmountLabel->setText(QString::fromStdString(resource_amount));

    resource_amount = std::to_string(resources[Course::BasicResource::STONE]);
    m_ui_->stoneAmountLabel->setText(QString::fromStdString(resource_amount));

    resource_amount = std::to_string(resources[Course::BasicResource::WOOD]);
    m_ui_->woodAmountLabel->setText(QString::fromStdString(resource_amount));
}

void MainWindow::updateTileInfo()
{
    std::shared_ptr<Course::TileBase> tile = clickedTileObj_;

    QString type = QString::fromStdString(tile->getType());
    QString x = QString::number(tile->getCoordinate().x());
    QString y = QString::number(tile->getCoordinate().y());
    QString owner;
    if (tile->getOwner()){
            owner = QString::fromStdString(tile->getOwner()->getName());
    }
    else{
        owner = "None";
    }
    QStringList buildings;
    for (auto building : tile->getBuildings()){
        buildings.push_back(QString::fromStdString(building->getType()));
    }
    QStringList workers;
    for (auto worker : tile->getWorkers()){
        workers.push_back(QString::fromStdString(worker->getType()));
    }

    m_ui_->tileInfoLabel->setText("(" + x + "," + y + ") " + type + "\n"
                                 + "Owner: " + owner + "\n"
                                 + "Buildings:"+ "\n");
    for (auto building : buildings){
        m_ui_->tileInfoLabel->setText(m_ui_->tileInfoLabel->text() + "-- " +
                                      building + "\n");
    }
    m_ui_->tileInfoLabel->setText(m_ui_->tileInfoLabel->text() +
                                  "Workers:"+ "\n");
    for (auto worker : workers){
        m_ui_->tileInfoLabel->setText(m_ui_->tileInfoLabel->text() + "-- " +
                                      worker + "\n");
    }
    m_ui_->tileInfoLabel->setWordWrap(true);
    m_ui_->tileInfoLabel->setAlignment(Qt::AlignTop);

}

void MainWindow::updateTileBorders()
{
    for (auto tile : m_objM_->getTiles()){
        if (auto owner = tile->getOwner()){
            auto player = std::dynamic_pointer_cast<Student::Player>(owner);
            m_scene_->drawBorder(player->getColor(),
                                 tile->getCoordinate().asQpoint());
        }
    }
}

void MainWindow::updateGameInfo(std::string infoText)
{
    m_ui_->gameInfoLabel->setText(QString::fromStdString(infoText));
    timer_->start(5000);
}
