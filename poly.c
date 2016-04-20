#include<GL/glut.h>
myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(-1.0,-1.0);
	glColor3f(0.0,1.0,0.0);
	glVertex2f(-1.0,1.0);
	glColor3f(0.0,0.0,1.0);
	glVertex2f(1.0,1.0);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(1.0,-1.0);
	glEnd();
	glFlush();
}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutCreateWindow("Shaded Polygon");
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}

