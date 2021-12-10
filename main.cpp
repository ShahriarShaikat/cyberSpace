#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include "star.cpp"
#include "cloud.cpp"
#include "rocket.cpp"
#include "stone.cpp"


void initGL() {


   glClearColor(0.02f, 0.050f, 0.1f, 0.41f);

}
void display() {

   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();
   displayCloud();
   glLoadIdentity();
   displayStar();
   glLoadIdentity();
   rocketShow();
   glLoadIdentity();
   displayStone();

   glFlush();
}


int main(int argc, char** argv) {

   glutInit(&argc, argv);          // Initialize GLUT

   glutInitWindowSize(920, 730);  // Set the window's initial width & height - non-square

   glutInitWindowPosition(300, 50); // Position the window's initial top-left corner

   glutCreateWindow("Cyber Space");  // Create window with the given title

   glutDisplayFunc(display);      // Register callback handler for window re-size event

   initGL();                       // Our own OpenGL initialization

   glutMainLoop();                 // Enter the infinite event-processing loop

   return 0;

}
