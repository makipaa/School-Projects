#include <QString>
#include <QtTest>
#include <core/gameeventhandler.h>

class GameEventHandlerTest : public QObject
{
    Q_OBJECT

public:
    GameEventHandlerTest();

private Q_SLOTS:

    void testModifyResource();
    void testModifyResources();
    void testAdd_players();
//    void testSetObjectManager();
    void testNew_round();
//    void testChangeTurn();
//    void testGetPlayerInTurn();
//    void testGetRoundNumber();
//    void testResourcemapMakeNegative();
//    void testGetScores();
};

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

void GameEventHandlerTest::testAdd_players()
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

void GameEventHandlerTest::testNew_round()
{

}


QTEST_APPLESS_MAIN(GameEventHandlerTest)

#include "tst_gameeventhandlertest.moc"
