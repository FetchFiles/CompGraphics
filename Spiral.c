#include<stdio.h>
#include<graphics.h>


void display(int xc,int yc,int x,int y)
{	
	
	delay(10);
	putpixel(xc+x,yc+y,15);
	putpixel(xc+y,yc+x,15);
	putpixel(xc+x,yc-y+5,15);
	putpixel(xc+y,yc-x+5,15);
	putpixel(xc-x,yc-y,15);
	putpixel(xc-y,yc-x,15);
	putpixel(xc-x,yc+y,15);
	putpixel(xc-y,yc+x,15); 
	y=y-5;	
}


void main()
{
	int gd=DETECT,gm;
	int r,y,xc,yc,x,p;
	printf("Enter the coordinates of centre of circle: \n");
	scanf("%d%d",&xc,&yc);
	printf("Enter the radius of cirlce: \n");
	scanf("%d",&r);
	initgraph(&gd,&gm,"..//bgi");
	while(r>0)
	{
	x=0;
	y=r;
	putpixel(xc,yc,15);
	p=1-r;
	
	while(x<=y)
	{
		if(p<0)
		{
			x++;
			p=p+(2*x)+1;
		}
		else
		{
			x++;
			y--;
			p=p+2*(x-y)+1;
		}			
	display(xc,yc,x,y);
	}
	r=r-5;
	}
	getch();
	cleardevice();
}	

