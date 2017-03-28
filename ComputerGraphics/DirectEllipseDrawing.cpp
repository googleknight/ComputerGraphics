#include<iostream>
#include<cstdlib>
#include<math.h>
#include "graphics.h"
using namespace std;
void directellipse(int a,int b,int cx,int cy);
void plot4(int x,int y,int cx,int cy);
int main()
{
	initwindow(400, 400);
	int a(0),b(0),x(0),y(0);
	cout<<"Enter center co ordinates:";
	cin>>x>>y;
	cout << "Enter a:";
	cin >> a;
	cout << "Enter b:";
	cin >> b;
    directellipse(a,b,x,y);
	while (!kbhit());
	closegraph();
	return 0;
}

void directellipse(int a,int b,int cx,int cy)
{
     double x=0,y=b,c((b*b)/(a*a));
     for(;x*c<y;x++)
     {
               plot4((int)x,(int)y,cx,cy);
               y=round(b*sqrt(1.0-((x*x)/(a*a))));
     }
     for(x=a,y=0;x*c>y;y++)
     {
               plot4((int)x,(int)y,cx,cy);
               x=round(a*sqrt(1.0-((y*y)/(b*b))));
     }
 
}
void plot4(int x,int y,int cx,int cy)
{
     putpixel(x+cx,y+cy,10);
     putpixel(-x+cx,y+cy,10);
     putpixel(-x+cx,-y+cy,10);     
     putpixel(x+cx,-y+cy,10);  
}

