#include "UI/mapwindow.hh"

#include <QApplication>

int main(int argc, char* argv[])
{

    QApplication app(argc, argv);

    MapWindow mapWindow;
    mapWindow.showMaximized();
    return app.exec();
}
