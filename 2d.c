#include<stdio.h>
#include<graphics.h>
#include<math.h>
int x[4],y[4];
void display( int x0[], int y0[])
{
 int i;
for(i=0;i<2;i++)
{
line(x0[i],y0[i],x0[i+1],y0[i+1]);
}
line(x0[i],y0[i],x0[0],y0[0]);
getch();
cleardevice();
}
void translation()
{
int i,tx,ty,x0[4],y0[4];
printf("Enter the translation terms\n");
scanf("%d%d",&tx,&ty);
for(i=0;i<3;i++)
{
x0[i]=x[i]+tx;
y0[i]=y[i]+ty;
}
display(x0,y0);
}
void rotation()
{
int i,x0[4],y0[4],vch=2;
float t;
printf("Enter Rotational angle in degrees\n");
scanf("%f",&t);
cleardevice();
t=((t*3.142)/180.0);
for(i=0;i<3;i++)
{
x0[i]=((x[i]-x[vch-1])*cos(t))-((y[i]-y[vch-1])*sin(t))+x[vch-1];
y0[i]=((x[i]-x[vch-1])*sin(t))+((y[i]-y[vch-1])*cos(t))+y[vch-1];
}
display(x0,y0);
}
void scaling()
{
int i,sx,sy,x0[4],y0[4],vch=1;
printf("Enter scaling terms\n");
scanf("%d%d",&sx,&sy);
cleardevice();
for(i=0;i<4;i++)
{
x0[i]=(x[i]-x[vch-1])*sx+x[vch-1];
y0[i]=(y[i]-y[vch-1])*sy+y[vch-1];
}
display(x0,y0);
}
void main()
{
int v=1,i,c;
int gd=DETECT,gm;
initgraph(&gd,&gm,"..//bgi");
printf("Enter the coordinates of traingle\n");
for(i=0;i<3;i++)
{
scanf("%d%d",&x[i],&y[i]);
}
cleardevice();
printf("\n\n\n\nInput diagram");
for(i=0;i<2;i++)
{
line(x[i],y[i],x[i+1],y[i+1]);
}
line(x[i],y[i],x[0],y[0]);
getch();
cleardevice();
do
{
printf("\n1.Translation\n2.Scaling\n3.Rotation\n");
printf("Enter your choice\n");
scanf("%d",&c);
switch(c)
{
case 1: translation();
break;
case 2: scaling();
break;
case 3: rotation();
break;
}
printf("Do you want to continue?\t 1.YES\t2.NO\n");
scanf("%d",&v);
}while(v==1);
}