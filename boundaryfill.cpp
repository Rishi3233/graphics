#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <iostream>
using namespace std;

void boundaryfill(int x, int y, int fill_color, int boundary_color, int &count)
{
    count += 1;
    if (getpixel(x, y) != boundary_color &&
        getpixel(x, y) != fill_color)
    {
        // delay(1);
        putpixel(x, y, fill_color);
        boundaryfill(x + 1, y, fill_color, boundary_color, count);
        boundaryfill(x, y + 1, fill_color, boundary_color, count);
        boundaryfill(x - 1, y, fill_color, boundary_color, count);
        boundaryfill(x, y - 1, fill_color, boundary_color, count);
        boundaryfill(x + 1, y + 1, fill_color, boundary_color, count);
        boundaryfill(x - 1, y + 1, fill_color, boundary_color, count);
        boundaryfill(x - 1, y - 1, fill_color, boundary_color, count);
        boundaryfill(x + 1, y - 1, fill_color, boundary_color, count);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:/TURBOC3/bgi");
    rectangle(50, 50, 250, 250);
    int count = 0;
    boundaryfill(55, 55, 10, 15, count);
    cout << count << endl;
    getch();
    closegraph();
    return 0;
}
