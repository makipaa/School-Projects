#include "UI/mainwindow.hh"
#include <QApplication>


int main(int argc, char* argv[])
{
     int currentExitCode = 0;

     do {
      QApplication app(argc, argv);
      MainWindow mapWindow;
      mapWindow.showMaximized();
      currentExitCode = app.exec();
     } while( currentExitCode == 1000);

     return currentExitCode;
}
