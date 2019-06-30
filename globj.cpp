/*
    Kevin Funderburg
    GUI - Summer 2019 - Texas State University
    Inroduction to OpenGL
*/

#include <QtGui/QtGui>
#include <QtOpenGL/QtOpenGL>
#include <math.h>
#include "globj.h"

GLobj::GLobj(QWidget *parent)
    : QGLWidget(parent)
{

}

GLobj::~GLobj()
{

}

//Initialize the GL settings
void GLobj::initializeGL()
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
void GLobj::resizeGL( int w, int h )
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
    glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
    glMatrixMode(GL_MODELVIEW);

    //implicit call to paintGL after resized
}

void GLobj::ngon(int n)
{

}

void GLobj::paintShapes()
{   
    float radius = 0.5;
    float rot[] = {-45, 0, 1, 1};

    glLoadIdentity();

    // Dotted line
    glPushMatrix();                     // Save model-view matrix setting
    glTranslatef(-1, 2, 0);
    glRotatef(-45, 0, 1, 1);
    glBegin(GL_POINTS);
        glColor3f ( 2.0, 0.5, 0.0);
        glVertex3f(-4.0, 4.0, 0.0);
        glVertex3f(-3.0, 4.0, 0.0);
        glVertex3f(-2.0, 4.0, 0.0);
        glVertex3f(-1.0, 4.0, 0.0);
        glVertex3f(-0.0, 4.0, 0.0);
        glVertex3f( 1.0, 4.0, 0.0);
        glVertex3f( 2.0, 4.0, 0.0);
        glVertex3f( 3.0, 4.0, 0.0);
        glVertex3f( 4.0, 4.0, 0.0);
    glEnd();
    glPopMatrix();                      // Restore the model-view matrix

    // White line
    glPushMatrix();                     // Save model-view matrix setting
    glTranslatef(-2.5, 1.5, 0);
    glRotatef(-90, 0, 1, 1);
    glBegin(GL_LINES);
        glColor3f ( 1.0, 1.8, 4.0);  
        glVertex2f(-3.5, 3.5);
        glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
        glVertex2f( 3.5, 3.5);
    glEnd();     
    glPopMatrix();                      // Restore the model-view matrix

    // Yellow zig zag  Line strip
    glPushMatrix();                     // Save model-view matrix setting
    glTranslatef(1, +1.0, 0);
    glRotatef(-45, 0, 1, 1);
    glBegin(GL_LINE_STRIP);
        glColor3f ( 1.0, 1.0, 0.0);  
        glVertex3f( 3.0, 3.0, 0.0);
        glVertex3f(-3.0, 3.0, 0.0);
        glVertex3f( 2.5, 2.5, 0.0);
        glColor3f(0.7f, 0.7f, 0.2f); // Dark Gray
        glVertex3f(-2.5, 2.5, 0.0);
        glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
        glVertex3f( 2.0, 2.0, 0.0);        
    glEnd();
    glPopMatrix();                      // Restore the model-view matrix

    //Triangle above square
    glPushMatrix();                      // Restore the model-view matrix
    glTranslatef(-1, 0, 0);
    glRotatef(+45, 0, 1, 1);
        glBegin(GL_TRIANGLES);
        glColor3f ( 1.5, 0.0, 1.0);  // Pink
        glVertex3f(-2.0, 2.0, 0.0);
        glVertex3f( 2.0, 2.0, 0.0);
        glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
        glVertex3f( 0.0, 0.5, 0.0);
    glEnd(); 
    glPopMatrix();                      // Restore the model-view matrix

    //Left Triangle strip
    glPushMatrix();                      // Restore the model-view matrix
    glTranslatef(-1, -0.5, 0);
    glRotatef(+45, 0, 1, 1);
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
        glVertex3f(-0.5,  0.0, 0.0);
        glColor3f(0.7f, 2.0f, 1.0f); // Light Gray
        glVertex3f(-3.0,  1.5, 0.0);
        glVertex3f(-3.0, -1.5, 0.0);
        glColor3f ( 0.0,  3.0, 1.5); // Teal
        glVertex3f(-4.5,  0.0, 0.0);
    glEnd(); 
    glPopMatrix();                      // Restore the model-view matrix

    //Right Triangle strip
    glPushMatrix();                     // Save model-view matrix setting
    glTranslatef(1, -0.5, 0);
    glRotatef(-45, 0, 1, 1);
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
        glVertex3f(0.5,  0.0, 0.0);
        glColor3f(0.7f, 0.7f, 0.7f); // Light Gray
        glVertex3f(3.0, -1.5, 0.0);
        glVertex3f(3.0, 1.5, 0.0);
        glColor3f(1.0f, 1.0f, 1.0f); // White
        glVertex3f(4.5,  0.0, 0.0);
    glEnd(); 
    glPopMatrix();                      // Restore the model-view matrix

    //Center square
    glPushMatrix();                     // Save model-view matrix setting
    glTranslatef(0, 0, 0);
    glRotatef(0, 0, 0, 0);
    glBegin(GL_QUADS);
        glColor3f (1.0, 0.0, 0.0);
        glVertex3f(0, radius, radius);
        glVertex3f(radius, 0, radius);
        glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
        glVertex3f(0, -radius, radius);
        glVertex3f(-radius, 0, radius);
    glEnd();
    glPopMatrix();                      // Restore the model-view matrix

    //Bottom polygon
    glPushMatrix();                     // Save model-view matrix setting
    glTranslatef(0, -0.5, 0);
    glRotatef(0, 0, 1, 1);
    glBegin(GL_POLYGON);
        glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
        glVertex3f( 0.0, -0.5, radius);
        glVertex3f(-1.0, -2.5, radius);
        glColor3f ( 3.0,  1.0, 0.5); // Yellow
        glVertex3f(-1.0, -3.5, radius);
        glVertex3f( 0.0, -4.5, radius);
        glVertex3f( 1.0, -3.5, radius);     
        glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
        glVertex3f( 1.0, -2.5, radius);
    glEnd();
    glPopMatrix();                      // Restore the model-view matrix
 
    //3D cube
    glPushMatrix();                     // Save model-view matrix setting
    glTranslatef(-2.5, 3.5, 0);
    glRotatef(45, 0, 1, 1);
    glBegin(GL_QUADS);
        // Set The Color To Green
        glColor3f(0.0f,1.0f,0.0f);         
        glVertex3f( 1.0f, 1.0f,-1.0f);     
        glVertex3f(-1.0f, 1.0f,-1.0f);     
        glVertex3f(-1.0f, 1.0f, 1.0f);     
        glVertex3f( 1.0f, 1.0f, 1.0f);     
        // Set The Color To Orange
        glColor3f(1.0f,0.5f,0.0f);         
        glVertex3f( 1.0f,-1.0f, 1.0f);    
        glVertex3f(-1.0f,-1.0f, 1.0f);    
        glVertex3f(-1.0f,-1.0f,-1.0f);    
        glVertex3f( 1.0f,-1.0f,-1.0f);    
        // Set The Color To Red
        glColor3f(1.0f,0.0f,0.0f);         
        glVertex3f( 1.0f, 1.0f, 1.0f);   
        glVertex3f(-1.0f, 1.0f, 1.0f);   
        glVertex3f(-1.0f,-1.0f, 1.0f);   
        glVertex3f( 1.0f,-1.0f, 1.0f);   
        // Set The Color To Yellow
        glColor3f (1.0f,1.0f,0.0f);        
        glVertex3f( 1.0f,-1.0f,-1.0f);     
        glVertex3f(-1.0f,-1.0f,-1.0f);     
        glVertex3f(-1.0f, 1.0f,-1.0f);     
        glVertex3f( 1.0f, 1.0f,-1.0f);     
        // Set The Color To Blue
        glColor3f(0.0f,0.0f,1.0f);         
        glVertex3f(-1.0f, 1.0f, 1.0f);    
        glVertex3f(-1.0f, 1.0f,-1.0f);    
        glVertex3f(-1.0f,-1.0f,-1.0f);    
        glVertex3f(-1.0f,-1.0f, 1.0f);    
         // Set The Color To Violet
        glColor3f(1.0f,0.0f,1.0f);        
        glVertex3f( 1.0f, 1.0f,-1.0f);     
        glVertex3f( 1.0f, 1.0f, 1.0f);     
        glVertex3f( 1.0f,-1.0f, 1.0f);     
        glVertex3f( 1.0f,-1.0f,-1.0f);     
    glEnd();  
    glPopMatrix();                      // Restore the model-view matrix
}


//Paints the GL scene
void GLobj::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    paintShapes();

    glFlush ();
}

