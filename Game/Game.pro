  TEMPLATE = app
TARGET = TheGame

QT += core gui widgets \
      location

CONFIG += c++14

SOURCES += \
    main.cpp \
    UI/mapwindow.cc \
    core/worldmap.cpp \
    gameeventhandler.cpp \
    objectmanager.cpp \
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
    Workers/fisher.cpp

HEADERS += \
    UI/mapwindow.hh \
    core/worldmap.h \
    gameeventhandler.h \
    objectmanager.h \
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
    Workers/fisher.h


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
    UI/mapwindow.ui \
    UI/dialog.ui

DISTFILES += \
    Images/farm.png \
    Images/farm.png \
    Images/forest.png \
    Images/grass.png \
    Images/headquarters.png \
    Images/mountain.png \
    Images/outpost.png \
    Images/swamp.png \
    Images/water.png
