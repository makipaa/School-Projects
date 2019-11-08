#include "UI/mapwindow.hh"
#include "ui_mapwindow.h"

#include <math.h>



MapWindow::MapWindow(QWidget *parent,
                     std::shared_ptr<Course::iGameEventHandler> handler):
    QMainWindow(parent),
    m_ui(new Ui::MapWindow),
    m_GEHandler(handler),
    m_scene(new Student::GameScene(this))
{
    m_ui->setupUi(this);

    Student::GameScene* sgs_rawptr = m_scene.get();

    m_ui->graphicsView->setScene(dynamic_cast<QGraphicsScene*>(sgs_rawptr));
    
    Dialog dialogwindow;
    connect(&dialogwindow, SIGNAL(sendValue(int, int)), this, SLOT(setSize(int,int)));
    dialogwindow.exec();

    std::shared_ptr<Student::ObjectManager> objM = std::make_shared<Student::ObjectManager>();

    Course::WorldGenerator* worldG = &Course::WorldGenerator::getInstance();
    worldG->addConstructor<Course::Forest>(1);
    worldG->addConstructor<Course::Grassland>(1);
    worldG->generateMap(10,10,1,objM, m_GEHandler);

    std::vector<std::shared_ptr<Course::TileBase>> tiilet = objM->getTiles();
    for(auto brikki : tiilet)
    {
        sgs_rawptr->drawItem(brikki);
    }


    
}

MapWindow::~MapWindow()
{
    delete m_ui;
}

void MapWindow::setGEHandler(
        std::shared_ptr<Course::iGameEventHandler> nHandler)
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

void MapWindow::removeItem(std::shared_ptr<Course::GameObject> obj)
{
    m_scene->removeItem(obj);
}

void MapWindow::drawItem( std::shared_ptr<Course::GameObject> obj)
{
    m_scene->drawItem(obj);
}


