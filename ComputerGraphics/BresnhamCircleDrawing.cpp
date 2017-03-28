#include<iostream>
#include<cstdlib>
#include "graphics.h"
using namespace std;
void bresenhamcircle(int r,int x,int y);
void plot8(int x,int y,int cx,int cy);
int main()
{
	initwindow(400, 400);
	int r(0),x(0),y(0);
	cout<<"Enter center co ordinates:";
	cin>>x>>y;
	cout << "Enter radius:";
	cin >> r;
	bresenhamcircle(r,x,y);
	while (!kbhit());
	closegraph();
	return 0;
}
void bresenhamcircle(int r,int cx,int cy)
{
     int x(0),y(r);
     double di=3-2*r;
     do
     {
               plot8(x,y,cx,cy);
               if(di<0)
                   di=di+(4*x)+6;
               else
               {
                   di=di+4*(x-y)+10;                   
                   y--;
               }
               x++;
     }while(x<=y);
     
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
