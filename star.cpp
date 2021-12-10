void displayStar() {

   glLoadIdentity();

    glTranslatef(0.5f, 0.6f, 0.0f);
    glBegin (GL_POLYGON);
        glColor3f(0.97, 1, 0.63);
        glVertex2f(0.0f,0.2f);
        glVertex2f(0.1f,0.1f);
        glVertex2f(0.2f,0.05f);
        glVertex2f(0.1f,0.0f);
        glVertex2f(0.2f,-0.1f);
        glVertex2f(0.0f,0.0f);
        glVertex2f(-0.2f,-0.1f);
        glVertex2f(-0.1f,0.0f);
        glVertex2f(-0.2f,0.05f);
        glVertex2f(-0.1f,0.1f);
        glEnd();

    glLoadIdentity();

    glTranslatef(0.0f, 0.8f, 0.0f);
    glBegin (GL_POLYGON);
        glVertex2f(0.0f,0.2f);
        glVertex2f(0.1f,0.1f);
        glVertex2f(0.2f,0.05f);
        glVertex2f(0.1f,0.0f);
        glVertex2f(0.2f,-0.1f);
        glVertex2f(0.0f,0.0f);
        glVertex2f(-0.2f,-0.1f);
        glVertex2f(-0.1f,0.0f);
        glVertex2f(-0.2f,0.05f);
        glVertex2f(-0.1f,0.1f);
        glEnd();

    glLoadIdentity();

    glTranslatef(0.5f, 0.1f, 0.0f);
    glBegin (GL_POLYGON);
        glVertex2f(0.0f,0.2f);
        glVertex2f(0.1f,0.1f);
        glVertex2f(0.2f,0.05f);
        glVertex2f(0.1f,0.0f);
        glVertex2f(0.2f,-0.1f);
        glVertex2f(0.0f,0.0f);
        glVertex2f(-0.2f,-0.1f);
        glVertex2f(-0.1f,0.0f);
        glVertex2f(-0.2f,0.05f);
        glVertex2f(-0.1f,0.1f);
        glEnd();

    glLoadIdentity();

    glTranslatef(-0.6f, 0.6f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.0f,0.2f);
        glVertex2f(0.1f,0.1f);
        glVertex2f(0.2f,0.05f);
        glVertex2f(0.1f,0.0f);
        glVertex2f(0.2f,-0.1f);
        glVertex2f(0.0f,0.0f);
        glVertex2f(-0.2f,-0.1f);
        glVertex2f(-0.1f,0.0f);
        glVertex2f(-0.2f,0.05f);
        glVertex2f(-0.1f,0.1f);
        glEnd();

    glLoadIdentity();

    glTranslatef(-0.5f, 0.1f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.0f,0.2f);
        glVertex2f(0.1f,0.1f);
        glVertex2f(0.2f,0.05f);
        glVertex2f(0.1f,0.0f);
        glVertex2f(0.2f,-0.1f);
        glVertex2f(0.0f,0.0f);
        glVertex2f(-0.2f,-0.1f);
        glVertex2f(-0.1f,0.0f);
        glVertex2f(-0.2f,0.05f);
        glVertex2f(-0.1f,0.1f);
        glEnd();

   glLoadIdentity();
}
