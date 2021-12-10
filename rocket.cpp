void rocketShow(GLfloat r_posX)
{
   //Rocket bottom
   glTranslatef(r_posX, -0.9f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 0.0f);
      glVertex2f(-0.04f, 0.0f);
      glVertex2f(0.04f, 0.06f);
      glVertex2f(0.04f, 0.0f);
      glVertex2f(-0.04f, 0.06f);
   glEnd();
   //Rocket bottom square
   glLoadIdentity();
   glTranslatef(r_posX, -0.83f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.05f, 0.0f);
      glVertex2f(0.05f, 0.0f);
      glVertex2f(0.05f, 0.15f);
      glVertex2f(-0.05f, 0.15f);
   glEnd();
   //Rocket bottom propaler left
   glLoadIdentity();
   glTranslatef(r_posX, -0.83f, 0.0f);
   glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-0.05f, 0.0f);
      glVertex2f(-0.05f, 0.15f);
      glVertex2f(-0.11f, -0.01f);
   glEnd();
   //Rocket bottom propaler right
   glLoadIdentity();
   glTranslatef(r_posX, -0.83f, 0.0f);
   glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(0.05f, 0.0f);
      glVertex2f(0.05f, 0.15f);
      glVertex2f(0.11f, -0.01f);
   glEnd();
   //Rocket Upper square
   glLoadIdentity();
   glTranslatef(r_posX, -0.67f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.05f, 0.0f);
      glVertex2f(0.05f, 0.0f);
      glVertex2f(0.05f, 0.18f);
      glVertex2f(-0.05f, 0.18f);
   glEnd();
   //Rocket Upper square
   glLoadIdentity();
   glTranslatef(r_posX, -0.67f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.0f, 0.0f, 1.0f);
      glVertex2f(-0.02f, 0.05f);
      glVertex2f(0.02f, 0.05f);
      glVertex2f(0.02f, 0.12f);
      glVertex2f(-0.02f, 0.12f);
   glEnd();
   //Rocket Upper Triangle
   glLoadIdentity();
   glTranslatef(r_posX, -0.49f, 0.0f);
   glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-0.066f, 0.0f);
      glVertex2f(0.066f, 0.0f);
      glVertex2f(0.0f, 0.10f);
   glEnd();
   glLoadIdentity();
}
