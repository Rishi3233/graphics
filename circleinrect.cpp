#include <iostream>
#include <conio.h>
#include <graphics.h>
using namespace std;

// struct Points{
//
// };

void BresenhamCircleDraw(int xcenter, int ycenter, int r, int color)
{
    int x = 0, y = r;
    putpixel(x + xcenter, y + ycenter, color);

    putpixel(-x + xcenter, y + ycenter, color);

    putpixel(x + xcenter, -y + ycenter, color);

    putpixel(-x + xcenter, -y + ycenter, color);

    float d = 3 - 2 * r;
    while (x < y)
    {
        x++;
        if (d < 0)
        {
            d += 4 * x + 6;
        }
        else
        {
            y--;
            d += 4 * (x - y) + 10;
        }
        putpixel(x + xcenter, y + ycenter, color);
        delay(5);
        putpixel(-x + xcenter, y + ycenter, color);

        putpixel(x + xcenter, -y + ycenter, color);

        putpixel(-x + xcenter, -y + ycenter, color);
        // changes
        putpixel(xcenter + y, ycenter - x, color);
        putpixel(xcenter - y, ycenter - x, color);
        putpixel(xcenter + y, ycenter + x, color);
        putpixel(xcenter - y, ycenter + x, color);
    }
}

int main()
{
    int gd = DETECT, gm, k = 0;
    initgraph(&gd, &gm, (char *)"");
    int center[2];
    cout << "Enter the center of the circle: ";
    for (int i = 0; i < 2; i++)
        cin >> center[i];

    int radius;
    cout << "Enter the radius: ";
    cin >> radius;

    int n = 50;
    int x = center[0], y = center[1];
    for (int i = 0; i < 10; i++)
    {
        BresenhamCircleDraw(center[0], center[1], radius, 15);
        putpixel(center[0], center[1], 15);
        BresenhamCircleDraw(center[0], center[1], radius, 0);
        center[0] += 20;
        delay(5);
        if (i == 24)
            break;
    }
    line(x, y, center[0], center[1]);

    x = center[0], y = center[1];
    for (int i = 0; i < 10; i++)
    {
        BresenhamCircleDraw(center[0], center[1], radius, 15);
        putpixel(center[0], center[1], 15);
        BresenhamCircleDraw(center[0], center[1], radius, 0);
        center[1] += 20;
        delay(5);
        if (i == 24)
            break;
    }
    line(x, y, center[0], center[1]);

    x = center[0], y = center[1];
    for (int i = 0; i < 10; i++)
    {
        BresenhamCircleDraw(center[0], center[1], radius, 15);
        putpixel(center[0], center[1], 15);
        BresenhamCircleDraw(center[0], center[1], radius, 0);
        center[0] -= 20;
        delay(5);
        if (i == 24)
            break;
    }
    line(x, y, center[0], center[1]);

    x = center[0], y = center[1];
    for (int i = 0; i < 10; i++)
    {
        BresenhamCircleDraw(center[0], center[1], radius, 15);
        putpixel(center[0], center[1], 15);
        BresenhamCircleDraw(center[0], center[1], radius, 0);
        center[1] -= 20;
        delay(5);
        if (i == 24)
            break;
    }
    line(x, y, center[0], center[1]);

    getch();
    closegraph();
}
