#include <QString>
#include <QtTest>
#include <core/gameeventhandler.h>
#include <tiles/grassland.h>

class GameEventHandlerTest : public QObject
{
    Q_OBJECT

public:
    GameEventHandlerTest();

private Q_SLOTS:

    /*!
     * \brief testModifyResource Tests GameEventHandlers modifyResource -method
     *        with adding, subtracting and subtracting more than player has
     */
    void testModifyResource();

    /*!
     * \brief testModifyResources Tests GameEventHandlers modifyResources
     *        -method with adding, subtracting and subtracting more than
     *        player has
     */
    void testModifyResources();

    /*!
     * \brief testAdd_players Tests GameEventHandlers addPlayers -method
     */
    void testAddPlayers();

    /*!
     * \brief testNewRound Tests GameEventHandlers newRound -method. Checks
     *        if the round number changes correctly and resorces are generated
     *        to players
     */
    void testNewRound();

    /*!
     * \brief testChangeTurn Tests GameEventHandlers changeTurn -method by
     *        checking if the player player in turn is changed and newRound
     *        is called after the round's final turn
     */
    void testChangeTurn();

    /*!
     * \brief testGetPlayerInTurn Tests GameEventHandlers getPlayerInTurn
     *        -method
     */
    void testGetPlayerInTurn();

    /*!
     * \brief testGetRoundNumber Tests GameEventHandlers getRoundNumber
     *         -method
     */
    void testGetRoundNumber();

    /*!
     * \brief testResourcemapMakeNegative Tests GameEventHandlers
     *        ResourcemapMakeNegative -method with positive and
     *        negative value maps
     *
     */
    void testResourcemapMakeNegative();

    /*!
     * \brief testGetScores Tests GameEventHandlers getScores -method by giving
     *        test players resources and counting the score based on them
     */
    void testGetScores();

private:

    /*!
     * \brief createTestTiles Creates tiles used by testfunctions
     * \param handle
     * \param manager
     * \param width Amount of tiles in a row
     * \param height Amount of tiles in a column
     * \return Returns vector with shared pointers to the created test tiles
     */
    std::vector<std::shared_ptr<Course::TileBase>> createTestTiles(
            std::shared_ptr<Student::GameEventHandler> handler,
            std::shared_ptr<Student::ObjectManager> manager,
            int width,
            int height);

};

std::vector<std::shared_ptr<Course::TileBase>> GameEventHandlerTest::createTestTiles(
        std::shared_ptr<Student::GameEventHandler> handler,
        std::shared_ptr<Student::ObjectManager> manager,
        int width,
        int height)
{
    std::vector<std::shared_ptr<Course::TileBase>> tiles;
    for (int x = 0; x < width; x++){
        for (int y = 0; y < height; y++){
            tiles.push_back(std::make_shared<Course::TileBase>
                        (Course::Grassland(Course::Coordinate(x,y),handler,manager)));
        }
    }
    return tiles;
}

GameEventHandlerTest::GameEventHandlerTest()
{
}

void GameEventHandlerTest::testModifyResource()
{

    std::shared_ptr<Student::GameEventHandler> handler = std::make_shared
            <Student::GameEventHandler>(Student::GameEventHandler());

    std::shared_ptr<Student::ObjectManager> manager = std::make_shared
            <Student::ObjectManager>(Student::ObjectManager());

    std::shared_ptr<Student::Player> player = std::make_shared
            <Student::Player>(Student::Player("Erkki",{},Qt::red));

    handler->addPlayers({player});

    // Test adding resources
    int amount (395);
    int currentAmount = player->getResources()[Course::MONEY];
    int result = currentAmount + amount;
    handler->modifyResource(player,Course::MONEY,amount);
    QCOMPARE(player->getResources()[Course::MONEY],result);

    // Test subtracting more resources than available
    currentAmount = player->getResources()[Course::MONEY];
    amount = -currentAmount -1;
    bool negativeResult = handler->modifyResource(player,Course::MONEY,amount);
    QCOMPARE(negativeResult,false);

    // Test subtracting resources
    amount = -50;
    currentAmount = player->getResources()[Course::MONEY];
    result = currentAmount + amount;
    handler->modifyResource(player, Course::MONEY, amount);
    QCOMPARE(player->getResources()[Course::MONEY],result);
}

void GameEventHandlerTest::testModifyResources()
{
    std::shared_ptr<Student::GameEventHandler> handler = std::make_shared
            <Student::GameEventHandler>(Student::GameEventHandler());

    std::shared_ptr<Student::ObjectManager> manager = std::make_shared
            <Student::ObjectManager>(Student::ObjectManager());

    std::shared_ptr<Student::Player> player = std::make_shared
            <Student::Player>(Student::Player("Erkki",{},Qt::red));

    handler->addPlayers({player});

    Course::ResourceMap resources = {
                                 {Course::BasicResource::MONEY, 231},
                                 {Course::BasicResource::FOOD, 451},
                                 {Course::BasicResource::WOOD, 234},
                                 {Course::BasicResource::STONE, 138}};

    Course::ResourceMap playerResources = player->getResources();
    Course::ResourceMap resultResources = Course::mergeResourceMaps
            (resources,playerResources);

    handler->modifyResources(player,resources);

    QCOMPARE(player->getResources(),resultResources);

    resources = {{Course::BasicResource::MONEY, -231},
                 {Course::BasicResource::FOOD, -451},
                 {Course::BasicResource::WOOD, -234},
                 {Course::BasicResource::STONE, -138}};

    playerResources = player->getResources();
    resultResources = Course::mergeResourceMaps(resources,playerResources);

    handler->modifyResources(player,resources);

    QCOMPARE(player->getResources(),resultResources);

    resources = {{Course::BasicResource::MONEY, -231},
                 {Course::BasicResource::FOOD, -451000},
                 {Course::BasicResource::WOOD, -234},
                 {Course::BasicResource::STONE, -138}};

    playerResources = player->getResources();
    resultResources = Course::mergeResourceMaps(resources,playerResources);

    bool negativeResult = handler->modifyResources(player,resources);

    QCOMPARE(negativeResult,false);

}

void GameEventHandlerTest::testAddPlayers()
{
    std::shared_ptr<Student::GameEventHandler> handler = std::make_shared
            <Student::GameEventHandler>(Student::GameEventHandler());

    std::shared_ptr<Student::ObjectManager> manager = std::make_shared
            <Student::ObjectManager>(Student::ObjectManager());

    std::shared_ptr<Student::Player> player1 = std::make_shared
            <Student::Player>(Student::Player("Erkki",{},Qt::red));
    std::shared_ptr<Student::Player> player2 = std::make_shared
            <Student::Player>(Student::Player("Jorma",{},Qt::red));
    std::shared_ptr<Student::Player> player3 = std::make_shared
            <Student::Player>(Student::Player("Mauri",{},Qt::red));

    std::vector<std::shared_ptr<Student::Player>> players
            ({player1, player2, player3});
    handler->addPlayers(players);
    QCOMPARE(handler->getPlayers(), players);

}

void GameEventHandlerTest::testNewRound()
{
    std::shared_ptr<Student::GameEventHandler> handler = std::make_shared
            <Student::GameEventHandler>(Student::GameEventHandler());

    std::shared_ptr<Student::ObjectManager> manager = std::make_shared
            <Student::ObjectManager>(Student::ObjectManager());

    std::shared_ptr<Student::Player> player1 = std::make_shared
            <Student::Player>(Student::Player("Erkki",{},Qt::red));

    handler->setObjectManager(manager);
    handler->addPlayers({player1});
    std::vector<std::shared_ptr<Course::TileBase>> tiles =
            createTestTiles(handler,manager,4,4);

    manager->addTiles(tiles);
    for (auto tile : tiles){
        tile->setOwner(player1);
    }
    Course::ResourceMap resultMap(player1->getResources());
    for (auto tile : tiles){
        resultMap = Course::mergeResourceMaps
                (resultMap, tile->BASE_PRODUCTION);
    }
    int resultRoundNumber = handler->getRoundNumber() + 1;

    handler->newRound();

    for (auto resource : player1->getResources()){
        QCOMPARE(resource.second, resultMap[resource.first]);
    }

    QCOMPARE(handler->getRoundNumber(), resultRoundNumber);

}

void GameEventHandlerTest::testChangeTurn()
{
    std::shared_ptr<Student::GameEventHandler> handler = std::make_shared
            <Student::GameEventHandler>(Student::GameEventHandler());

    std::shared_ptr<Student::ObjectManager> manager = std::make_shared
            <Student::ObjectManager>(Student::ObjectManager());

    std::shared_ptr<Student::Player> player1 = std::make_shared
            <Student::Player>(Student::Player("Erkki",{},Qt::red));
    std::shared_ptr<Student::Player> player2 = std::make_shared
            <Student::Player>(Student::Player("Jorma",{},Qt::red));
    std::shared_ptr<Student::Player> player3 = std::make_shared
            <Student::Player>(Student::Player("Mauri",{},Qt::red));

    handler->addPlayers({player1, player2, player3});
    handler->setObjectManager(manager);

    handler->changeTurn();
    QCOMPARE(handler->getPlayerInTurn(), player2);

    handler->changeTurn();
    QCOMPARE(handler->getPlayerInTurn(), player3);

    int roundNumber = handler->getRoundNumber();
    handler->changeTurn();
    QCOMPARE(handler->getRoundNumber(), roundNumber + 1);
    QCOMPARE(handler->getPlayerInTurn(), player1);
}

void GameEventHandlerTest::testGetPlayerInTurn(){

    std::shared_ptr<Student::GameEventHandler> handler = std::make_shared
            <Student::GameEventHandler>(Student::GameEventHandler());

    std::shared_ptr<Student::Player> player1 = std::make_shared
            <Student::Player>(Student::Player("Erkki",{},Qt::red));
    std::shared_ptr<Student::Player> player2 = std::make_shared
            <Student::Player>(Student::Player("Jorma",{},Qt::red));
    std::shared_ptr<Student::Player> player3 = std::make_shared
            <Student::Player>(Student::Player("Mauri",{},Qt::red));

    handler->addPlayers({player1, player2, player3});

    // First added player should be in turn
    QCOMPARE(handler->getPlayerInTurn(), player1);

    // Adding players clears the current players
    handler->addPlayers({player2, player3});
    QCOMPARE(handler->getPlayerInTurn(), player2);
}

void GameEventHandlerTest::testGetRoundNumber()
{
    std::shared_ptr<Student::GameEventHandler> handler = std::make_shared
            <Student::GameEventHandler>(Student::GameEventHandler());

    std::shared_ptr<Student::ObjectManager> manager = std::make_shared
            <Student::ObjectManager>(Student::ObjectManager());

    std::shared_ptr<Student::Player> player1 = std::make_shared
            <Student::Player>(Student::Player("Erkki",{},Qt::red));
    std::shared_ptr<Student::Player> player2 = std::make_shared
            <Student::Player>(Student::Player("Jorma",{},Qt::red));


    handler->addPlayers({player1, player2});
    handler->setObjectManager(manager);

    QCOMPARE(handler->getRoundNumber(),1);

    handler->changeTurn();
    handler->changeTurn();
    QCOMPARE(handler->getRoundNumber(),2);

    handler->changeTurn();
    handler->changeTurn();
    QCOMPARE(handler->getRoundNumber(),3);

}

void GameEventHandlerTest::testResourcemapMakeNegative()
{
    Course::ResourceMap resources = {
                                 {Course::BasicResource::MONEY, 231},
                                 {Course::BasicResource::FOOD, 451},
                                 {Course::BasicResource::WOOD, 234},
                                 {Course::BasicResource::STONE, 138}};

    Course::ResourceMap resourcesNegative = {
                                 {Course::BasicResource::MONEY, -231},
                                 {Course::BasicResource::FOOD, -451},
                                 {Course::BasicResource::WOOD, -234},
                                 {Course::BasicResource::STONE, -138}};

    std::shared_ptr<Student::GameEventHandler> handler = std::make_shared
            <Student::GameEventHandler>(Student::GameEventHandler());

    for (auto resource : handler->resourcemapMakeNegative(resources)){
        QCOMPARE(resource.second, resourcesNegative[resource.first]);
    }

    for (auto resource : handler->resourcemapMakeNegative(resourcesNegative)){
        QCOMPARE(resource.second, resources[resource.first]);
    }
}

void GameEventHandlerTest::testGetScores()
{
    std::shared_ptr<Student::GameEventHandler> handler = std::make_shared
            <Student::GameEventHandler>(Student::GameEventHandler());

    std::shared_ptr<Student::ObjectManager> manager = std::make_shared
            <Student::ObjectManager>(Student::ObjectManager());

    std::shared_ptr<Student::Player> player1 = std::make_shared
            <Student::Player>(Student::Player("Erkki",{},Qt::red));
    std::shared_ptr<Student::Player> player2 = std::make_shared
            <Student::Player>(Student::Player("Jorma",{},Qt::red));


    handler->addPlayers({player1, player2});
    handler->setObjectManager(manager);

    // 7000 Total
    Course::ResourceMap resources1 = {
                                 {Course::BasicResource::MONEY, 2000},
                                 {Course::BasicResource::FOOD, 3000},
                                 {Course::BasicResource::WOOD, 500},
                                 {Course::BasicResource::STONE, 1500}};

    // 9000 Total
    Course::ResourceMap resources2 = {
                                 {Course::BasicResource::MONEY, 3000},
                                 {Course::BasicResource::FOOD, 1700},
                                 {Course::BasicResource::WOOD, 1300},
                                 {Course::BasicResource::STONE, 3000}};

    player1->modifyResources(resources1);
    player2->modifyResources(resources2);

    // Player stariting resource total is 2500

    auto scores = handler->getScores();
    QCOMPARE(scores[player1->getName()], 9500);
    QCOMPARE(scores[player2->getName()], 11500);
}




QTEST_APPLESS_MAIN(GameEventHandlerTest)

#include "tst_gameeventhandlertest.moc"
