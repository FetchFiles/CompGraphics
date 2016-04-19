#include<stdio.h>
#include<graphics.h>

void boundary_fill(int x,int y,int fcolor,int bcolor)
{
	if ((getpixel(x,y)!=fcolor) && (getpixel(x,y)!=bcolor))
	{
		putpixel(x, y, fcolor);
		boundary_fill(x+1,y,fcolor,bcolor);
		boundary_fill(x-1,y,fcolor,bcolor);
		boundary_fill(x,y-1,fcolor,bcolor);
		boundary_fill(x,y+1,fcolor,bcolor);
	}
}


void main()
{
	int x,y,fcolor,bcolor=15;
	int gd = DETECT,gm;
	initgraph(&gd, &gm,"");
	cleardevice();
	line(100,200,500,200);
	line(100,200,50,250);
	line(50,250,150,250);
	line(100,200,150,250);
	line(150,250,550,250);
	line(500,200,550,250);
	rectangle(50,250,150,400);
	rectangle(150,250,550,400);
	circle(100,225,5);
	rectangle(350,300,400,400);
	boundary_fill(60,260,1,15);
	boundary_fill(160,260,12,15);
	boundary_fill(101,226,13,15);
	boundary_fill(360,320,9,15);
	boundary_fill(150,210,3,15);
	boundary_fill(80,230,14,15);
	getch();
}
