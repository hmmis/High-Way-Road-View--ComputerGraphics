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

     ///====================================road divider
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    int dividerLine=0;
    for(int i=0;i<20;i++){
        glVertex2i(dividerLine+20,300);
        glVertex2i(dividerLine+40,300);
        dividerLine=dividerLine+40;
    }
    glEnd();

    ///==================================== Bottom Road Side Bar


    int changeX1=0,changeX2=40;

    for(int i=0;i<20;i++){
        glBegin(GL_POLYGON);
        if(i%2==0){
            glColor3ub(1,1,1);  //black color
        }else{
            glColor3ub(217, 217, 217);  //white color
        }

        glVertex2i(changeX1,180);
        glVertex2i(changeX2,180);
        glVertex2i(changeX2,210);
        glVertex2i(changeX1,210);

        changeX1=changeX2;
        changeX2=changeX2+40;
        glEnd();
    }



    ///==================================== Bottom Road Side Bar Top View
    glBegin(GL_LINES);
    glLineWidth(5);
	glColor3f(204, 153, 0);     //yellow color
    glVertex2i(0,210);
    glVertex2i(800,210);
    glEnd();

     ///==================================== Top Road Side Bar


    int TopChangeX1=0,TopchangeX2=40;

    for(int i=0;i<20;i++){
        glBegin(GL_POLYGON);
        if(i%2==1){
            glColor3ub(1,1,1);  //black color
        }else{
            glColor3ub(217, 217, 217);  //white color
        }

        glVertex2i(TopChangeX1,400);
        glVertex2i(TopchangeX2,400);
        glVertex2i(TopchangeX2,420);
        glVertex2i(TopChangeX1,420);

        TopChangeX1=TopchangeX2;
        TopchangeX2=TopchangeX2+40;
        glEnd();
    }

    ///==================================== Top Road Side Bar Top View
    glBegin(GL_LINES);
    glLineWidth(5);
	glColor3f(204, 153, 0);     //yellow color
    glVertex2i(0,420);
    glVertex2i(800, 420);
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
    glClearColor(0.0,0.7,1.5,0.0);  //sky color
    glColor3f(0.0f, 0.0f, 0.0f);
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
    glutCreateWindow ("High Way Road View");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();
}
