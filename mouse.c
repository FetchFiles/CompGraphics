#include <GL/glut.h>
#include <math.h>
void draw()
{
	int r=10;
	GLfloat theta;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	for (int theta = 0; theta <=360 ; theta+=0.01)
	{
		glVertex2f(10*sin(theta*(3.142/180)),4*cos(theta*(3.142/180)));
	}
	glEnd();
	glFlush();
}
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
	GLfloat vertices[3][2]={{0.0,0.0},{25.0,50.0},{50.0,0.0}};
	int j,k;
	GLfloat p[2]={7.5,5.0};
	
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	for (int k = 0; k <=5000; k++)
	{
		j=rand()%3;
		p[0]=(p[0]+vertices[j][0])/2.0;
		p[1]=(p[1]+vertices[j][1])/2.0;
		glVertex2fv(p);
	}
	glEnd();
	glFlush();
}
void myMouse(int button,int state,int x,int y)
{
	if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		draw();
	}
	if (button==GLUT_RIGHT_BUTTON && state==GLUT_UP)
	{
		display();
	}
}
void main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Sierpinsky Gasket");
	glutMouseFunc(myMouse);
	myinit();
	glutMainLoop();
}
