#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QTimer>
#include <math.h>
#include <map>
#include <QPixmap>

#include "interfaces/igameeventhandler.h"
#include "Graphics/gamescene.h"
#include "Graphics/mapitem.h"
#include "core/objectmanager.h"
#include "core/gameeventhandler.h"
#include "UI/dialog.h"
#include "enddialog.h"
#include "core/player.h"
#include "tiles/forest.h"
#include "tiles/grassland.h"
#include "Student_tiles/swamp.h"
#include "Student_tiles/water.h"
#include "Student_tiles/cobblestone.h"
#include "core/basicresources.h"
#include "Buildings/studentHeadQuarters.h"
#include "Buildings/studentOutpost.h"
#include "Buildings/studentfarm.h"
#include "Buildings/mine.h"
#include "Buildings/trawler.h"
#include "Buildings/sawmill.h"
#include "workers/basicworker.h"
#include "Workers/fisher.h"
#include "Workers/miner.h"
#include "Workers/farmer.h"
#include "Workers/luberjack.h"
#include "Workers/peatworker.h"
#include "core/resourcemaps.h"
#include "exceptions/illegalaction.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0,
                       std::shared_ptr<Student::GameEventHandler>
                       GEHandler = {});
    ~MainWindow();

    int getGridSize();

    int getRoundSize();

    void setSize(int width, int height);

    void setScale(double scale);

    void resize();

    void updateLabels();

    void updateTileInfo();

    void updateTileBorders();

    void updateGameInfo(std::string infoText);

    void setGEHandler(std::shared_ptr<Student::GameEventHandler> nHandler);

public slots:
    void setGridSize(int size);

    void setRounds(int amount);

    void getPlayer(std::vector<std::shared_ptr<Student::Player>> players);

    void changeTurn();

    void getId(unsigned int Id);

    void actionBuild();

    void actionRecruit();

    void updateBuildingInfo(QString buildingName);

    void updateWorkerInfo(QString workerName);

    void timeOut();

    void exitGame(int code);

    void resizeEvent(QResizeEvent *event);

private:
    QTimer* timer_ = nullptr;
    Ui::MainWindow* m_ui_;

    std::shared_ptr<Student::GameEventHandler> m_GEHandler_ = nullptr;
    std::shared_ptr<Student::ObjectManager> m_objM_ = nullptr;
    std::shared_ptr<Student::GameScene> m_scene_ = nullptr;
    std::shared_ptr<Course::TileBase> clickedTileObj_ = nullptr;

    int m_size_ = 0;
    int gameRounds_ = 0;

    void constructWantedBuilding(
         std::shared_ptr<Course::BuildingBase> &building);
    void constructWantedRecruit(
         std::shared_ptr<Course::WorkerBase> &worker);
};

#endif // MAINWINDOW_HH

