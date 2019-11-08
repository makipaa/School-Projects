#include "UI/mapwindow.hh"

#include <QApplication>

int main(int argc, char* argv[])
{

    QApplication app(argc, argv);

    Student::MapWindow mapWindow;
    mapWindow.show();
    return app.exec();
}
