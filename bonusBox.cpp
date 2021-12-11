void displayBonusBox() {

   glLoadIdentity();

   glTranslatef(0.0f, 0.9f, 0.0f);
   glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.06f, 0.06f);
        glVertex2f(0.06f,0.06f);
        glVertex2f(0.06f,-0.06f);
        glVertex2f(-0.06f,-0.06f);
    glEnd();
    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.04f, 0.0f);
        glVertex2f(0.04f, 0.0f);
    glEnd();
        glBegin(GL_LINES);
        glVertex2f(0.0f, -0.04f);
        glVertex2f(0.0f, 0.04f);
    glEnd();
    glLoadIdentity();
}
