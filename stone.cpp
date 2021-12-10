void drawStone(double x,double y,double radious,float r,float g,float b) {
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

void displayStone() {

glTranslatef(0.0f, -0.8f, 0.0f);

drawStone(0.70f, 0.60f, 0.25f, 0.33,0.34,0.32);
drawStone(-0.70f, -0.1f, 0.25f, 0.33,0.34,0.32);

}

