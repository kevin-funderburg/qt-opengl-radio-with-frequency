/***
*
*   Author: Kevin Funderburg 
*   File: mainwindow.cpp
*
***/

#include <QtGui>
#include <QDebug>
#include <GL/glut.h>
#include "radio.h"
#include "globj.h"
#include "signal.h"
#include "mainwindow.h"


MainWindow::MainWindow()
{
    globj = new GLobj(this);

    QWidget *radio = new Radio;
    setCentralWidget(radio);

    createActions();     // Initialize the acitions for the menus
    createMenus();       // Add the actions to the menus
    createStatusBar();   // Add status bar

    createDockWindows(); // Create and fill windows 

    setWindowTitle(tr("My QGL"));
    setUnifiedTitleAndToolBarOnMac(true);
}


void MainWindow::createActions()
{
    /// Each action below is created with shortcuts, a status tip,
    /// and then is connected to slot function that will perform
    /// the desired action.
    loadAct = new QAction(tr("&Load ASCII File"), this);
    loadAct->setShortcuts(QKeySequence::New);
    loadAct->setStatusTip(tr("Create a new form letter"));
    connect(loadAct, SIGNAL(triggered()), this, SLOT(loadFile()));

    undoAct = new QAction(tr("&Undo..."), this);
    undoAct->setShortcuts(QKeySequence::Undo);
    undoAct->setStatusTip(tr("Undo last change"));
    connect(undoAct, SIGNAL(triggered()), this, SLOT(undo()));

    quitAct = new QAction(tr("&Quit"), this);
    quitAct->setShortcuts(QKeySequence::Quit);
    quitAct->setStatusTip(tr("Quit the application"));
    connect(quitAct, SIGNAL(triggered()), this, SLOT(close()));

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MainWindow::createMenus()
{
    // Instantiate the menu bars with their respective actions
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(loadAct);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAct);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(undoAct);

    viewMenu = menuBar()->addMenu(tr("&View"));

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}

void MainWindow::loadFile()
{
    QFile file("./S2.txt");
    if (!file.open(QFile::ReadWrite | QFile::Text)) {
        QMessageBox::warning(this, tr("Stored Signal"),
                             tr("Cannot open file %1:\n%2.")
                                     .arg("./S2.txt")
                                     .arg(file.errorString()));
        return;
    }
    QTextStream in(&file);
    QString str, line;
    QStringList minmaxlist, yvalues;
    while(!in.atEnd())
    {
        line = in.readLine();    
        if (! line.contains("S2") || line.contains("#"))
        {
            qDebug() << "line length " << line.length();
            if (line.length() <= 5)
                minmaxlist = line.split(" ");
            else
                yvalues = line.split(" ");
        }
    }
    int minmax[minmaxlist.length()];
    int ys[yvalues.length()];

    for(int i = 0; i < minmaxlist.length(); i++)
        minmax[i] = minmaxlist[i].toInt();
    for(int i = 0; i < yvalues.length(); i++)
       ys[i] = yvalues[i].toInt();

    qDebug() << minmaxlist.length();
    qDebug() << yvalues.length();
    signal = new Signal(this);
    signal->setvals(minmax[0], minmax[1], ys);
}

void MainWindow::undo()
{
    //QTextDocument *document = textEdit->document();
    //document->undo();
}

// Simple about window located within the help menu
void MainWindow::about()
{
    QMessageBox::about(this, tr("About Dock Widgets With Radio"),
                       tr("The <b>Dock Widgets</b> example demonstrates how to "
                          "use Qt's dock widgets. You can open files within the "
                          "text editor pane, enter your own text, and save files "
                          "to the system."));
}

void MainWindow::createStatusBar() { statusBar()->showMessage(tr("Ready")); }

void MainWindow::createDockWindows()
{
    int MIN_WIDTH = 300,
        MIN_HEIGHT = 300;

    QDockWidget *dock = new QDockWidget(tr("shapes"), this);
    dock->setAllowedAreas(Qt::AllDockWidgetAreas);
    dock->setMinimumWidth(MIN_WIDTH);
    dock->setMinimumHeight(MIN_HEIGHT);
    dock->setWidget(globj);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    loadFile();
    dock = new QDockWidget(tr("wave"), this);
    dock->setMinimumWidth(MIN_WIDTH);
    dock->setMinimumHeight(MIN_HEIGHT);
    dock->setWidget(signal);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    dock = new QDockWidget(tr("fractal"), this);
    dock->setMinimumWidth(MIN_WIDTH);
    dock->setMinimumHeight(MIN_HEIGHT);
    dock->setWidget(globj);
    addDockWidget(Qt::LeftDockWidgetArea, dock);

    dock = new QDockWidget(tr("frequency"), this);
    dock->setMinimumWidth(MIN_WIDTH);
    dock->setMinimumHeight(MIN_HEIGHT);
    dock->setWidget(globj);
    addDockWidget(Qt::LeftDockWidgetArea, dock);


//    addDockWidget(Qt::LeftDockWidgetArea, dock);
//    addDockWidget(Qt::TopDockWidgetArea, dock);
//    addDockWidget(Qt::BottomDockWidgetArea, dock);

    // Add toggle button in the view menu
    viewMenu->addAction(dock->toggleViewAction());
}
