
#include "UI/mapwindow.hh"
#include "ui_mapwindow.h"
#include "iostream"

#include <math.h>


MapWindow::MapWindow(QWidget *parent,
                     std::shared_ptr<Student::GameEventHandler> handler):
    QMainWindow(parent),
    m_ui(new Ui::MapWindow),
    m_GEHandler(handler),
    m_scene(new Student::GameScene(this))
{
    m_ui->setupUi(this);
    m_GEHandler = std::make_shared<Student::GameEventHandler>(Student::GameEventHandler());

    Dialog dialogwindow;
    connect(&dialogwindow, SIGNAL(sendValue(int)), this,
            SLOT(setGridSize(int)));
    connect(&dialogwindow, SIGNAL(sendPlayer(std::vector<std::shared_ptr<Student::Player>>)),
                           this, SLOT(getPlayer(std::vector<std::shared_ptr<Student::Player>>)));
    connect(m_ui->endTurnPushButton, SIGNAL(clicked(bool)), this, SLOT(changeTurn()));
    connect(m_ui->buildPushButton, SIGNAL(clicked(bool)), this, SLOT(actionBuild()));
    

    dialogwindow.exec();

    QStringList buildings = {"HeadQuarters", "Outpost", "Farm", "Mine", "Trawler", "Sawmill"};
    m_ui->buildingsComboBox->addItems(buildings);

    Student::GameScene* sgs_rawptr = m_scene.get();
    m_ui->graphicsView->setScene(dynamic_cast<QGraphicsScene*>(sgs_rawptr));
    this->setSize(2*m_size, m_size);
    this->setScale((m_ui->graphicsView->height())/m_size-1);

    connect(sgs_rawptr, SIGNAL(sendID(unsigned int)), this, SLOT(getId(unsigned int)));

    m_objM = std::make_shared<Student::ObjectManager>();
    m_GEHandler->setObjectManager(m_objM);

    Course::WorldGenerator* worldG = &Course::WorldGenerator::getInstance();
    worldG->addConstructor<Course::Forest>(1);
    worldG->addConstructor<Course::Grassland>(1);
    worldG->addConstructor<Student::Swamp>(1);
    worldG->addConstructor<Student::Water>(1);
    worldG->addConstructor<Student::Cobblestone>(1);

    worldG->generateMap(2*m_size, m_size,1, m_objM, m_GEHandler);

    std::vector<std::shared_ptr<Course::TileBase>> tiles = m_objM->getTiles();
    for(auto brick : tiles)
    {
        sgs_rawptr->drawItem(brick);
    }

    std::shared_ptr<Student::Player> playerInTurn = m_GEHandler->getPlayerInTurn();
    this->updateLabels();

    QMediaPlayer *mediaPlayer = new QMediaPlayer();
    mediaPlayer->setMedia(QUrl("qrc:/sounds/flute_salad.mp3"));
    mediaPlayer->play();
}

MapWindow::~MapWindow()
{
    delete m_ui;
}

int MapWindow::getGridSize(){
    return m_size;
}

void MapWindow::setGridSize(int size){
    m_size = size;
}

void MapWindow::getPlayer(std::vector<std::shared_ptr<Student::Player>> players)
{
    m_GEHandler->add_player(players);
}

void MapWindow::changeTurn()
{
    m_GEHandler->changeTurn();

    std::shared_ptr<Student::Player> playerInTurn = m_GEHandler->getPlayerInTurn();
    this->updateLabels();

    clickedTileObj = nullptr;
    m_ui->tileInfoLabel->clear();
}

void MapWindow::getId(unsigned int Id)
{
    clickedTileObj = m_objM->getTile(Id);
    if (clickedTileObj->getOwner()){
        qDebug() << "Owner: " << (clickedTileObj->getOwner()->getName()).c_str();
        qDebug() << "# of buildings: " << clickedTileObj->getBuildingCount();
    }
    this->updateTileInfo();
}

void MapWindow::actionBuild()
{
    if (!clickedTileObj ||
        (clickedTileObj->getOwner()
            && clickedTileObj->getOwner() != m_GEHandler->getPlayerInTurn())){
        return;
    }

    std::shared_ptr<Course::BuildingBase> building;
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
        clickedTileObj->setOwner(m_GEHandler->getPlayerInTurn());
        clickedTileObj->addBuilding(building);

        m_objM->addBuilding(building);
        building->onBuildAction();
        m_scene->drawItem(building);

        this->updateLabels();
        this->updateTileInfo();

}

void MapWindow::constructWantedBuilding(
        std::shared_ptr<Course::BuildingBase>& building)
{
    std::string wantedBuilding = m_ui->buildingsComboBox->
                                currentText().toStdString();

    if(wantedBuilding == "HeadQuarters")
    {
        building = std::make_shared<Course::HeadQuarters>(m_GEHandler,
                                    m_objM, m_GEHandler->getPlayerInTurn());
    }
    else if(wantedBuilding == "Outpost")
    {
        building = std::make_shared<Course::Outpost>(m_GEHandler,
                                    m_objM, m_GEHandler->getPlayerInTurn());
    }
    else if(wantedBuilding == "Farm")
    {
        building = std::make_shared<Course::Farm>(m_GEHandler,
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

void MapWindow::setGEHandler(std::shared_ptr<Student::GameEventHandler> nHandler)
{
    m_GEHandler = nHandler;
}

void MapWindow::setSize(int width, int height)
{
    m_scene->setSize(width, height);
}

void MapWindow::setScale(int scale)
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
    m_ui->tileInfoLabel->setText("(" + x + "," + y + ") " + type + "\n"
                                 + "Owner: " + owner + "\n"
                                 + "Buildings:"+ "\n");
    for (auto building : buildings){
        m_ui->tileInfoLabel->setText(m_ui->tileInfoLabel->text() + building + "\n");
    }
    m_ui->tileInfoLabel->setWordWrap(true);
    m_ui->tileInfoLabel->setAlignment(Qt::AlignTop);

}


void MapWindow::removeItem(std::shared_ptr<Course::GameObject> obj)
{
    m_scene->removeItem(obj);
}

void MapWindow::drawItem( std::shared_ptr<Course::GameObject> obj)
{
    m_scene->drawItem(obj);
}

