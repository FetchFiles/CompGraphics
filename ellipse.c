#include<stdio.h>
#include<graphics.h>

void main()
{
	int xc,yc,a,b,rx,ry,x,y;
	long dx,dy,p1,p2,rxsq,rysq,tworxsq,tworysq;
	int gd=DETECT,gm;
	printf("\n Enter The Co-Ordinate Of Center ");
	scanf("%d%d",&xc,&yc);
	printf("\n Enter The Value of X Radius ");
	scanf("%d",&rx);
	printf("\n Enter The Value of Y Radius ");
	scanf("%d",&ry);
	initgraph(&gd,&gm,"..//bgi");
	rxsq=rx*rx;
	rysq=ry*ry;
	tworxsq=2*rxsq;
	tworysq=2*rysq;
	x=0;
	y=ry;
	dx=tworxsq*x;
	dy=tworxsq*y;
	p1=rysq+0.25*rxsq-rxsq*ry;
	do
	{
	delay(100);
	putpixel(xc+x,yc+y,15);
	putpixel(xc+x,yc-y,15);
	putpixel(xc-x,yc+y,15);
	putpixel(xc-x,yc-y,15);
	x++;
	if(p1<0)
	{
		dx=dx+tworysq;
		p1=p1+rysq+dx;
	}
	else
	{
		y--;
		dy=dy-tworxsq;
		dx=dx+tworysq;
		p1=p1+rysq+dx-dy;

	}
	delay(100);
	}
	while(dx<dy);
	p2=rysq*(x+0.5)*(x+0.5)+rxsq*(y-1)*(y-1)-rxsq*rysq;
	do
	{
	delay(100);
	putpixel(xc+x,yc+y,15);
	putpixel(xc+x,yc-y,15);
	putpixel(xc-x,yc+y,15);
	putpixel(xc-x,yc-y,15);
	y--;
	if(p2>0)
	{
		dy=dy-tworxsq;
		p2=p2+rxsq-dy;
	}
	else
	{
		x++;
		dx=dx+tworysq;
		dy=dy-tworxsq;
		p2=p2+rxsq+dx-dy;
	}
	delay(100);
	}
	while(y>=0);
	getch();
}

