	
#include<iostream>
#include<cstdlib>
#include "graphics.h"
using namespace std;
int sign(float x);
void bres(int x1, int y1, int x2, int y2);
int main()
{
	initwindow(400, 400);
	int x1, y1, x2, y2;
	cout << "Enter initial point:";
	cin >> x1 >> y1;
	cout << "Enter final point:";
	cin >> x2 >> y2;
	bres(x1, y1, x2, y2);
	while (!kbhit());
	closegraph();
	return 0;
}
void bres(int x1, int y1, int x2, int y2)
{
	double dx = (x2 - x1);
	double dy = (y2 - y1);
	int x=x1, y=y1,i;
	if ((dy / dx) < 0)
		i = -1;
	else
		i = 1;
	dx = abs(dx);
	dy = abs(dy);
	int p = 2 * dy - dx;
	if (x1>x2)
	{
		putpixel(x2, y2, 10);
		x = x2;
		y = y2;
	}
	else
	{
		putpixel(x1, y1, 10);
		x = x1;
		y = y1;
	}	
	cout << x << endl << y << endl;
	if(dx>=dy)
		for (int k = 0; k<dx; k++,x++)
		{
			if (p<0)
			{
				putpixel(x + 1, y, 10);
				p = p + (2 * dy);
			}
			else
			{
				putpixel(x + 1, y + i, 10);
				y+=i;
				p = p + (2 * dy) - (2 * dx);
			}
		}
	else
		for (int k = 0; k<dy; k++,y++)
		{
			if (p<0)
			{
				putpixel(x , y+1, 10);
				p = p + (2 * dx);
			}
			else
			{
				putpixel(x + i, y + 1, 10);
				x+=i;
				p = p + (2 * dx) - (2 * dy);
			}
		}

}