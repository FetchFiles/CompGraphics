#include<stdio.h>
#include<graphics.h> 
 #include <X11/Xlib.h>
void main()
{
	int gd=DETECT,gm=DETECT;
	float x1,y1,x2,y2,m,dx,dy,i;
	printf("\nEnter the x Co-ordinate of 1st point: ");
	scanf("%f",&x1);
	printf("\nEnter the y Co-ordinate of 1st point: ");
	scanf("%f",&y1);
	printf("\nEnter the x Co-ordinate of 2nd point: ");
	scanf("%f",&x2);
	printf("\nEnter the y Co-ordinate of 2nd point: ");
	scanf("%f",&y2);
	dx=x2-x1;
	dy=y2-y1;
	m=dy/dx;
	initgraph(&gd,&gm,"..//bgi");
	cleardevice();
	if(dx>dy)
	{
		for(i=x1;i<=x2;i++)
		{
			x1++;
			y1=y1+m;
			putpixel(x1,y1,15);
			delay(5);
		}
	}
	else
	{
		for(i=y1;i<=y2;i++)
		{
			y1++;
			x1=x1+(1/m);
			putpixel(x1,y1,15);
			delay(5);
		}
	}
	
	closegraph();	
	getch();
}
