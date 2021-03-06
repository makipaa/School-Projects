  TEMPLATE = app
TARGET = TheGame

QT += core gui widgets \

CONFIG += c++14

SOURCES += \
    main.cpp \
    core/gameeventhandler.cpp \
    core/objectmanager.cpp \
    core/player.cpp \
    UI/dialog.cpp \
    Graphics/gamescene.cpp \
    Graphics/mapitem.cpp \
    Student_tiles/swamp.cpp \
    Student_tiles/water.cpp \
    Student_tiles/cobblestone.cpp \
    Buildings/mine.cpp \
    Buildings/trawler.cpp \
    Buildings/sawmill.cpp \
    Workers/fisher.cpp \
    Workers/miner.cpp \
    Graphics/tileborder.cpp \
    Buildings/studentOutpost.cpp \
    Buildings/studentfarm.cpp \
    Buildings/studentHeadQuarters.cpp \
    Workers/farmer.cpp \
    Workers/peatworker.cpp \
    Graphics/tilemarker.cpp \
    UI/enddialog.cpp \
    UI/mainwindow.cc \
    Workers/lumberjack.cpp

HEADERS += \
    core/gameeventhandler.h \
    core/objectmanager.h \
    core/player.h \
    UI/dialog.h \
    Graphics/gamescene.h \
    Graphics/mapitem.h \
    Student_tiles/swamp.h \
    core/resourcemaps.h \
    Student_tiles/water.h \
    Student_tiles/cobblestone.h \
    Buildings/mine.h \
    Buildings/trawler.h \
    Buildings/sawmill.h \
    Workers/fisher.h \
    Workers/miner.h \
    Graphics/tileborder.h \
    Buildings/studentOutpost.h \
    Buildings/studentfarm.h \
    Buildings/studentHeadQuarters.h \
    Workers/farmer.h \
    Workers/peatworker.h \
    Graphics/tilemarker.h \
    UI/enddialog.h \
    UI/mainwindow.hh \
    Workers/lumberjack.h


win32:CONFIG(release, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/release/ -lCourseLib
else:win32:CONFIG(debug, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/debug/ -lCourseLib
else:unix: LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/ -lCourseLib

INCLUDEPATH += \
    $$PWD/../Course/CourseLib

DEPENDPATH += \
    $$PWD/../Course/CourseLib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/libCourseLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/libCourseLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/CourseLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/CourseLib.lib
else:unix: PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/libCourseLib.a

FORMS += \
    UI/dialog.ui \
    UI/enddialog.ui \
    UI/mainwindow.ui

RESOURCES += \
    images.qrc
