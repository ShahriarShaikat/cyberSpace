#include <windows.h>
#include<iostream>
using namespace std;
#include <GL/glut.h>
#include <math.h>
#include "star.cpp"
#include "cloud.cpp"
#include "rocket.cpp"
#include "stone.cpp"


void initGL() {
   glClearColor(0.02f, 0.050f, 0.1f, 0.41f);
}




GLfloat strMove = 0.00f;
int signal = 1;

GLfloat rock_posX = 0.0f;
GLfloat posLeftStn = 0.9f;
GLfloat posLeftStnHorizoneVal = -0.1f;
GLfloat posRightStn = 0.7f;

void update(int value) {
    bool flag = true;

    //For Star Movement
    if(signal == 1)
    {
        if(strMove>=0.04){signal=2;}
        strMove+=0.001f;
    }
    else if (signal == 2)
    {
        if(strMove<=0.0){signal=1;}
        strMove-=0.001f;
    }
    //For left stone
    if(posLeftStn < -1.4)
    {
        posLeftStn = 1.2f;
        posLeftStnHorizoneVal = rock_posX;
    }
    else{
        posLeftStn-=0.1f;
    }
    //For right stone
    if(posRightStn < -1.4)
    {
        posRightStn = 1.2f;
    }
    else{
        posRightStn-=0.19f;
    }

    //Collition
    /*if(rock_posX+0.1<=-0.700000 && rock_posX+0.1>=-0.900000 || rock_posX-0.1<=-0.700000 && rock_posX-0.1>=-0.900000)
    {
        if(posLeftBox+0.1<=-0.700000 && posLeftBox+0.1>=-0.900000 || posLeftBox-0.1<=-0.700000 && posLeftBox-0.1>=-0.900000)
        {
            flag = false;
            printf("Collision detected for left boxs!\n");
            leftBoxCollition();
        }
    }
    if(rock_posX+0.1>=0.700000 && rock_posX+0.1<=0.900000 || rock_posX-0.1>=0.700000 && rock_posX-0.1<=0.900000)
    {
        if(posRightBox+0.1<=-0.700000 && posRightBox+0.1>=-0.900000 || posRightBox-0.1<=-0.700000 && posRightBox-0.1>=-0.900000)
        {
            flag = false;
            printf("Collision detected for right boxs!\n");
            rightBoxCollition();
        }
    }*/


	glutPostRedisplay();
	if(flag)
    {
        glutTimerFunc(100, update, 0);
    }
}
void handleKeypress(unsigned char key, int x, int y) {
	switch (key)
	{
        case 'a':
            if(rock_posX>-0.8)
            rock_posX -= 0.15f;
            //printf("(%f,%f)\n",rock_posX-0.1,rock_posX+0.1);
            break;
        case 'd':
            if(rock_posX<0.8)
            rock_posX += 0.15f;
            //printf("(%f,%f)\n",rock_posX-0.1,rock_posX+0.1);
            break;


	}glutPostRedisplay();
}

void display() {

   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();
   displayCloud();
   glLoadIdentity();
   displayStar(strMove);
   glLoadIdentity();
   displayStone(posLeftStnHorizoneVal,posLeftStn,posRightStn);
   glLoadIdentity();
   rocketShow(rock_posX);

   glFlush();
}


int main(int argc, char** argv) {

   glutInit(&argc, argv);          // Initialize GLUT

   glutInitWindowSize(920, 730);  // Set the window's initial width & height - non-square

   glutInitWindowPosition(300, 50); // Position the window's initial top-left corner

   glutCreateWindow("Cyber Space");  // Create window with the given title

   glutDisplayFunc(display);      // Register callback handler for window re-size event

   initGL();                       // Our own OpenGL initialization

   glutKeyboardFunc(handleKeypress);

   glutTimerFunc(500, update, 0);

   glutMainLoop();                 // Enter the infinite event-processing loop

   return 0;

}
