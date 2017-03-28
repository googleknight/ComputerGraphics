#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<vector>
#include "graphics.h"
using namespace std;
void translatemyobj(vector<vector <int> > shape,int xt,int yt);
int main()
{
	initwindow(800, 800);
    int xorg(0),yorg(0),n,xt(0),yt(0);
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
    printf("Enter trsnslation values of x and y:");
    scanf("%d%d",&xt,&yt);
    system("pause");
    translatemyobj(shape,xt+xorg,yt+yorg);
	while (!kbhit());
	closegraph();
	return 0;
}
void translatemyobj(vector<vector <int> > shape,int xt,int yt)
{
     int n=shape.size();
     moveto(shape[0][0]+xt,shape[0][1]+yt);
     for(int i=0;i<n;i++)
     {
             shape[i][0]+=xt;
             shape[i][1]+=yt;
             lineto(shape[i][0],shape[i][1]);
     }
     lineto(shape[0][0],shape[0][1]);
     
}
