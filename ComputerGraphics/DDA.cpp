#include<iostream>
#include<cstdlib>
#include "graphics.h"
using namespace std;
int sign(float x);
void dda(int x1, int y1, int x2, int y2);
int main()
{
	initwindow(400, 400);
	int x1, y1, x2, y2;
	cout << "Enter initial point:";
	cin >> x1 >> y1;
	cout << "Enter final point:";
	cin >> x2 >> y2;
	dda(x1, y1, x2, y2);
	while (!kbhit());
	closegraph();
	return 0;
}
int sign(float x)
{
	if (x>0)
		return 1;
	else if (x<0)
		return -1;
	else
		return 0;
}
void dda(int x1, int y1, int x2, int y2)
{
	int dx, dy;
	double x, y, length, newdx, newdy;
	dx = x2 - x1;
	dy = y2 - y1;
	length = abs(dx) >= abs(dy) ? abs(dx) : abs(dy);
	newdx = dx / length;
	newdy = dy / length;
	x = x1 + .5*sign(newdx);
	y = y1 + .5*sign(newdy);
	for (int i = 1; i <= length; i++)
	{
		putpixel(x, y, 2);
		x += newdx;
		y += newdy;
	}
}