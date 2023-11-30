#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

int sign(int n)
{
    if (n >= 0)
    {
        return 1;
    }
    else
        return 0;
}

int main()
{
    int x1, y1, x2, y2;
    cout << "Enter the start and end points of a line:" << endl;
    cin >> x1 >> y1 >> x2 >> y2;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    float dx = abs(x2 - x1);
    float dy = abs(y2 - y1);
    float len;

    if (dx > dy)
    {
        len = dx;
    }
    else
    {
        len = dy;
    }
    dx = (x2 - x1) / len;
    dy = (y2 - y1) / len;

    float x = x1 + 0.5 * sign(dx);
    float y = y1 + 0.5 * sign(dy);

    int i = 1;
    putpixel(trunc(x), trunc(y), RED);
    cout << x << " " << y << endl;
    while (i <= len)
    {
        x += dx;
        y += dy;
        cout << x << " " << y << endl;
        i++;
        putpixel(trunc(x), trunc(y), RED);
    }
    getch();
}
