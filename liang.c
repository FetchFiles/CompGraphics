#include<stdio.h>

#include<graphics.h>
int liange(int x1,int y1,int x2,int y2)
{       int k,x,y,dx,dy,xmin=200,xmax=450,ymin=200,ymax=450,X1,Y1,X2,Y2;
	float max,min,p[5],q[5],r[5],u1,u2;
	max=0;
	min=1;
	dx=x2-x1;
	dy=y2-y1;
	p[1]=-dx;
	p[2]=dx;
	p[3]=-dy;
	p[4]=dy;
	q[1]=x1-xmin;
	q[2]=xmax-x1;
	q[3]=y1-ymin;
	q[4]=ymax-y1;
	for(k=1;k<=4;k++)
	{if((p[k]==0)&&(q[k]<0))
	{ k=6;
	 return 0;
	}
	}

	for(k=1;k<=4;k++)
	{if(p[k]<0)
	{r[k]=q[k]/p[k];
	if(max<r[k])
	max=r[k];
	}
	else
	{
	r[k]=q[k]/p[k];
	if(min>r[k])
	min=r[k];
	}
	}

	u1=max;
	u2=min;
	if(u1>u2)
	return 0;
	else
	{X1=x1+(u1*dx);
	Y1=y1+(u1*dy);
	X2=x1+(u2*dx);
	Y2=y1+(u2*dy);
	line(X1,Y1,X2,Y2);
	}
	return 0;
}
void main()
{      	int gd=DETECT,gm;
	int i,j,k;
	initgraph(&gd,&gm,"c:\\TC\\BGI");
	
	cleardevice();

	rectangle(200,200,450,450);

	//Algorithm

	line(300,100,400,100);
	line(300,300,400,400);
	line(180,400,350,400);
	getch();
	

	rectangle(200,200,450,450);

	liange(300,100,400,100);
	liange(300,300,400,400);
	liange(180,400,350,400);

	getch();
	closegraph();
}


