/***
*
*   Author: Kevin Funderburg
*   File:   freqency.cpp 
*
***/

#include <QtGui/QtGui>
#include <QtOpenGL/QtOpenGL>
#include <QDebug>
//#include <QtMath>
#include <QtCore/qmath.h>
#include <math.h>

#include "frequency.h"
#define PI 3.14159265

Frequency::Frequency(QWidget *parent)
    : QGLWidget(parent)
{

}

Frequency::~Frequency()
{

}

//Initialize the GL settings
void Frequency::initializeGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glLineWidth(2.0);
    glPointSize(2.0);
}

//Set up the viewport based on the screen dimentions
//Function is called implicitly by initializeGL and when screen is resized
void Frequency::resizeGL( int w, int h )
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
    glOrtho(0.0, 100.0, -7.0, 7.0, -5.0, 5.0);
    glMatrixMode(GL_MODELVIEW);

    //implicit call to paintGL after resized
}


void Frequency::draw()
{   
    int f = 25, //frequency of radio station
        v = 5,  //volume 
        t = 1;
    double y; 

    glLoadIdentity();
    glBegin(GL_LINE_STRIP);
        glColor3f(2.0, 0.5, 1.0);
        for(double x = 0; x < f*5; x += 0.05) {
            y = double(v) * cos((2*M_PI) * (1/double(f)) * x);
            qDebug() << x << " , " << y;
            glColor3f(0, x, y);
            glVertex2f(x, y);
        }
    glEnd();

}


//Paints the GL scene
void Frequency::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    draw();

    glFlush ();
}

