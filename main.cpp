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




GLfloat rock_posX = 0.0f;
void handleKeypress(unsigned char key, int x, int y) {
	switch (key)
	{
        case 'a':
            if(rock_posX>-0.9)
            rock_posX -= 0.15f;
            //printf("(%f,%f)\n",rock_posX-0.1,rock_posX+0.1);
            break;
        case 'd':
            if(rock_posX<0.9)
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
   displayStar();
   glLoadIdentity();
   displayStone();
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

   glutMainLoop();                 // Enter the infinite event-processing loop

   return 0;

}
