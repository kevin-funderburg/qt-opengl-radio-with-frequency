/***
*
*   Author: Kevin Funderburg
*   File:   fractal.cpp
*
**/
#include "fractal.h"

typedef GLfloat point2[2];

Fractal::Fractal(QWidget *parent) : QGLWidget(parent)
{
    
}

Fractal::~Fractal()
{

}

//Initialize the GL settings
void Fractal::initializeGL()
{
    this->n = 5;

    this->v[0][0] = -2.0;
    this->v[0][1] = -1.16;
    this->v[1][0] = 2.0;
    this->v[1][1] = -1.16;
    this->v[2][0] = 0.0;
    this->v[2][1] = 2.3;

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    srand(time(0));

    // Set up timer to change color and update
    QTimer *timer = new QTimer();
    timer->setInterval(1000);
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(draw()));
}

void Fractal::draw()
{
    float num1 = (float)rand() / RAND_MAX;
    float num2 = (float)rand() / RAND_MAX;
    float num3 = (num1 + num2) / 2;;
    glColor3f(num1, num2, num3);
    updateGL();
}

//Set up the viewport based on the screen dimentions
//Function is called implicitly by initializeGL and when screen is resized
void Fractal::resizeGL( int w, int h )
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
    glOrtho(-3, 3, -3, 3, -3, 3);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //implicit call to paintGL after resized
}

//Paints the GL scene
void Fractal::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT); 
    glClear(GL_DEPTH_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
        this->divide_triangle(v[0], v[1], v[2], n); 
    glEnd();
    glFlush();
}

void Fractal::divide_triangle(GLfloat *a, GLfloat *b, GLfloat *c, int m)
{
    /* triangle subdivision using vertex numbers */
    point2 v0, v1, v2;

    int j;
    if(m>0)
    {
        for(j=0; j<2; j++) v0[j]=(a[j]+b[j])/2;
        for(j=0; j<2; j++) v1[j]=(a[j]+c[j])/2;
        for(j=0; j<2; j++) v2[j]=(c[j]+b[j])/2;
        divide_triangle(a, v0, v1, m-1);
        divide_triangle(c, v1, v2, m-1);
        divide_triangle(b, v2, v0, m-1);
    }
    else
    {
    this->triangle(a,b,c);
    }
        
/* draw triangle at end of recursion */
}

void Fractal::triangle(GLfloat *a, GLfloat *b, GLfloat *c)
{
    glVertex2fv(a);
    glVertex2fv(b);
    glVertex2fv(c);
}



