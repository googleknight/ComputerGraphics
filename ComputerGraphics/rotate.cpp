#include<iostream>
#include<cstdlib>
#include<vector>
#include "graphics.h"
#include<math.h>
using namespace std;
void rotatemyobj(vector<vector <int> > shape,double theta,int xorg,int yorg);
int main()
{
	initwindow(800, 800);
    int xorg(0),yorg(0),n;
    double theta(0);
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
    moveto(shape[0][0]+xorg,shape[0][1]+yorg);
    for(int i=0;i<n;i++)
         lineto(shape[i][0]+xorg,shape[i][1]+yorg);  
    lineto(shape[0][0]+xorg,shape[0][1]+yorg);
    printf("Enter rotation angle:");
    scanf("%lf",&theta);
    system("pause");
    rotatemyobj(shape,theta,xorg,yorg);
	while (!kbhit());
	closegraph();
	return 0;
}
void rotatemyobj(vector<vector <int> > shape,double theta,int xorg,int yorg)
{
     int n=shape.size();
     double xrt=(shape[0][0]*cos(theta))-(shape[0][1]*sin(theta)) ;
     double yrt=(shape[0][1]*cos(theta))+(shape[0][0]*sin(theta));
     moveto((int)xrt+xorg,(int)yrt+yorg);
     for(int i=0;i<n;i++)
     {
             xrt=(shape[i][0]*cos(theta))-(shape[i][1]*sin(theta));
             yrt=(shape[i][1]*cos(theta))+(shape[i][0]*sin(theta));
             shape[i][0]=(int)xrt;
             shape[i][1]=(int)yrt;
             lineto(shape[i][0]+xorg,shape[i][1]+yorg);
     }
     lineto(shape[0][0]+xorg,shape[0][1]+yorg);
}
