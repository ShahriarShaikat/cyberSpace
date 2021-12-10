
void drawCircle(double x,double y,double radious,float r,float g,float b) {
float x2,y2;
float angle;
double radius=radious;
glLoadIdentity();
glBegin(GL_POLYGON);
glColor3f(r, g, b);
glVertex2f(x,y);

for (angle=1.0f;angle<361.0f;angle+=0.2)
{
x2 = x+sin(angle)*radius;
y2 = y+cos(angle)*radius;
glVertex2f(x2,y2);
}
glEnd();
glLoadIdentity();
}

void displayCloud() {

   //glClear(GL_COLOR_BUFFER_BIT);
   //glLoadIdentity();

glTranslatef(0.0f, -0.8f, 0.0f);


drawCircle(0.3f, -0.9f, 0.5f, 0.12,0.25,0.41);
drawCircle(-0.3f, -0.9f, 0.5f, 0.11,0.28,0.41);
drawCircle(-0.9f, -0.9f, 0.5f, 0.11,0.28,0.41);
drawCircle(0.9f, -0.9f, 0.5f, 0.10,0.20,0.38);

drawCircle(-0.8f, -0.75f, 0.28f, 0.17,0.15,0.43);
drawCircle(-0.4f, -0.78f, 0.25f, 0.17,0.15,0.43);
drawCircle(-0.0f, -0.73f, 0.22f, 0.19,0.15,0.43);
drawCircle(0.4f, -0.78f, 0.25f, 0.20,0.15,0.43);
drawCircle(0.8f, -0.75f, 0.28f, 0.20,0.15,0.43);

drawCircle(-0.9f, -1.0f, 0.35f, 0.22,0.20,0.35);
drawCircle(0.32f, -1.13f, 0.38f, 0.22,0.20,0.35);
drawCircle(-0.28f, -1.11f, 0.35f, 0.22,0.20,0.35);
drawCircle(0.9f, -1.0f, 0.34, 0.22,0.20,0.35);

}

