#include<iostream>
#include<cstdlib>
#include<math.h>
#include "graphics.h"
using namespace std;
void trigonocircle(int r,int x,int y,int color);
void plot8(int x,int y,int cx,int cy,int color);
void boundaryfill(int x,int y,int color,int bordercolor);
int main()
{
	initwindow(500, 500);
	int r(0),x(0),y(0),color(0),bc(0);
	cout<<"Enter center co ordinates:";
	cin>>x>>y;
	cout << "Enter radius:";
	cin >> r;
	cout << "Enter circle boundary color:";
	cin >> bc;
    trigonocircle(r,x,y,bc);
	cout<<"Enter circle color:";
    cin>>color;
    boundaryfill(x,y,color,bc);
	while (!kbhit());
	closegraph();
	return 0;
}
void trigonocircle(int r,int cx,int cy,int bc)
{
     double theta(90);
     double x(round(r*cos(theta))),y(round(r*sin(theta)));
     for(;theta>45;theta-=0.05)
     {
          plot8((int)x,(int)y,cx,cy,bc);
          x=round(r*cos(theta));
          y=round(r*sin(theta));  
     }
     
}
void plot8(int x,int y,int cx,int cy,int color)
{
     putpixel(x+cx,y+cy,color);
     putpixel(-x+cx,y+cy,color);
     putpixel(-x+cx,-y+cy,color);     
     putpixel(x+cx,-y+cy,color);  
     putpixel(y+cx,x+cy,color);
     putpixel(y+cx,-x+cy,color);
     putpixel(-y+cx,-x+cy,color);     
     putpixel(-y+cx,x+cy,color);      
}
void boundaryfill(int x,int y,int color,int bordercolor)
{
     int region=getpixel(x,y);
     if(region!=color && region!= bordercolor)
     {
          putpixel(x,y,color);
          boundaryfill(x+1,y,color,bordercolor);
          boundaryfill(x-1,y,color,bordercolor);
          boundaryfill(x,y+1,color,bordercolor);
          boundaryfill(x,y-1,color,bordercolor);
    }  
}