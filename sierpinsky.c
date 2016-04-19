#include<GL/glut.h>

void myinit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10.0,10.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
}

void display(void)
{
	GLfloat vertices[3][2]={{1.0,1.0},{6.0,1.0},{3.5,5.5}};
	int j,k;
	int rand();
	GLfloat p[2]={2.5,2.5};
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	for(k=0;k<500000000;k++)
	{
		j=rand()%3;
		p[0]=(p[0]+vertices[j][0])/2.0;
		p[1]=(p[1]+vertices[j][1])/2.0;
		glVertex2fv(p);
	}
	glEnd();
	glFlush();
}


int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("SERPINSKY GASKET");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}
 
