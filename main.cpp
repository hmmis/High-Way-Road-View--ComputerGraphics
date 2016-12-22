#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

void keyboard(unsigned char , int , int );
void update(int);
void draw_circle(float x, float y, float radius);
float moveCar1 = 0.0f;
float moveCar2 = 800.0f;
float moveBusUp=0.0f;
float positionOfCarOne=0;
float positionOfCarTwo=0;

void DrawCarOne();
void DrawCarTow();
void DrawBodyOfCarOne();
void DrawBodyOfCarTow();
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

     ///==================================== Draw Building two
    glBegin(GL_POLYGON);
	glColor3ub(153, 51, 51);
    glVertex2i(100,420);
    glVertex2i(200,420);
    glVertex2i(200,600);
    glVertex2i(100,600);
    glEnd();

    int buildingY1=570,buildingY2=573;
	for(int i=0;i<7;i++){
        //=================flor of building 1
        glBegin(GL_POLYGON);
        glColor3ub(153, 153, 102);
        glVertex2i(100,buildingY1);
        glVertex2i(200,buildingY1);
        glVertex2i(200,buildingY2);
        glVertex2i(100,buildingY2);
        glEnd();
        buildingY1=buildingY1-25;
        buildingY2=buildingY2-25;
	}

	///==================================== Draw Building One
    glBegin(GL_POLYGON);
	glColor3ub(102, 153, 153);
    glVertex2i(10,420);
    glVertex2i(110,420);
    glVertex2i(110,580);
    glVertex2i(10,580);
    glEnd();

    //===============================gate of building one
    glBegin(GL_POLYGON);
	glColor3ub(242, 242, 242);
    glVertex2i(50,420);
    glVertex2i(70,420);
    glVertex2i(70,440);
    glVertex2i(50,440);
    glEnd();

    int b1y1=450,b1y2=460;
    int b1x1=15,b1x2=35;
	for(int i=1;i<16;i++){
        glBegin(GL_POLYGON);

        glColor3ub(242, 242, 242);
        glVertex2i(b1x1,b1y1);
        glVertex2i(b1x2,b1y1);
        glVertex2i(b1x2,b1y2);
        glVertex2i(b1x1,b1y2);
        glEnd();


        b1x1=b1x1+35;
        b1x2=b1x2+35;
        if(i%3==0){
            b1x1=15;
            b1x2=35;
            b1y1=b1y1+25;
            b1y2=b1y2+25;
        }

	}


}
void DrawCar()
{
    glPushMatrix();
    DrawCarOne();
    DrawCarTow();


}
void DrawBodyOfCarOne(){
    glVertex2i(0,330);
    glVertex2i(120,330);
    glVertex2i(120,345);
    glVertex2i(115,350);
    glVertex2i(90,350);
    glVertex2i(70,365);
    glVertex2i(40,365);
    glVertex2i(20,350);
    glVertex2i(0,350);
    glEnd();
}
void DrawCarOne(){
     glPushMatrix();
     glTranslatef(moveCar1, 0.0f, 0.0f);
    positionOfCarOne=120+moveCar1;
    //==================================Body of a car
	glBegin(GL_POLYGON);
    glColor3ub(204, 204, 0);
    DrawBodyOfCarOne();


    glBegin(GL_LINE_LOOP);
    glColor3ub(255, 255, 255);
    DrawBodyOfCarOne();

    //==================================glass of a car
    glBegin(GL_POLYGON);
    glColor3ub(204, 51, 0);
    glVertex2i(25,350);
    glVertex2i(85,350);
    glVertex2i(67,360);
    glVertex2i(43,360);
    glEnd();
    //==================================chaka of a car
    glColor3f(0, 0, 0);
    draw_circle(15+moveCar1,330,10);
    draw_circle(90+moveCar1,330,10);
    glPopMatrix();
}

void DrawCarTow(){
    glPushMatrix();
    glTranslatef(moveCar2,moveBusUp, 0.0f);

    positionOfCarTwo=0+moveCar2;
    //==================================Body of a bus
	glBegin(GL_POLYGON);
	glColor3ub(204, 0, 0);
	DrawBodyOfCarTow();


    //==================================Sidebar of Bus
    glBegin(GL_LINE_LOOP);
    glColor3ub(255, 255, 255);
    DrawBodyOfCarTow();

    //==================================glass of of a bus
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
    glVertex2i(90,270);
    glVertex2i(110,270);
    glVertex2i(110,280);
    glVertex2i(90,280);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
    glVertex2i(65,270);
    glVertex2i(85,270);
    glVertex2i(85,280);
    glVertex2i(65,280);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
    glVertex2i(60,270);
    glVertex2i(40,270);
    glVertex2i(40,280);
    glVertex2i(60,280);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
    glVertex2i(35,270);
    glVertex2i(15,270);
    glVertex2i(15,280);
    glVertex2i(35,280);
    glEnd();

    //==================================chaka of a bus carTwo
    glColor3f(0, 0, 0);
    draw_circle(20+moveCar2,255+moveBusUp,8);
    draw_circle(105+moveCar2,255+moveBusUp,8);
    draw_circle(85+moveCar2,255+moveBusUp,8);
    glPopMatrix();
}
void DrawBodyOfCarTow(){
    glVertex2i(0,260);
    glVertex2i(5,255);
    glVertex2i(120,255);
    glVertex2i(120,290);
    glVertex2i(5,290);
    glVertex2i(0,285);
    glEnd();
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
    glutInitWindowSize (800, 800);
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
        moveCar2=moveCar2-5;
        glutPostRedisplay();
    }
    else if(key=='u' && (moveBusUp+270)<400)
    {
        //speed up of car 2

            moveBusUp=moveBusUp+1;
            glutPostRedisplay();
    }
    else if(key=='d' && (moveBusUp+270)>235)
    {
        //speed up of car 2
        moveBusUp=moveBusUp-1;
        glutPostRedisplay();
    }
    else if(key=='x')
    {
        moveCar1=moveCar1-2;
        moveCar2 = moveCar2+2;
        glutPostRedisplay();
    }
}
void update(int value) {

    moveCar1 = moveCar1+2;  //initial speed

    moveCar2 = moveCar2-2;  //initial speed
    if(moveCar2< 0 && moveCar1> 800)
    {
        moveCar1 =-200;
        moveCar2 =1000;
    }
    if(positionOfCarOne==positionOfCarTwo){
       moveCar1=moveCar1-2;
       moveCar2 = moveCar2+2;
        //glTranslatef(0, 0, 0);
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
