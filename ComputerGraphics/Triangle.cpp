#include<iostream>
#include"graphics.h"
#include"Header.h"
using namespace std;
int main()
{
	initwindow(1000, 600);
	//Hexagon
	dda(200, 200, 300, 200);//top
	dda(300, 200, 360, 260);//topright
	dda(360, 260, 300, 320);//bottomright
	dda(300, 320, 200, 320);//bottom
	dda(200, 320, 140, 260);//bottomleft
	dda(140, 260, 200,200);//bottomleft
	//Triangle
	dda(500, 320, 600, 220);//left
	dda(600, 220, 700, 320);//right
	dda(500, 320, 700, 320);//bottom
	bresenhamcircle(90, 100, 100);
	
	while (!kbhit());
	closegraph();
	return 0;
}