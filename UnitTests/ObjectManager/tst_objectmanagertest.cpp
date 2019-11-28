#include <core/objectmanager.h>
#include <core/gameeventhandler.h>
#include <QString>
#include <QtTest>
#include <workers/basicworker.h>






class ObjectManagerTest : public QObject
{
    Q_OBJECT

public:
    ObjectManagerTest();

private Q_SLOTS:
    void testAddTiles();
    void testGetTile();
    void testGetTiles();
    void testAddBuilding();
    void testAddWorker();
    void testGetBuilding();
    void testGetBuildings();

private:
    std::vector<std::shared_ptr<Course::TileBase>> createTestTiles(
            std::shared_ptr<Student::GameEventHandler> handler,
            std::shared_ptr<Student::ObjectManager> manager,
            int width,
            int height);

};

std::vector<std::shared_ptr<Course::TileBase>> ObjectManagerTest::createTestTiles(
        std::shared_ptr<Student::GameEventHandler> handler,
        std::shared_ptr<Student::ObjectManager> manager,
        int width,
        int height)
{
    std::vector<std::shared_ptr<Course::TileBase>> tiles;
    for (int x = 0; x < width; x++){
        for (int y = 0; y < height; y++){
            tiles.push_back(std::make_shared<Course::TileBase>
                        (Course::TileBase(Course::Coordinate(x,y),handler,manager)));
        }
    }
    return tiles;
}


ObjectManagerTest::ObjectManagerTest()
{
}

void ObjectManagerTest::testAddTiles()
{
    std::shared_ptr<Student::GameEventHandler> handler = std::make_shared
            <Student::GameEventHandler>(Student::GameEventHandler());

    std::shared_ptr<Student::ObjectManager> manager = std::make_shared
            <Student::ObjectManager>(Student::ObjectManager());

    std::vector<std::shared_ptr<Course::TileBase>> tiles =
            createTestTiles(handler,manager,20,10);

    manager->addTiles(tiles);
    QCOMPARE(manager->getTiles(), tiles);
}

void ObjectManagerTest::testGetTile()
{
    std::shared_ptr<Student::GameEventHandler> handler = std::make_shared
            <Student::GameEventHandler>(Student::GameEventHandler());

    std::shared_ptr<Student::ObjectManager> manager = std::make_shared
            <Student::ObjectManager>(Student::ObjectManager());

    std::vector<std::shared_ptr<Course::TileBase>> tiles =
            createTestTiles(handler,manager,20,10);

    manager->addTiles(tiles);

    // Get tile with coordinate
    for (auto tile : tiles){
        QCOMPARE(manager->getTile(tile->getCoordinate()),tile);
    }

    // Get tile with coordinate
    for (auto tile : tiles){
        QCOMPARE(manager->getTile(tile->ID),tile);
    }


}

void ObjectManagerTest::testGetTiles()
{
    std::shared_ptr<Student::GameEventHandler> handler = std::make_shared
            <Student::GameEventHandler>(Student::GameEventHandler());

    std::shared_ptr<Student::ObjectManager> manager = std::make_shared
            <Student::ObjectManager>(Student::ObjectManager());

    std::vector<std::shared_ptr<Course::TileBase>> tiles =
            createTestTiles(handler,manager,20,10);

    manager->addTiles(tiles);

    std::vector<std::shared_ptr<Course::TileBase>> selectedTiles;
    std::vector<Course::Coordinate> selectedCoordinates;

    for (int i = 5; i < 12; i++){
        selectedTiles.push_back(tiles[i]);
        selectedCoordinates.push_back(tiles[i]->getCoordinate());
    }
    QCOMPARE(manager->getTiles(selectedCoordinates),selectedTiles);

}

void ObjectManagerTest::testAddBuilding()
{
    std::shared_ptr<Student::GameEventHandler> handler = std::make_shared
            <Student::GameEventHandler>(Student::GameEventHandler());

    std::shared_ptr<Student::ObjectManager> manager = std::make_shared
            <Student::ObjectManager>(Student::ObjectManager());

    std::shared_ptr<Student::Player> player = std::make_shared
            <Student::Player>(Student::Player("Erkki",{},Qt::red));

    std::shared_ptr<Course::BuildingBase> building1 =
            std::make_shared<Course::BuildingBase>(handler,manager,player);

    std::shared_ptr<Course::BuildingBase> building2 =
            std::make_shared<Course::BuildingBase>(handler,manager,player);

    manager->addBuilding(building1);
    manager->addBuilding(building2);

    QCOMPARE(building1, manager->getBuilding(building1->ID));
    QCOMPARE(building2, manager->getBuilding(building2->ID));


}

void ObjectManagerTest::testAddWorker()
{
    std::shared_ptr<Student::GameEventHandler> handler = std::make_shared
            <Student::GameEventHandler>(Student::GameEventHandler());

    std::shared_ptr<Student::ObjectManager> manager = std::make_shared
            <Student::ObjectManager>(Student::ObjectManager());

    std::shared_ptr<Student::Player> player = std::make_shared
            <Student::Player>(Student::Player("Erkki",{},Qt::red));

    std::shared_ptr<Course::WorkerBase> worker1 =
            std::make_shared<Course::BasicWorker>(handler,manager,player);

    std::shared_ptr<Course::WorkerBase> worker2 =
            std::make_shared<Course::BasicWorker>(handler,manager,player);

    manager->addWorker(worker1);
    manager->addWorker(worker2);

    QCOMPARE(worker1, manager->getWorker(worker1->ID));
    QCOMPARE(worker2, manager->getWorker(worker2->ID));
}

void ObjectManagerTest::testGetBuilding()
{
    std::shared_ptr<Student::GameEventHandler> handler = std::make_shared
            <Student::GameEventHandler>(Student::GameEventHandler());

    std::shared_ptr<Student::ObjectManager> manager = std::make_shared
            <Student::ObjectManager>(Student::ObjectManager());

    std::shared_ptr<Student::Player> player = std::make_shared
            <Student::Player>(Student::Player("Erkki",{},Qt::red));

    std::shared_ptr<Course::BuildingBase> building1 =
            std::make_shared<Course::BuildingBase>(handler,manager,player);

    std::shared_ptr<Course::BuildingBase> building2 =
            std::make_shared<Course::BuildingBase>(handler,manager,player);

    manager->addBuilding(building1);
    manager->addBuilding(building2);

    QCOMPARE(building1, manager->getBuilding(building1->ID));
    QCOMPARE(building2, manager->getBuilding(building2->ID));
}

void ObjectManagerTest::testGetBuildings()
{
    std::shared_ptr<Student::GameEventHandler> handler = std::make_shared
            <Student::GameEventHandler>(Student::GameEventHandler());

    std::shared_ptr<Student::ObjectManager> manager = std::make_shared
            <Student::ObjectManager>(Student::ObjectManager());

    std::shared_ptr<Student::Player> player = std::make_shared
            <Student::Player>(Student::Player("Erkki",{},Qt::red));

    std::shared_ptr<Course::BuildingBase> building1 =
            std::make_shared<Course::BuildingBase>(handler,manager,player);

    std::shared_ptr<Course::BuildingBase> building2 =
            std::make_shared<Course::BuildingBase>(handler,manager,player);

    manager->addBuilding(building1);
    manager->addBuilding(building2);

    QCOMPARE(building1, manager->getBuildings()[0]);
    QCOMPARE(building2, manager->getBuildings()[1]);
}












QTEST_APPLESS_MAIN(ObjectManagerTest)

#include "tst_objectmanagertest.moc"
