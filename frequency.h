/***
*
*	Author:	Kevin Funderburg
*	File: frequency.h
*
***/

#ifndef FREQUENCY_H
#define FREQUENCY_H

#include <QtOpenGL/QGLWidget>

class Frequency : public QGLWidget  {
    Q_OBJECT

public:
    Frequency(QWidget *parent = 0);
    ~Frequency();

protected:
    void initializeGL();
    void resizeGL(int w, int h);    
	void draw();
	void paintGL();
};

#endif
