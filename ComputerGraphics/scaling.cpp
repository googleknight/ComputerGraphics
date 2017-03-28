#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<vector>
#include "graphics.h"
using namespace std;
void scalemyobj(vector<vector <int> > shape,double xt,double yt,int xorg,int yorg);
int main()
{
	initwindow(800, 800);
    int xorg(0),yorg(0),n;
    double xt(0),yt(0);
    vector<vector <int> > shape;
    printf("Enter origin:");
    scanf("%d%d",&xorg,&yorg);
    printf("Enter total number of points in shape:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
            vector<int> myvec;
            int tempx,tempy;
            printf("Point %d:",i);
            scanf("%d%d",&tempx,&tempy);
            myvec.push_back(tempx);
            myvec.push_back(tempy);
            shape.push_back(myvec);
     }
    moveto(xorg+shape[0][0],yorg+shape[0][1]);
    for(int i=0;i<n;i++)
         lineto(shape[i][0]+xorg,shape[i][1]+yorg);  
    lineto(shape[0][0]+xorg,shape[0][1]+yorg);
    printf("Enter scaling values of x and y:");
    scanf("%lf%lf",&xt,&yt);
    system("pause");
    scalemyobj(shape,xt,yt,xorg,yorg);
	while (!kbhit());
	closegraph();
	return 0;
}
void scalemyobj(vector<vector <int> > shape,double xt,double yt,int xorg,int yorg)
{
     int n=shape.size();
     moveto((shape[0][0]*xt)+xorg,(shape[0][1]*yt)+yorg);
     for(int i=0;i<n;i++)
     {
             shape[i][0]*=xt;
             shape[i][1]*=yt;
             lineto(shape[i][0]+xorg,shape[i][1]+yorg);
     }
     lineto(shape[0][0]+xorg,shape[0][1]+yorg);     
}
