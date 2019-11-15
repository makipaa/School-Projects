#ifndef MAPWINDOW_HH
#define MAPWINDOW_HH

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

#include <map>

#include "interfaces/igameeventhandler.h"
#include "Graphics/gamescene.h"
#include "Graphics/mapitem.h"
#include "objectmanager.h"
#include "gameeventhandler.h"
#include "UI/dialog.h"
#include "tiles/forest.h"
#include "tiles/grassland.h"
#include "Student_tiles/swamp.h"
#include "Student_tiles/water.h"
#include "Student_tiles/cobblestone.h"
#include "core/basicresources.h"


namespace Ui {
class MapWindow;
}



class MapWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MapWindow(QWidget *parent = 0,
                       std::shared_ptr<Student::GameEventHandler> GEHandler = {}
                       );
    ~MapWindow();

    void setGEHandler(std::shared_ptr<Student::GameEventHandler> nHandler);

    int getGridSize();
    void setSize(int width, int height);
    void setScale(int scale);
    void resize();

    void drawItem( std::shared_ptr<Course::GameObject> obj);
    void removeItem( std::shared_ptr<Course::GameObject> obj);
    void updateItem( std::shared_ptr<Course::GameObject> obj);

    void updateLabels(Course::ResourceMap resources, std::string playerName, int roundNumber);


public slots:
    void setGridSize(int size);
    void getPlayer(std::vector<std::shared_ptr<Student::Player>> players);
    void changeTurn();

private:
    Ui::MapWindow* m_ui;
    std::shared_ptr<Student::GameEventHandler> m_GEHandler = nullptr;
    std::shared_ptr<Student::ObjectManager> m_objM = nullptr;
    std::shared_ptr<Student::GameScene> m_scene = nullptr;
    int m_size = 0;

};


#endif // MapWINDOW_HH

