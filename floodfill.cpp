#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <iostream>
using namespace std;

int count = 0;

void flood(int x, int y, int fillColor, int defaultColor, int &count)
{
    count += 1;
    if (getpixel(x, y) == defaultColor)
    {
        // delay(1);
        putpixel(x, y, fillColor);
        flood(x + 1, y, fillColor, defaultColor, count);
        flood(x - 1, y, fillColor, defaultColor, count);
        flood(x, y + 1, fillColor, defaultColor, count);
        flood(x, y - 1, fillColor, defaultColor, count);
        flood(x + 1, y + 1, fillColor, defaultColor, count);
        flood(x - 1, y - 1, fillColor, defaultColor, count);
        flood(x - 1, y + 1, fillColor, defaultColor, count);
        flood(x + 1, y - 1, fillColor, defaultColor, count);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:/TURBOC3/bgi");
    int count = 0;
    rectangle(50, 50, 250, 250);
    flood(55, 55, 10, 0, count);
    cout << count << endl;
    getch();
    closegraph();
    return 0;
}
