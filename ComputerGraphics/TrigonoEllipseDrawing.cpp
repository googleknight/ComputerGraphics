#include<iostream>
#include<cstdlib>
#include<math.h>
#include"graphics.h"

using namespace std;

void trigoellipse(int rx, int ry, int x, int y);
void plot4(int x,int y,int cx,int cy);
int main()
{
	initwindow(400, 400);
	int rx,ry,x,y;
	cout<<"Enter coordinates for center:";
	cin>>x>>y;
	cout << "Enter radius for x axis and y axis:";
	cin >> rx >> ry;
    trigoellipse(rx,ry,x,y);
	while (!kbhit());
	closegraph();
	return 0;
}
void trigoellipse(int rx, int ry,int cx,int cy)
{
     double theta=90;
     double x=round(rx*cos(theta)),y=round(ry*sin(theta));
     for(;theta>0;theta-=0.05)
     {
          plot4((int)x,(int)y,cx,cy);
          x=round(rx*cos(theta));
          y=round(ry*sin(theta));  
     }
     
}
void plot4(int x,int y,int cx,int cy)
{
     putpixel(x+cx,y+cy,10);
     putpixel(-x+cx,y+cy,10);
     putpixel(x+cx,-y+cy,10);
     putpixel(-x+cx,-y+cy,10);
}
