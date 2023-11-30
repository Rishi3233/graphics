#include <stdio.h>
#include <graphics.h>
#include <iostream>
using namespace std;

void drawcircle(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, RED);
    putpixel(xc - x, yc + y, RED);
    putpixel(xc + x, yc - y, RED);
    putpixel(xc - x, yc - y, RED);
    putpixel(xc + y, yc + x, RED);
    putpixel(xc - y, yc + x, RED);
    putpixel(xc + y, yc - x, RED);
    putpixel(xc - y, yc - x, RED);
}

void algo(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawcircle(xc, yc, x, y);
    cout << "(" << x + xc << ", " << y + yc << ")\t";
    cout << "(" << -x + xc << ", " << y + yc << ")\t";
    cout << "(" << x + xc << ", " << -y + yc << ")\t";
    cout << "(" << -x + xc << ", " << -y + yc << ")\n";
    while (y >= x)
    {
        x++;
        if (d > 0)
        {
            y--;
            d += 4 * (x - y) + 10;
        }
        else
        {
            d += 4 * x + 6;
        }
        drawcircle(xc, yc, x, y);
        delay(100);
        if (x > y)
            break;
        cout << "(" << x + xc << ", " << y + yc << ")\t";
        cout << "(" << -x + xc << ", " << y + yc << ")\t";
        cout << "(" << x + xc << ", " << -y + yc << ")\t";
        cout << "(" << -x + xc << ", " << -y + yc << ")\n";
        if (x != y)
        {
            cout << "(" << y + xc << ", " << x + yc << ")\t";
            cout << "(" << -y + xc << ", " << x + yc << ")\t";
            cout << "(" << y + xc << ", " << -x + yc << ")\t";
            cout << "(" << -y + xc << ", " << -x + yc << ")\n";
        }
    }
}

int main()
{
    int xc = 50, yc = 50, r = 25;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    algo(200, 200, 50);
    return 0;
}
