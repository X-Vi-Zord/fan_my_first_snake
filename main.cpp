#include "MainWindow.h"
#include <QApplication>
#include <QObject>
#include <QAction>




int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    mainWindow Mymenu;
    Mymenu.setWindowTitle("Snake");
    Mymenu.show();

    return app.exec();
}

