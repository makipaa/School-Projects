#-------------------------------------------------
#
# Project created by QtCreator 2019-11-28T14:17:40
#
#-------------------------------------------------

QT       += testlib

QT       += gui

TARGET = tst_gameeventhandlertest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        tst_gameeventhandlertest.cpp \
        ../../Game/core/objectmanager.cpp \
        ../../Game/core/gameeventhandler.cpp \
    ../../Game/Buildings/mine.cpp \
    ../../Game/Buildings/sawmill.cpp \
    ../../Game/Buildings/studentfarm.cpp \
    ../../Game/Buildings/studentHeadQuarters.cpp \
    ../../Game/Buildings/studentOutpost.cpp \
    ../../Game/Buildings/trawler.cpp \
    ../../Game/core/player.cpp \
    ../../Game/Student_tiles/cobblestone.cpp \
    ../../Game/Student_tiles/swamp.cpp \
    ../../Game/Student_tiles/water.cpp \
    ../../Game/Workers/farmer.cpp \
    ../../Game/Workers/fisher.cpp \
    ../../Game/Workers/luberjack.cpp \
    ../../Game/Workers/miner.cpp \
    ../../Game/Workers/peatworker.cpp \
    ../../Course/CourseLib/buildings/buildingbase.cpp \
    ../../Course/CourseLib/buildings/farm.cpp \
    ../../Course/CourseLib/buildings/headquarters.cpp \
    ../../Course/CourseLib/buildings/outpost.cpp \
    ../../Course/CourseLib/core/basicresources.cpp \
    ../../Course/CourseLib/core/coordinate.cpp \
    ../../Course/CourseLib/core/gameobject.cpp \
    ../../Course/CourseLib/core/placeablegameobject.cpp \
    ../../Course/CourseLib/core/playerbase.cpp \
    ../../Course/CourseLib/core/worldgenerator.cpp \
    ../../Course/CourseLib/tiles/forest.cpp \
    ../../Course/CourseLib/tiles/grassland.cpp \
    ../../Course/CourseLib/tiles/tilebase.cpp \
    ../../Course/CourseLib/workers/basicworker.cpp \
    ../../Course/CourseLib/workers/workerbase.cpp

HEADERS += \
        ../../Game/core/objectmanager.h \
        ../../Game/core/gameeventhandler.h \
    ../../Game/Buildings/mine.h \
    ../../Game/Buildings/sawmill.h \
    ../../Game/Buildings/studentfarm.h \
    ../../Game/Buildings/studentHeadQuarters.h \
    ../../Game/Buildings/studentOutpost.h \
    ../../Game/Buildings/trawler.h \
    ../../Game/core/player.h \
    ../../Game/core/resourcemaps.h \
    ../../Game/Student_tiles/cobblestone.h \
    ../../Game/Student_tiles/swamp.h \
    ../../Game/Student_tiles/water.h \
    ../../Game/Workers/farmer.h \
    ../../Game/Workers/fisher.h \
    ../../Game/Workers/luberjack.h \
    ../../Game/Workers/miner.h \
    ../../Game/Workers/peatworker.h \
    ../../Course/CourseLib/buildings/buildingbase.h \
    ../../Course/CourseLib/buildings/farm.h \
    ../../Course/CourseLib/buildings/headquarters.h \
    ../../Course/CourseLib/buildings/outpost.h \
    ../../Course/CourseLib/core/basicresources.h \
    ../../Course/CourseLib/core/coordinate.h \
    ../../Course/CourseLib/core/gameobject.h \
    ../../Course/CourseLib/core/placeablegameobject.h \
    ../../Course/CourseLib/core/playerbase.h \
    ../../Course/CourseLib/core/resourcemaps.h \
    ../../Course/CourseLib/core/worldgenerator.h \
    ../../Course/CourseLib/exceptions/baseexception.h \
    ../../Course/CourseLib/exceptions/illegalaction.h \
    ../../Course/CourseLib/exceptions/invalidpointer.h \
    ../../Course/CourseLib/exceptions/keyerror.h \
    ../../Course/CourseLib/exceptions/notenoughspace.h \
    ../../Course/CourseLib/exceptions/ownerconflict.h \
    ../../Course/CourseLib/interfaces/igameeventhandler.h \
    ../../Course/CourseLib/interfaces/iobjectmanager.h \
    ../../Course/CourseLib/tiles/forest.h \
    ../../Course/CourseLib/tiles/grassland.h \
    ../../Course/CourseLib/tiles/tilebase.h \
    ../../Course/CourseLib/workers/basicworker.h \
    ../../Course/CourseLib/workers/workerbase.h

INCLUDEPATH += \
            ../../Game/ \
            ../../Course/CourseLib

DEPENDPATH += \
            ../../Game/ \
            ../../Course/CourseLib
