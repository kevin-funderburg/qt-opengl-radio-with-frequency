/***
*
*   Author: Kevin Funderburg 
*   File:   main.cpp
*
***/

#include <QApplication>
#include <QDesktopWidget>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.resize( 700, 500 );
    window.show();

    return app.exec();
}
