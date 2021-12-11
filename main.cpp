#include <windows.h>
#include <MMSystem.h>
#include <iostream>
//#include<string>
//#include <boost/lexical_cast.hpp>
#include <sstream>
using namespace std;
#include <GL/glut.h>
#include <math.h>
#include "bonusBox.cpp"
#include "star.cpp"
#include "cloud.cpp"
#include "rocket.cpp"
#include "stone.cpp"


void initGL() {
   glClearColor(0.02f, 0.050f, 0.1f, 0.41f);
}
void showText(int num)
{
   string str;
   stringstream ss;
   ss << num;
   ss >> str;
   char const *strn = str.c_str();
   glColor3f (1.0f, 1.0f, 0.0f);
   glRasterPos2f(-0.95f, 0.9f); //define position on the screen
   while(*strn)
   {
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *strn++);
   }
}
void sound()
{
    PlaySound("Explosion7.wav", NULL, SND_ASYNC|SND_FILENAME);
}
int score=0;
GLfloat strMove = 0.00f;
bool newSignal = true;

GLfloat rock_posX = 0.0f;

GLfloat posLeftStn = 0.9f;
GLfloat posLeftStnHorizoneVal = -0.1f;

GLfloat posRightStn = 0.7f;

void update(int value) {
    bool flag = true;

    //For Star Movement
    if(newSignal == true)
    {
        if(strMove>=0.04){newSignal=false;}
        strMove+=0.001f;
    }
    else if (newSignal == false)
    {
        if(strMove<=0.0){newSignal=true;}
        strMove-=0.001f;
    }
    //For left stone
    if(posLeftStn < -1.4)
    {
        posLeftStn = 1.2f;
        score++;
        posLeftStnHorizoneVal = rock_posX;
    }
    else{
        posLeftStn-=0.1f;
    }
    //For right stone
    if(posRightStn < -1.4)
    {
        posRightStn = 1.2f;
        score++;
    }
    else{
        posRightStn-=0.19f;
    }

    //Collision calculation
    if(rock_posX+0.1>=0.500000 && rock_posX+0.1<=0.900000 || rock_posX-0.1>=0.500000 && rock_posX-0.1<=0.900000)
    {
        if(posRightStn+0.20<=-0.400000 && posRightStn+0.20>=-0.900000 || posRightStn-0.20<=-0.400000 && posRightStn-0.20>=-0.900000)
        {
            sound();
            flag = false;
            cout<<"Collision detected for right stone!"<<endl;
            //leftBoxCollition();
        }
    }
    if(rock_posX+0.1>=posLeftStnHorizoneVal-0.13 && rock_posX+0.1<=posLeftStnHorizoneVal+0.13 || rock_posX-0.1>=posLeftStnHorizoneVal-0.13 && rock_posX-0.1<=posLeftStnHorizoneVal+0.13)
    {
        if(posLeftStn+0.13<=-0.400000 && posLeftStn+0.13>=-0.900000 || posLeftStn-0.13<=-0.400000 && posLeftStn-0.13>=-0.900000)
        {
            sound();
            flag = false;
            cout<<"Collision detected for left stone!"<<endl;
            //leftBoxCollition();
        }
    }


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
   displayBonusBox();
   glLoadIdentity();
   displayStone(posLeftStnHorizoneVal,posLeftStn,posRightStn);
   glLoadIdentity();
   rocketShow(rock_posX);
   showText(score);
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

   PlaySound("sound.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

   glutMainLoop();                 // Enter the infinite event-processing loop

   return 0;

}
