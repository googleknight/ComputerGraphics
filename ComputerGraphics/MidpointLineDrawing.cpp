#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include "graphics.h"
using namespace std;
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
	int dx = x2 - x1;
	int dy = y2 - y1;
	putpixel(x1, y1, 10);
	int f = dy- dx/2;
	for (int k = 0, x = x1, y = y1; k<dx; k++, y++, x++)
	{
		if (f<0)
		{
			putpixel(x + 1, y, 10);
			f = f + dy;
		}
		else
		{
			putpixel(x + 1, y + 1, 10);
			f = f + dy-dx;
		}
	}
}