 #include<iostream>
#include<cstdlib>
#include "graphics.h"
using namespace std;
void midpointellipse(double rx,double ry,double x,double y);
void plot4(int x,int y,int cx,int cy);
int main()
{
    initwindow(400, 400);
	double rx,ry,cx,cy;
	cout<<"Enter coordinates for center:";
	cin>>cx>>cy;
	cout << "Enter radius for x axis and y axis:";
	cin >> rx >> ry;
    midpointellipse(rx,ry,cx,cy);
	while (!kbhit());
	closegraph();
	return 0;
}
void midpointellipse(double rx,double ry,double cx,double cy)
{
     //Region 1
     double x(0),y(ry);
     plot4((int)x,(int)y,(int)cx,(int)cy);
     double p=(ry*ry)-rx*rx*ry+(0.25)*rx*rx;
     do
     {
            if(p>0)
              y--;
            x++;
            plot4((int)x,(int)y,(int)cx,(int)cy);
            p=(ry*ry*x*x)+(rx*rx*y*y)-(rx*rx*ry*ry);
     }while((ry*ry*x)<=(rx*rx*y));
     //Region 2
     do
     {
            if(p<0)
                x++;
            y--;     
            plot4((int)x,(int)y,(int)cx,(int)cy);
            p=(ry*ry*x*x)+(rx*rx*y*y)-(rx*rx*ry*ry);
     }while(y>=0);
}
void plot4(int x,int y,int cx,int cy)
{
     putpixel(x+cx,y+cy,10);
     putpixel(-x+cx,y+cy,10);
     putpixel(x+cx,-y+cy,10);
     putpixel(-x+cx,-y+cy,10);
}
