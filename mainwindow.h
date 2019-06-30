/**
* 
*  Author:   Kevin Funderburg
*  File:     mainwindow.cpp
* 
**/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QWidget>
#include <QCheckBox>

class QAction;
class QListWidget;
class QMenu;
class QTextEdit;

class GLobj;
class Signal;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

    GLobj *globj;
    //GLobj *signal;
    Signal *signal;

private slots:
    //void save();
    void open();
    void loadFile();
    void undo();
    void about();

private:
    void createActions();
    void createMenus();
    void createStatusBar();
    void createDockWindows();

    //QTextEdit *textEdit;
    //QListWidget *customerList;
    //QListWidget *paragraphsList;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *viewMenu;
    QMenu *helpMenu;
    QToolBar *fileToolBar;
    QToolBar *editToolBar;
    QAction *loadAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *undoAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
    QAction *quitAct;
};

#endif
