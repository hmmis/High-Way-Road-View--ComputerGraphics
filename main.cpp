#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

void keyboard(unsigned char , int , int );
void update(int);
void draw_circle(float x, float y, float radius);
float moveCar1 = 0.0f;
float moveCar2 = 0.0f;
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


void DrawGrassField(){
     ///==================================== add grass
    glBegin(GL_POLYGON);
	glColor3f(0,0.60,0);     //green color
    glVertex2i(0,0);
    glVertex2i(800, 0);
    glVertex2i(800,180);
    glVertex2i(0, 180);
    glEnd();

    ///====================================1st lane Tree draw
    int treeDistance=0;
    for(int i=0;i<4;i++){
        glBegin(GL_POLYGON);
        glColor3ub(102, 51, 0);  //tree body color
        glVertex2i(60+treeDistance,30);
        glVertex2i(70+treeDistance,30);
        glVertex2i(65+treeDistance,150);
        glEnd();
        glColor3f(0, 153, 0);   //tree leaf color
        draw_circle(50+treeDistance,100,20);     //tree  top 1st leaf
        draw_circle(80+treeDistance,100,20);     //tree top 2nd leaf
        draw_circle(58+treeDistance,130,18);     //tree middle 1st leaf
        draw_circle(72+treeDistance,130,18);     //tree middle 2nd leaf
        draw_circle(65+treeDistance,150,14);     //tree top leaf

        treeDistance=treeDistance+200;
    }

    ///====================================2nd lane Tree draw
    treeDistance=100;
    for(int i=0;i<4;i++){
        glBegin(GL_POLYGON);
        glColor3ub(102, 51, 0);  //tree body color
        glVertex2i(60+treeDistance,100);
        glVertex2i(70+treeDistance,100);
        glVertex2i(65+treeDistance,220);
        glEnd();
        glColor3f(0, 153, 0);   //tree leaf color
        draw_circle(50+treeDistance,170,20);     //tree  top 1st leaf
        draw_circle(80+treeDistance,170,20);     //tree top 2nd leaf
        draw_circle(58+treeDistance,200,18);     //tree middle 1st leaf
        draw_circle(72+treeDistance,200,18);     //tree middle 2nd leaf
        draw_circle(65+treeDistance,220,14);     //tree top leaf

        treeDistance=treeDistance+200;
    }
}
void DrawCity()
{


    ///==================================== Draw Sun
    glColor3f(255, 255, 0);   //sun color
    draw_circle(300,740,50);

}
void DrawCar()
{
    glPushMatrix();
	glTranslatef(moveCar1, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(255, 255, 0);
	glVertex2i(0,330);
    glVertex2i(30,330);
    glVertex2i(30,350);
    glVertex2i(0,350);
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(moveCar2+3, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(255, 255, 0);
	glVertex2i(0,220);
    glVertex2i(30,220);
    glVertex2i(30,240);
    glVertex2i(0,240);

	glEnd();
    glPopMatrix();

}
void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    DrawCity();
    DrawMainRoad();
    DrawCar();
    DrawGrassField();
    glFlush ();
}

void myInit (void)
{
    glClearColor(0.0,0.7,1.5,0.0);  //sky color
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 800.0);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (700, 700);
    glutInitWindowPosition (0,0);
    glutCreateWindow ("High Way Road View");
    glutDisplayFunc(myDisplay);
    glutTimerFunc(25, update, 100); //Add a timer
    glutKeyboardFunc(keyboard);     //keyboard
    myInit ();
    glutMainLoop();
}


//=============================================method
void keyboard(unsigned char key, int x, int y)
{

    if(key=='s')
    {
        //speed up of car 1
        moveCar1=moveCar1+5;
        glutPostRedisplay();
    }
    else if(key=='a')
    {
        //speed up of car 2
        moveCar2=moveCar2+5;
        glutPostRedisplay();
    }


}
void update(int value) {

    moveCar1 = moveCar1+2;  //initial speed
    if(moveCar1> 800)
    {
        moveCar1 =0;
    }

    moveCar2 = moveCar2+3;  //initial speed
    if(moveCar2> 800)
    {
        moveCar2 =0;
    }
	glutPostRedisplay(); //Tell GLUT that the display has changed
	glutTimerFunc(25, update, 0);   //Tell GLUT to call update again in 25 milliseconds
}

void draw_circle(float x, float y, float radius) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(x, y, 0.0f);
    static const int circle_points = 100;
    static const float angle = 2.0f * 3.1416f / circle_points;

    glBegin(GL_POLYGON);
    double angle1=0.0;
    glVertex2d(radius * cos(0.0) , radius * sin(0.0));
    int i;
    for (i=0; i<circle_points; i++)
    {
        glVertex2d(radius * cos(angle1), radius *sin(angle1));
        angle1 += angle;
    }
    glEnd();
    glPopMatrix();
}
