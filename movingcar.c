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
	int i=0,x,y,fcolor,bcolor=15;
	int gd=DETECT,gm;
	initgraph(&gd, &gm,"");
	cleardevice();
	while(i<300)
	{
		line(50,400,600,400);
		//Car
		setcolor(RED);
		line(50+i,390,70+i,390);
		line(90+i,390,120+i,390);
		line(140+i,390,165+i,390);
		line(165+i,390,165+i,375);
		line(165+i,375,140+i,365);
		line(140+i,365,120+i,335);
		line(120+i,335,130+i,365);
		line(130+i,365,80+i,365);
		line(80+i,365,90+i,337);
		line(90+i,337,85+i,335);
		line(85+i,335,65+i,365);
		line(65+i,365,50+i,375);
		line(50+i,375,50+i,390);
		setcolor(WHITE);
		circle(80+i,390,10);
		circle(130+i,390,10);
		//Signal
		line(560,300,560,400);
		rectangle(550,300,570,250);
		if(i>=0 && i<200)
		{
			circle(560,290,5);
			boundary_fill(560,290,2,15);
			i=i+4;
		}
		else if(i>=200 && i<=295)
		{
			circle(560,275,5);
			boundary_fill(560,275,14,15);
			i=i+2;
		}
		else
		{
			circle(560,260,5);
			boundary_fill(560,260,4,15);
			delay(1000);
		}
		delay(50);
		cleardevice();
	}
	
	getch();
}
