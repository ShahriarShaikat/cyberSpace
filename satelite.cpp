void drawAntena(double x,double y,double radious,float r,float g,float b) {
    float x2,y2;
    float angle;
    double radius=radious;
    glBegin(GL_POLYGON);
    glColor3f(r, g, b);
    glVertex2f(x,y);

    for (angle=1.56f;angle<4.760f;angle+=0.1)
    {
        x2 = x+sin(angle)*radius;
        y2 = y+cos(angle)*radius;
        glVertex2f(x2,y2);
    }
    glEnd();
}


void drawAntenaBall(double x,double y,double radious,float r,float g,float b) {
    float x2,y2;
    float angle;
    double radius=radious;
    glBegin(GL_POLYGON);
    glColor3f(r, g, b);
    glVertex2f(x,y);

    for (angle=1.56f;angle<361.00f;angle+=0.2)
    {
        x2 = x+sin(angle)*radius;
        y2 = y+cos(angle)*radius;
        glVertex2f(x2,y2);
    }
    glEnd();
}


void displaySatelite(GLfloat satMove, GLfloat satMoveY) {

    float angle =5.0;


   glLoadIdentity();
   glTranslatef(-0.048f + satMove, 0.0f + satMoveY, 0.0f);

    //Middle Body
    glBegin (GL_QUADS);
        glColor3f(0.74, 0.76, 0.78);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.1, 0.0);
        glVertex2f(0.1, 0.2);
        glVertex2f(0.0, 0.2);
    glEnd();

    // AntenaBall
    glLoadIdentity();
    glTranslatef(0.0f + satMove, 0.33f + satMoveY, 0.0f);
    drawAntenaBall(0.0, 0.0, 0.03, 0.90, 0.29, 0.23);


    // Antena
    glLoadIdentity();
    glTranslatef(0.001f + satMove, 0.3f + satMoveY, 0.0f);
    drawAntena(0.0, 0.0, 0.1, 0.92, 0.94, 0.94);

    //Fan right
    glLoadIdentity();
    glTranslatef(0.05f + satMove, 0.05f + satMoveY, 0.0f);
    glBegin (GL_QUADS);
        glColor3f(0.20, 0.59, 0.85);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.2, 0.0);
        glVertex2f(0.2, 0.1);
        glVertex2f(0.0, 0.1);
    glEnd();

    //Fan left
    glLoadIdentity();
    glTranslatef(-0.248f + satMove, 0.05f + satMoveY, 0.0f);
    glBegin (GL_QUADS);
                glColor3f(0.20, 0.59, 0.85);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.2, 0.0);
        glVertex2f(0.2, 0.1);
        glVertex2f(0.0, 0.1);
    glEnd();


    //Fan Solar Pannels
    glLoadIdentity();
    glTranslatef(-0.248f + satMove, 0.07f + satMoveY, 0.0f);
    glBegin (GL_QUADS);
        glColor3f(0.92, 0.94, 0.94);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.04, 0.0);
        glVertex2f(0.04, 0.05);
        glVertex2f(0.0, 0.05);
    glEnd();

    glLoadIdentity();
    glTranslatef(-0.190f + satMove, 0.07f + satMoveY, 0.0f);
    glBegin (GL_QUADS);
        glColor3f(0.92, 0.94, 0.94);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.04, 0.0);
        glVertex2f(0.04, 0.05);
        glVertex2f(0.0, 0.05);
    glEnd();

    glLoadIdentity();
    glTranslatef(-0.132f + satMove, 0.07f + satMoveY, 0.0f);
    glBegin (GL_QUADS);
        glColor3f(0.92, 0.94, 0.94);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.04, 0.0);
        glVertex2f(0.04, 0.05);
        glVertex2f(0.0, 0.05);
    glEnd();

    // Right


    glLoadIdentity();
    glTranslatef(0.210f + satMove, 0.07f + satMoveY, 0.0f);
    glBegin (GL_QUADS);
        glColor3f(0.92, 0.94, 0.94);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.04, 0.0);
        glVertex2f(0.04, 0.05);
        glVertex2f(0.0, 0.05);
    glEnd();

    glLoadIdentity();
    glTranslatef(0.155f + satMove, 0.07f + satMoveY, 0.0f);
    glBegin (GL_QUADS);
        glColor3f(0.92, 0.94, 0.94);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.04, 0.0);
        glVertex2f(0.04, 0.05);
        glVertex2f(0.0, 0.05);
    glEnd();

    glLoadIdentity();
    glTranslatef(0.100f + satMove, 0.07f + satMoveY, 0.0f);
    glBegin (GL_QUADS);
        glColor3f(0.92, 0.94, 0.94);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.04, 0.0);
        glVertex2f(0.04, 0.05);
        glVertex2f(0.0, 0.05);
    glEnd();

   glLoadIdentity();
}
