#include<iostream>
#include"graphics.h"
using namespace std;
void mid(int x1, int y1, int x2, int y2);
void floodfill(int x, int y, int color, int backcolor)
{
	int region = getpixel(x, y);
	if (region == backcolor)
	{
		putpixel(x, y, color);
		floodfill(x + 1, y, color, backcolor);
		floodfill(x - 1, y, color, backcolor);
		floodfill(x, y + 1, color, backcolor);
		floodfill(x, y - 1, color, backcolor);
	}
}
int main()
{
	initwindow(800, 800);
	int x1, y1, x2, y2;
	mid(500, 320, 600, 220);//left
	mid(600, 220, 700, 320);//right
	mid(500, 320, 700, 320);//bottom
	//floodfill(550, 310, 10, 0);
	while (!kbhit());
	closegraph();
	return 0;
}
void mid(int x1, int y1, int x2, int y2)
{
	double dx = x2 - x1, dy = y2 - y1;
	putpixel(x1, y1, 3);
	putpixel(x2, y2, 3);
	if (abs(dy / dx) < 1)
	{
		double d =  dy - dx/2;
		int x = x1>x2 ? x2 : x1;
		int y = x1>x2 ? y2 : y1;
		int inc;
		if ((dy / dx) < 0)
			inc = -1;
		else
			inc = 1;
		dx = abs(dx);
		dy = abs(dy);
		for (int i = 0; i <= dx; i++, x++)
		{

			if (d < 0)
			{
				putpixel(x + 1, y, 3);
				d = d + dy;
			}
			else
			{
				putpixel(x + 1, y + inc, 3);
				y += inc;
				d = d +  (dy - dx);
			}
		}
	}
	else
	{
		double d =  dx - dy/2;
		int x = y1>y2 ? x2 : x1;
		int y = y1>y2 ? y2 : y1;
		int inc;
		if ((dy / dx) < 0)
			inc = -1;
		else
			inc = 1;
		dx = abs(dx);
		dy = abs(dy);
		for (int i = 0; i <= dy; i++, y++)
		{
			if (d < 0)
			{
				putpixel(x, y + 1, 3);
				d = d + dx;
			}
			else
			{
				putpixel(x + inc, y + 1, 3);
				x += inc;
				d = d +  (dx - dy);
			}
		}
	}
}
