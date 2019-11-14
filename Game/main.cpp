#include "UI/mapwindow.hh"

#include <QApplication>

/*
Q_DECLARE_METATYPE(std::vector<std::shared_ptr<Student::Player>>)
int metatype_id = qRegisterMetaType<std::vector<std::shared_ptr<Student::Player>>>("PlayerList");
*/

int main(int argc, char* argv[])
{

    QApplication app(argc, argv);

    MapWindow mapWindow;
    mapWindow.showMaximized();
    return app.exec();
}
