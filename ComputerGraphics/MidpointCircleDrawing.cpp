#include<iostream>
#include<cstdlib>
#include "graphics.h"
using namespace std;
void midpointcircle(int r,int x,int y);
void plot8(int x,int y,int cx,int cy);
int main()
{
	initwindow(400, 400);
	int r(0),x(0),y(0);
	cout<<"Enter center co ordinates:";
	cin>>x>>y;
	cout << "Enter radius:";
	cin >> r;
	midpointcircle(r,x,y);
	while (!kbhit());
	closegraph();
	return 0;
}
void midpointcircle(int r,int cx,int cy)
{
     int x(0),y(r);
     double di=1.25-r;
     for(;x<y;)
     {
               plot8(x,y,cx,cy);
               if(di<0)
               {
                   x++;
                   di=di+(2*x)+2;
               }
               else
               {
                   x++;
                   y--;
                   di=di+(2*x)-(2*y)+1;                   
               }
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
