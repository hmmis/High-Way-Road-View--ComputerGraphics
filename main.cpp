#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>

void DrawMainRoad(){

    ///==================================== Main Road
    glBegin(GL_POLYGON);
    glColor3f(0.2,0.2,0.2);
    glVertex2i(0,200);
    glVertex2i(800,200);
    glVertex2i(800,400);
    glVertex2i(0,400);
    glEnd();

    ///====================================Top Border of road
    glBegin(GL_LINES);
    glLineWidth(5);
	glColor3f(1.0,1.0,1.0);
    glVertex2i(0,380);
    glVertex2i(800,380);
    glEnd();

    ///====================================bottom Border of road
    glBegin(GL_LINES);
    glLineWidth(5);
	glColor3f(1.0,1.0,1.0);
    glVertex2i(0,220);
    glVertex2i(800,220);
    glEnd();

}

void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);

    DrawMainRoad();
    glFlush ();
}

void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    //glPointSize(15.0);
    //glLineWidth(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 600.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (0,0);
    glutCreateWindow ("Hello OpenGL");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();
}
