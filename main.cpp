#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include "cloud.cpp"


void initGL() {


   glClearColor(0.02f, 0.050f, 0.1f, 0.41f);

}
void display() {

   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();
   displayCloud();
   glLoadIdentity();

   //Rocket bottom
   glTranslatef(0.0f, -0.9f, 0.0f);

   glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 0.0f);
      glVertex2f(-0.08f, 0.0f);
      glVertex2f(0.08f, 0.08f);
      glVertex2f(0.08f, 0.0f);
      glVertex2f(-0.08f, 0.08f);
   glEnd();
   //Rocket bottom square
   glLoadIdentity();
   glTranslatef(0.0f, -0.81f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.09f, 0.0f);
      glVertex2f(0.09f, 0.0f);
      glVertex2f(0.09f, 0.21f);
      glVertex2f(-0.09f, 0.21f);
   glEnd();
   //Rocket bottom propaler left
   glLoadIdentity();
   glTranslatef(0.0f, -0.78f, 0.0f);
   glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-0.09f, 0.0f);
      glVertex2f(-0.09f, 0.15f);
      glVertex2f(-0.15f, -0.03f);
   glEnd();
   //Rocket bottom propaler right
   glLoadIdentity();
   glTranslatef(0.0f, -0.78f, 0.0f);
   glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(0.09f, 0.0f);
      glVertex2f(0.09f, 0.15f);
      glVertex2f(0.15f, -0.03f);
   glEnd();
   //Rocket Upper square
   glLoadIdentity();
   glTranslatef(0.0f, -0.59f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.09f, 0.0f);
      glVertex2f(0.09f, 0.0f);
      glVertex2f(0.09f, 0.25f);
      glVertex2f(-0.09f, 0.25f);
   glEnd();
   //Rocket Upper square
   glLoadIdentity();
   glTranslatef(0.0f, -0.59f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.0f, 0.0f, 1.0f);
      glVertex2f(-0.02f, 0.07f);
      glVertex2f(0.02f, 0.07f);
      glVertex2f(0.02f, 0.14f);
      glVertex2f(-0.02f, 0.14f);
   glEnd();
   //Rocket Upper Triangle
   glLoadIdentity();
   glTranslatef(0.0f, -0.35f, 0.0f);
   glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-0.12f, 0.0f);
      glVertex2f(0.12f, 0.0f);
      glVertex2f(0.0f, 0.2f);
   glEnd();


   glLoadIdentity();
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
