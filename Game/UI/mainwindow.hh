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
#include "Workers/lumberjack.h"
#include "Workers/peatworker.h"
#include "core/resourcemaps.h"
#include "exceptions/illegalaction.h"


namespace Ui {
class MainWindow;
}
/**
 * @brief This class is for the interface in the game which interacts \n
 * with the player.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the class.
     * @param parent Points to the parent object per Qt's parent-child-system.
     * @param GEHandler which points to the GameEventHandler.
     */
    explicit MainWindow(QWidget *parent = 0,
                       std::shared_ptr<Student::GameEventHandler>
                       GEHandler = {});
    /**
     * @brief Parameterless destructor.
     */
    ~MainWindow();

    /**
     * @return Size of the grid.
     * @post Exception Guarantee: No throw.
     */
    int getGridSize();

    /**
     * @return Amount of rounds.
     * @post Exception Guarantee: No throw.
     */
    int getRoundSize();

    /**
     * @brief Sets the size for the scene.
     * @param width
     * @param height
     */
    void setSize(int width, int height);

    /**
     * @brief Sets scale for the scene.
     * @param scale
     */
    void setScale(double scale);

    /**
     * @brief Resizes the scene.
     */
    void resize();

    /**
     * @brief Updates labels for players resources.
     */
    void updateLabels();

    /**
     * @brief Updates tiles buildings workers etc. for the user to see \n
     * in the interface.
     * @post Exception Guarantee: No guarantee.
     */
    void updateTileInfo();

    /**
     * @brief If a player owns certain tiles, it updates and calls a \n
     * function to draw them.
     * @post Exception Guarantee: No guarantee.
     */
    void updateTileBorders();

    /**
     * @brief Updates text to the interface for example "Too few resources \n
     * to build"
     * @param infoText
     */
    void updateGameInfo(std::string infoText);

    /**
     * @brief Sets the variable m_GEhandler_ to nHandler.
     * @param nHandler
     * @post Exception Guarantee: No throw.
     */
    void setGEHandler(std::shared_ptr<Student::GameEventHandler> nHandler);

public slots:
    /**
     * @brief Sets the map size.
     * @param size
     * @post Exception Guarantee: No throw.
     */
    void setGridSize(int size);

    /**
     * @brief Set game rounds.
     * @param amount
     */
    void setRounds(int amount);

    /**
     * @brief Gives players to the gameEventHandler.
     * @param players
     * @post Exception Guarantee: No throw.
     */
    void getPlayer(std::vector<std::shared_ptr<Student::Player>> players);

    /**
     * @brief Changes turn.
     * @post Exception Guarantee: No guarantee.
     */
    void changeTurn();

    /**
     * @brief Shows info of a tile corresponding to the ID.
     * @param Id
     */
    void getId(unsigned int Id);

    /**
     * @brief Performs building action when the build button is pressed.
     * @post Exception Guarantee: No guarantee.
     */
    void actionBuild();

    /**
     * @brief Performs recruiting action when the recruit button is pressed.
     * @post Exception Guarantee: No guarantee.
     */
    void actionRecruit();

    /**
     * @brief Shows buildings picture and its build cost in the interface.
     * @param buildingName
     */
    void updateBuildingInfo(QString buildingName);

    /**
     * @brief Shows workers build cost in the interface.
     * @param workerName
     */
    void updateWorkerInfo(QString workerName);

    /**
     * @brief Erases the error message.
     * @post Exception Guarantee: No throw.
     */
    void timeOut();

    /**
     * @brief Exits game or starts a new one depending on the code.
     * @param code
     */
    void exitGame(int code);

    /**
     * @brief Scales the map if the screen size changes.
     * @param event
     */
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

    /**
     * @brief Constructs the wanted building to the tile.
     * @param building
     */
    void constructWantedBuilding(
         std::shared_ptr<Course::BuildingBase> &building);

    /**
     * @brief Constructs the wanted worker to the tile.
     * @param worker
     */
    void constructWantedRecruit(
         std::shared_ptr<Course::WorkerBase> &worker);
};

#endif // MAINWINDOW_HH

