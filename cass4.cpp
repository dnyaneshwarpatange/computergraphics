#include<iostream>
#include<math.h>
#include<GL/glut.h>
using namespace std;
int choice;
int x1,x2,x3,x4,yy1,y2,y3,y4,nx1,nx2,nx3,nx4,ny1,ny2,ny3,ny4,c,shx,shy;
float sx,sy,xt,yt,r;
double t;
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
glVertex2i(-500,0);
glVertex2i(500,0);
glVertex2i(0,-500);
glVertex2i(0,500);
glEnd();
glColor3f(1.0,1.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(x1,yy1);
glVertex2f(x2,y2);
glVertex2f(x3,y3);
glEnd();
glColor3f(1.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(nx1,ny1);
glVertex2f(nx2,ny2);
glVertex2f(nx3,ny3);
glEnd();
glFlush();
}
void myinit()
{
glClearColor(0.0,0.0,0.0,1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-500.0,500.0,-500.0,500.0);
}
int main(int argc,char **argv)
{
x1=100;
yy1=113;
x2=200;
y2=113;
x3=150;
y3=200;
cout<<"\n1.Translation\n2.Rotation \n3.Scaling \n4.Shear\n5.Exit\nEnter your 
choice:";
cin>>c;
switch(c)
{
case 1:
cout<<"\nEnter the translation factor x:";
cin>>xt;
cout<<"\nEnter the translation factor y:";
cin>>yt;
nx1=x1+xt;
ny1=yy1+yt;
nx2=x2+xt;
ny2=y2+yt;
nx3=x3+xt;
ny3=y3+yt;
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glutCreateWindow("Translation");
glutDisplayFunc(display);
myinit();
glutMainLoop();
break;
case 2:
cout<<"\nEnter the angle of rotation";
cin>>r;
t=3.14*r/180;
nx1=(x1*cos(t)-yy1*sin(t));
ny1=(x1*sin(t)+yy1*cos(t));
nx2=(x2*cos(t)-y2*sin(t));
ny2=(x2*sin(t)+y2*cos(t));
nx3=(x3*cos(t)-y3*sin(t));
ny3=(x3*sin(t)+y3*cos(t));
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glutCreateWindow("Rotation");
glutDisplayFunc(display);
myinit();
glutMainLoop();
break;
case 3:
cout<<"\nEnter the scaling factor x";
cin>>sx;
cout<<"\nEnter the scaling factor y";
cin>>sy;
t=3.14*r/180;
nx1=x1*sx;
ny1=yy1*sy;
nx2=x2*sx;
ny2=y2*sy;
nx3=x3*sx;
ny3=y3*sy;
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glutCreateWindow("Scaling");
glutDisplayFunc(display);
myinit();
glutMainLoop();
break;
case 4:
cout<<"\nEnter the shear factor x";
cin>>shx;
cout<<"\nEnter the shear factor y";
cin>>shy;
nx1=(x1+shx*yy1);
nx2=(x2+shx*y2);
nx3=(x3+shx*y3);
ny1=(yy1+shy*x1);
ny2=(y2+shy*x2);
ny3=(y3+shy*x3);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glutCreateWindow("Shear");
glutDisplayFunc(display);
myinit();
glutMainLoop();
break;
case 5:
break;
default: cout<<"Enter the correct choice:";
}
return 0;
}
