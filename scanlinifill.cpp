#include <graphics.h>
#include <stdio.h>

void scanline(int x1, int x2, int y)
{
    for (int x = x1; x <= x2; x++)
    {
        // delay(1);
        putpixel(x, y, RED);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 200, y1 = 200;
    int x2 = 400, y2 = 400;

    rectangle(x1, y1, x2, y2);

    for (int y = y1 + 1; y < y2; y++)
    {
        scanline(x1 + 1, x2 - 1, y);
    }

    delay(5000);

    closegraph();
    return 0;
}
