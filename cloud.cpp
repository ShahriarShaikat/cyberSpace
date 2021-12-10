
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

drawCircle(0.0f, -0.6f, 0.7f, 0.12,0.20,0.41);
drawCircle(-0.9f, -0.6f, 0.7f, 0.12,0.20,0.41);
drawCircle(0.8f, -0.6f, 0.7f, 0.12,0.20,0.41);
//drawCircle(0.3f, -0.4f, 0.7f, 0.02,0.12,0.15);
//drawCircle(-0.2f, -0.4f, 0.7f, 0.02,0.12,0.15);
//drawCircle(-0.10f, -0.1f, 0.7f, 255,240,245);
//drawCircle(-0.1f, -0.1f, 0.7f, 255,240,245);
}

