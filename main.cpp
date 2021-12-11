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
#include "points.cpp"
#include "satelite.cpp"

float RandomFloat(float min, float max){
   return ((max - min) * ((float)rand() / RAND_MAX)) + min;
}

void initGL() {
   glClearColor(0.02f, 0.050f, 0.1f, 0.41f);
}

void gameOverFN()
{
   char const *strn = "GAME OVER";
   glScalef(0.5f,0.5f,0.0f);
   glColor3f (1.0f, 1.0f, 0.0f);
   glLoadIdentity();
   glRasterPos2f(-0.1f, 0.0f); //define position on the screen
   while(*strn)
   {
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *strn++);
   }
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




bool gameOver= false;
int score=0;
GLfloat strMove = 0.00f;
bool newSignal = true;

GLfloat rock_posX = 0.0f;


GLfloat bonusBOxX = 0.0f;
GLfloat bonusBOxY = 2.5f;

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
    //For bonus box
    if(bonusBOxY < -1.4)
    {
        bonusBOxY = 2.5f;
        //bonusBOxX = rock_posX-0.1;
        cout << RandomFloat(-0.9, 0.9);
        bonusBOxX =   RandomFloat(-0.9, 0.9);

    }
    else{
        bonusBOxY-=0.12f;
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
            gameOver = true;
            //gameOverFN();
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
            gameOver = true;
            //gameOverFN();
            cout<<"Collision detected for left stone!"<<endl;
            //leftBoxCollition();
        }
    }
    if(rock_posX-0.1<=bonusBOxX-0.06 && rock_posX+0.1>=bonusBOxX-0.06 || rock_posX-0.1<=bonusBOxX+0.06 && rock_posX+0.1>=bonusBOxX+0.06)
    {
        if(bonusBOxY+0.06<=-0.400000 && bonusBOxY+0.06>=-0.900000 || bonusBOxY-0.06<=-0.400000 && bonusBOxY-0.06>=-0.900000)
        {
            //sound(bonus.wav);
            //PlaySound("bonus.wav", NULL, SND_ASYNC|SND_FILENAME);
            //PlaySound("sound.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
            score+=5;
            //bonusBOxY = 2.5f;
             bonusBOxY = 2.5f;
             bonusBOxX =   RandomFloat(-0.9, 0.9);
            cout<<"Collision detected for bonus box!"<<endl;

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
    if(gameOver == false)
    {
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


        }
        glutPostRedisplay();
    }

}

void display() {

   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();
   displayPoints();
   glLoadIdentity();
   displayCloud();
   glLoadIdentity();
   displayStar(strMove);
   glLoadIdentity();
   displayStone(posLeftStnHorizoneVal,posLeftStn,posRightStn);
   glLoadIdentity();
   displayBonusBox(bonusBOxX,bonusBOxY);
   glLoadIdentity();

   displaySatelite(0.7, 0.5);
   rocketShow(rock_posX);
   showText(score);
   if(gameOver==true)
   {
       gameOverFN();
   }
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
