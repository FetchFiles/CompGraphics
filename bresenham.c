#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
int main()
{
	int x1,y1,x2,y2,i;
	float dx,dy,p;
	int gd=DETECT,gm;
	printf("Enter the points : ");
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	initgraph(&gd,&gm,"");
	float l;
	dx=x2-x1;
	dy=y2-y1;
	p=2*dy-dx;
	putpixel(x1,y1,15);
	for(i=x1;i<=x2;i++)
	{
		if(p<0)
		{
			x1++;
			putpixel(x1,y1,15);
			p=p+2*dy;
		}
		else
		{
			x1++;
			y1++;
			putpixel(x1,y1,15);
			p=p+2*(dy-dx);
		}
	}
	getch();
	cleardevice();
	return 0;
}
