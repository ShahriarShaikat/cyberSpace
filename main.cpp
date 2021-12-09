#include <windows.h>
#include <GL/glut.h>
#include <math.h>


void initGL() {


   glClearColor(0.02f, 0.050f, 0.1f, 0.41f);

}

void drawCircle(double x,double y,double radious,float r,float g,float b) {
float x2,y2;
float angle;
double radius=radious;



glColor3f(r, g, b);



glBegin(GL_POLYGON);
glVertex2f(x,y);



for (angle=1.0f;angle<361.0f;angle+=0.2)
{
x2 = x+sin(angle)*radius;
y2 = y+cos(angle)*radius;
//glScalef(0.3f,0.3f,0.0f);
glVertex2f(x2,y2);
}



glEnd();
}

void display() {

   glClear(GL_COLOR_BUFFER_BIT);


   glLoadIdentity();


   glTranslatef(0.0f, -0.9f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 0.0f);

      glVertex2f(-0.08f, 0.0f);
      glVertex2f(0.08f, 0.08f);
      glVertex2f(0.08f, 0.0f);
      glVertex2f(-0.08f, 0.08f);
   glEnd();

   glLoadIdentity();
   glFlush();
}

//shovon

int main(int argc, char** argv) {

   glutInit(&argc, argv);          // Initialize GLUT

   glutInitWindowSize(950, 730);  // Set the window's initial width & height - non-square

   glutInitWindowPosition(300, 50); // Position the window's initial top-left corner

   glutCreateWindow("Cyber Space");  // Create window with the given title

   glutDisplayFunc(display);      // Register callback handler for window re-size event

   initGL();                       // Our own OpenGL initialization

   glutMainLoop();                 // Enter the infinite event-processing loop

   return 0;

}
