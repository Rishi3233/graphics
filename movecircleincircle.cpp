#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <math.h>
#include <iostream>
using namespace std;

void drawcircle(int xc, int yc, int x, int y, int color)
{
    putpixel(xc + x, yc + y, color);
    putpixel(xc - x, yc + y, color);
    putpixel(xc + x, yc - y, color);
    putpixel(xc - x, yc - y, color);
    putpixel(xc + y, yc + x, color);
    putpixel(xc - y, yc + x, color);
    putpixel(xc + y, yc - x, color);
    putpixel(xc - y, yc - x, color);
}

void algo(int xc, int yc, int r, int color)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawcircle(xc, yc, x, y, color);
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
        drawcircle(xc, yc, x, y, color);
        delay(10);
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

int main(void)
{
    int i = 0, j = 0, m = 0;
    int graphic_driver = DETECT, graphic_mode;
    initgraph(&graphic_driver, &graphic_mode, "//turboc3/bgi");
    setbkcolor(0);
    setcolor(15);
    algo(250, 250, 200, 15);
    while (!kbhit())
    {
        i = 200 * sin(m * 3.14159 / 180);
        j = 200 * cos(m * 3.14159 / 180);
        algo(250 + i, 250 - j, 20, 15);
        algo(250 + i, 250 - j, 20, 0);
        m += 10;
        if (m == 360)
            m = 0;
    }
    getch();
    closegraph();
    return 0;
}
