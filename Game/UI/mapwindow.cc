
#include "UI/mapwindow.hh"
#include "ui_mapwindow.h"

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

    dialogwindow.exec();

    Student::GameScene* sgs_rawptr = m_scene.get();
    m_ui->graphicsView->setScene(dynamic_cast<QGraphicsScene*>(sgs_rawptr));
    this->setSize(2*m_size, m_size);
    this->setScale((m_ui->graphicsView->height())/m_size-1);


    m_objM = std::make_shared<Student::ObjectManager>();
    m_GEHandler->setObjectManager(m_objM);

    Course::WorldGenerator* worldG = &Course::WorldGenerator::getInstance();
    worldG->addConstructor<Course::Forest>(1);
    worldG->addConstructor<Course::Grassland>(1);
    worldG->addConstructor<Student::Swamp>(1);
    worldG->addConstructor<Student::Water>(1);
    worldG->addConstructor<Student::Cobblestone>(1);

    worldG->generateMap(2*m_size, m_size,1, m_objM, m_GEHandler);

    std::vector<std::shared_ptr<Course::TileBase>> tiilet = m_objM->getTiles();
    for(auto brikki : tiilet)
    {
        sgs_rawptr->drawItem(brikki);
    }

    std::shared_ptr<Student::Player> playerInTurn = m_GEHandler->getPlayerInTurn();
    this->updateLabels(playerInTurn->getResources(),playerInTurn->getName(),
                       m_GEHandler->getRoundNumber());
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
    this->updateLabels(playerInTurn->getResources(),playerInTurn->getName(),
                       m_GEHandler->getRoundNumber());
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

void MapWindow::updateLabels(Course::ResourceMap resources,
                             std::string playerName, int roundNumber)
{
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

void MapWindow::removeItem(std::shared_ptr<Course::GameObject> obj)
{
    m_scene->removeItem(obj);
}

void MapWindow::drawItem( std::shared_ptr<Course::GameObject> obj)
{
    m_scene->drawItem(obj);
}


