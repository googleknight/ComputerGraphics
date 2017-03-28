#include<iostream>
#include<cstdlib>
#include<math.h>
#include "graphics.h"
using namespace std;
void trigonocircle(int r,int x,int y);
void plot8(int x,int y,int cx,int cy);
int main()
{
	initwindow(400, 400);
	int r(0),x(0),y(0);
	cout<<"Enter center co ordinates:";
	cin>>x>>y;
	cout << "Enter radius:";
	cin >> r;
    trigonocircle(r,x,y);
	while (!kbhit());
	closegraph();
	return 0;
}
void trigonocircle(int r,int cx,int cy)
{
     double theta(90);
     double x(round(r*cos(theta))),y(round(r*sin(theta)));
     for(;theta>45;theta-=0.05)
     {
          plot8((int)x,(int)y,cx,cy);
          x=round(r*cos(theta));
          y=round(r*sin(theta));  
     }
     
}
void plot8(int x,int y,int cx,int cy)
{
     putpixel(x+cx,y+cy,10);
     putpixel(-x+cx,y+cy,10);
     putpixel(-x+cx,-y+cy,10);     
     putpixel(x+cx,-y+cy,10);  
     putpixel(y+cx,x+cy,10);
     putpixel(y+cx,-x+cy,10);
     putpixel(-y+cx,-x+cy,10);     
     putpixel(-y+cx,x+cy,10);      
}

