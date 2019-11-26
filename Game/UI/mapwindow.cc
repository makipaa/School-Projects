#include "UI/mapwindow.hh"
#include "ui_mapwindow.h"


MapWindow::MapWindow(QWidget *parent,
                     std::shared_ptr<Student::GameEventHandler> handler):
    QMainWindow(parent),
    m_ui(new Ui::MapWindow),
    m_GEHandler(handler),
    m_scene(new Student::GameScene(this))
{
    m_ui->setupUi(this);
    this->setWindowTitle("Colonizing Pirkanmaa");
    m_GEHandler = std::make_shared<Student::GameEventHandler>
            (Student::GameEventHandler());

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
    connect(m_ui->endTurnPushButton, SIGNAL(clicked(bool)), this, SLOT(changeTurn()));
    connect(m_ui->buildPushButton, SIGNAL(clicked(bool)), this, SLOT(actionBuild()));
    connect(m_ui->recruitPushButton, SIGNAL(clicked(bool)), this, SLOT(actionRecruit()));
    connect(m_scene.get(), SIGNAL(sendID(unsigned int)), this, SLOT(getId(unsigned int)));


    dialogwindow.exec();

    QStringList buildings = {"HeadQuarters", "Outpost", "Farm", "Mine",
                             "Trawler", "Sawmill"};
    m_ui->buildingsComboBox->addItems(buildings);

    QStringList workers = {"BasicWorker","Fisher", "Miner", "Lumberjack",
                           "PeatWorker", "Farmer"};
    m_ui->recruitsComboBox->addItems(workers);


    this->setSize(2*m_size, m_size);
    this->setScale(50);
    m_ui->graphicsView->setFrameStyle(0);
    m_ui->graphicsView->setScene(m_scene.get());
    m_ui->graphicsView->setAutoFillBackground(true);
    m_ui->graphicsView->setBackgroundBrush(Qt::lightGray);

    QPalette textLabelPalette;
    textLabelPalette.setColor(QPalette::WindowText, Qt::black);

    m_ui->resourcesLabel->setPalette(textLabelPalette);

    m_ui->moneyLabel->setPalette(textLabelPalette);
    m_ui->moneyAmountLabel->setPalette(textLabelPalette);

    m_ui->foodLabel->setPalette(textLabelPalette);
    m_ui->foodAmountLabel->setPalette(textLabelPalette);

    m_ui->woodLabel->setPalette(textLabelPalette);
    m_ui->woodAmountLabel->setPalette(textLabelPalette);

    m_ui->stoneLabel->setPalette(textLabelPalette);
    m_ui->stoneAmountLabel->setPalette(textLabelPalette);

    m_ui->turnLabel->setPalette(textLabelPalette);
    m_ui->turnNameLabel->setPalette(textLabelPalette);
    m_ui->roundLabel->setPalette(textLabelPalette);
    m_ui->roundNumberLabel->setPalette(textLabelPalette);




    m_objM = std::make_shared<Student::ObjectManager>();
    m_GEHandler->setObjectManager(m_objM);

    Course::WorldGenerator* worldG = &Course::WorldGenerator::getInstance();
    worldG->addConstructor<Course::Forest>(8);
    worldG->addConstructor<Course::Grassland>(15);
    worldG->addConstructor<Student::Swamp>(4);
    worldG->addConstructor<Student::Water>(3);
    worldG->addConstructor<Student::Cobblestone>(2);
    worldG->generateMap(2*m_size, m_size,1, m_objM, m_GEHandler);

    std::vector<std::shared_ptr<Course::TileBase>> tiles = m_objM->getTiles();
    for(auto brick : tiles)
    {
        m_scene->drawItem(brick);
    }

    std::shared_ptr<Student::Player> playerInTurn = m_GEHandler->getPlayerInTurn();
    this->updateLabels();

    QPalette backgroundPalette;
    backgroundPalette.setBrush(QPalette::Background, Qt::lightGray);
    this->setPalette(backgroundPalette);

}

MapWindow::~MapWindow()
{
    delete m_ui;
}

int MapWindow::getGridSize()
{
    return m_size;
}

int MapWindow::getRoundSize()
{
    return gameRounds;
}

void MapWindow::setGridSize(int size)
{
    m_size = size;
}

void MapWindow::setRounds(int amount)
{
    gameRounds = amount;
}

void MapWindow::getPlayer(std::vector<std::shared_ptr<Student::Player>> players)
{
    m_GEHandler->add_player(players);
}

void MapWindow::changeTurn()
{

    m_GEHandler->changeTurn();

    if(m_GEHandler->getRoundNumber() > gameRounds){
        EndDialog ending(this,m_GEHandler->getScores());
        connect(&ending, SIGNAL(finished(int)), this, SLOT(exitGame(int)));
        ending.exec();

    }

    this->updateLabels();

    clickedTileObj = nullptr;
    m_ui->tileInfoLabel->clear();
    m_scene->removeMarker();


}

void MapWindow::getId(unsigned int Id)
{
    clickedTileObj = m_objM->getTile(Id);
    if (clickedTileObj->getOwner()){
        qDebug() << "Owner: " << (clickedTileObj->getOwner()->getName()).c_str();
        qDebug() << "# of buildings: " << clickedTileObj->getBuildingCount();
    }
    this->updateTileInfo();
    m_scene->drawMarker(clickedTileObj->getCoordinate().asQpoint());
}

void MapWindow::actionBuild()
{
    if (!clickedTileObj){
        return;
    }

    if (clickedTileObj->getOwner() != m_GEHandler->getPlayerInTurn()){
        if(m_ui->buildingsComboBox->currentText().toStdString() != "HeadQuarters" &&
                m_ui->buildingsComboBox->currentText().toStdString() != "Outpost"){
            qDebug() << "Cannot build on unowned tile";
            return;
        }
    }

    std::shared_ptr<Course::BuildingBase> building;

    std::shared_ptr<Student::Player> tempPlayer = m_GEHandler->
            getPlayerInTurn();
    if(tempPlayer->funcHasBuiltHq() &&
            m_ui->buildingsComboBox->currentText().toStdString() ==
            "HeadQuarters"){
        qDebug() << "Cannot build more than one HQ!";
        return;
    }
    constructWantedBuilding(building);

    if(!building->canBePlacedOnTile(clickedTileObj)){
        qDebug() << "Cannot build the wanted building on this tile!";
        return;
    }

    if(!m_GEHandler->modifyResources(m_GEHandler->getPlayerInTurn(),
       m_GEHandler->resourcemapMakeNegative(building->BUILD_COST)))
    {
        qDebug() << "Too few resources to build";
        return;
    }

    if(!clickedTileObj->hasSpaceForBuildings(1))
    {
        qDebug() << "Building capacity is already maxed";
        return;
    }

    clickedTileObj->setOwner(m_GEHandler->getPlayerInTurn());
    clickedTileObj->addBuilding(building);
    m_GEHandler->getPlayerInTurn()->addObject(building);

    m_objM->addBuilding(building);
    building->onBuildAction();
    m_scene->drawItem(building);

    this->updateLabels();
    this->updateTileInfo();
    updateTileBorders();

    if(m_ui->buildingsComboBox->currentText().toStdString() == "HeadQuarters"){
        tempPlayer->changeHQBuildStatus();
    }

}

void MapWindow::actionRecruit()
{
    if (!clickedTileObj){
        return;
    }

    if (clickedTileObj->getOwner() != m_GEHandler->getPlayerInTurn()){
        return;
    }

    std::shared_ptr<Course::WorkerBase> recruit;
    constructWantedRecruit(recruit);

    if(!recruit->canBePlacedOnTile(clickedTileObj)){
        return;
    }
    if(!m_GEHandler->modifyResources(m_GEHandler->getPlayerInTurn(),
            m_GEHandler->resourcemapMakeNegative(recruit->RECRUITMENT_COST))){
        return;
    }
    clickedTileObj->addWorker(recruit);
    m_GEHandler->getPlayerInTurn()->addObject(recruit);
    m_objM->addWorker(recruit);


    this->updateLabels();
    this->updateTileInfo();

}

void MapWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    m_ui->graphicsView->setFixedWidth(2*(m_ui->graphicsView->height()));

    if(m_ui->graphicsView->scene()){
        m_ui->graphicsView->fitInView(m_ui->graphicsView->scene()->sceneRect(),Qt::KeepAspectRatio);
    }
}

void MapWindow::exitGame(int code)
{
    if(code){
        qApp->exit(1000);
    }
    else{
        qApp->exit(0);
    }
}



void MapWindow::constructWantedBuilding(
        std::shared_ptr<Course::BuildingBase>& building)
{
    std::string wantedBuilding = m_ui->buildingsComboBox->
                                currentText().toStdString();

    if(wantedBuilding == "HeadQuarters" )
    {
        building = std::make_shared<Student::StudentHeadQuarters>(m_GEHandler,
                                    m_objM, m_GEHandler->getPlayerInTurn());
    }
    else if(wantedBuilding == "Outpost")
    {
        building = std::make_shared<Student::StudentOutpost>(m_GEHandler,
                                    m_objM, m_GEHandler->getPlayerInTurn());
    }
    else if(wantedBuilding == "Farm")
    {
        building = std::make_shared<Student::StudentFarm>(m_GEHandler,
                                    m_objM, m_GEHandler->getPlayerInTurn());
    }
    else if(wantedBuilding == "Mine")
    {
        building = std::make_shared<Student::Mine>(m_GEHandler,
                                    m_objM, m_GEHandler->getPlayerInTurn());
    }
    else if(wantedBuilding == "Trawler")
    {
        building = std::make_shared<Student::Trawler>(m_GEHandler,
                                    m_objM, m_GEHandler->getPlayerInTurn());
    }
    else if(wantedBuilding == "Sawmill" )
    {
        building = std::make_shared<Student::Sawmill>(m_GEHandler,
                                    m_objM, m_GEHandler->getPlayerInTurn());
    }
}

void MapWindow::constructWantedRecruit(std::shared_ptr<Course::WorkerBase> &worker)
{
    std::string wantedRecruit = m_ui->recruitsComboBox->
            currentText().toStdString();
    if (wantedRecruit == "BasicWorker") {
            worker = std::make_shared<Course::BasicWorker>(m_GEHandler,
                                                           m_objM, m_GEHandler->getPlayerInTurn());
    }
    else if (wantedRecruit == "Miner") {
            worker = std::make_shared<Student::Miner>(m_GEHandler,
                                                           m_objM, m_GEHandler->getPlayerInTurn());
    }
    else if (wantedRecruit == "Fisher") {
            worker = std::make_shared<Student::Fisher>(m_GEHandler,
                                                           m_objM, m_GEHandler->getPlayerInTurn());
    }
    else if (wantedRecruit == "Farmer") {
            worker = std::make_shared<Student::Farmer>(m_GEHandler,
                                                           m_objM, m_GEHandler->getPlayerInTurn());
    }
    else if (wantedRecruit == "Lumberjack") {
            worker = std::make_shared<Student::Lumberjack>(m_GEHandler,
                                                           m_objM, m_GEHandler->getPlayerInTurn());
    }
    else if (wantedRecruit == "PeatWorker") {
            worker = std::make_shared<Student::PeatWorker>(m_GEHandler,
                                                           m_objM, m_GEHandler->getPlayerInTurn());
    }
}

void MapWindow::setGEHandler(std::shared_ptr<Student::GameEventHandler> nHandler)
{
    m_GEHandler = nHandler;
}

void MapWindow::setSize(int width, int height)
{
    m_scene->setSize(width, height);
}

void MapWindow::setScale(double scale)
{
    m_scene->setScale(scale);
}

void MapWindow::resize()
{
    m_scene->resize();
}

void MapWindow::updateItem(std::shared_ptr<Course::GameObject> obj)
{
    m_scene->updateItem(obj);
}

void MapWindow::updateLabels()
{
    auto playerInTurn = m_GEHandler->getPlayerInTurn();
    auto resources = playerInTurn->getResources();
    auto playerName = playerInTurn->getName();
    auto roundNumber = m_GEHandler->getRoundNumber();

    m_ui->turnNameLabel->setText
            (QString::fromStdString(playerName));

    m_ui->roundNumberLabel->setText
            (QString::fromStdString(std::to_string(roundNumber)));

    std::string resource_amount = "";

    resource_amount = std::to_string(resources[Course::BasicResource::MONEY]);
    m_ui->moneyAmountLabel->setText(QString::fromStdString(resource_amount));

    resource_amount = std::to_string(resources[Course::BasicResource::FOOD]);
    m_ui->foodAmountLabel->setText(QString::fromStdString(resource_amount));

    resource_amount = std::to_string(resources[Course::BasicResource::STONE]);
    m_ui->stoneAmountLabel->setText(QString::fromStdString(resource_amount));

    resource_amount = std::to_string(resources[Course::BasicResource::WOOD]);
    m_ui->woodAmountLabel->setText(QString::fromStdString(resource_amount));
}

void MapWindow::updateTileInfo()
{
    std::shared_ptr<Course::TileBase> tile = clickedTileObj;

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

    m_ui->tileInfoLabel->setText("(" + x + "," + y + ") " + type + "\n"
                                 + "Owner: " + owner + "\n"
                                 + "Buildings:"+ "\n");
    for (auto building : buildings){
        m_ui->tileInfoLabel->setText(m_ui->tileInfoLabel->text() + "-- " + building + "\n");
    }
    m_ui->tileInfoLabel->setText(m_ui->tileInfoLabel->text() + "Workers:"+ "\n");
    for (auto worker : workers){
        m_ui->tileInfoLabel->setText(m_ui->tileInfoLabel->text() + "-- " + worker + "\n");
    }
    m_ui->tileInfoLabel->setWordWrap(true);
    m_ui->tileInfoLabel->setAlignment(Qt::AlignTop);

}

void MapWindow::updateTileBorders()
{
    for (auto tile : m_objM->getTiles()){
        if (auto owner = tile->getOwner()){
            auto player = std::dynamic_pointer_cast<Student::Player>(owner);
            m_scene->drawBorder(player->getColor(),tile->getCoordinate().asQpoint());
        }
    }
}


void MapWindow::removeItem(std::shared_ptr<Course::GameObject> obj)
{
    m_scene->removeItem(obj);
}

void MapWindow::drawItem( std::shared_ptr<Course::GameObject> obj)
{
    m_scene->drawItem(obj);
}

