/***
*
*   Author: Kevin Funderburg
*   File:   signal.cpp
*   GUI - Summer 2019 - Texas State University
*
***/

#include <QtGui/QtGui>
#include <QtOpenGL/QtOpenGL>
#include <QDebug>
#include <math.h>
#include "signal.h"

Signal::Signal(QWidget *parent)
    : QGLWidget(parent)
{

}

Signal::~Signal()
{

}

void Signal::setvals(int min, int max, int yvals[])
{
    MIN_Y = min;
    MAX_Y = max;
    for(int i = 0; i < 5; i++)
        ys[i] = yvals[i];
}

//Initialize the GL settings
void Signal::initializeGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glLineWidth(4.0);
    glPointSize(2.0);
}

//Set up the viewport based on the screen dimentions
//Function is called implicitly by initializeGL and when screen is resized
void Signal::resizeGL( int w, int h )
{
    //algorithm to keep scene "square" (preserve aspect ratio)
    //even if screen is streached
    if(w>h)
        glViewport((w-h)/2, 0, h, h);
    else
        glViewport(0, (h-w)/2, w, w);

    //setup the projection and switch to model view for transformations
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(1, 5.0, 0, MAX_Y, -5.0, 5.0);
    glMatrixMode(GL_MODELVIEW);

    //implicit call to paintGL after resized
}

void Signal::ngon(int n)
{

}

void Signal::draw()
{   
    glLoadIdentity();
    glBegin(GL_LINE_STRIP);
        glColor3f ( 2.0, 0.5, 1.0); // Pink 
        for(int n = 0; n < 5; n++)
            glVertex2f(sqrt(ys[n]), ys[n]);
    glEnd();     
}


//Paints the GL scene
void Signal::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    draw();

    glFlush ();
}

