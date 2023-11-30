#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

int main()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int dx = x2 - x1;
    int dy = y2 - y1;

    int s_z = 2 * dy;
    int g_z = 2 * (dy - dx);
    int p = 2 * dy - dx;

    int x = x1, y = y1;
    putpixel(x, y, RED);
    cout << x << " " << y << endl;

    do
    {
        if (p < 0)
        {
            p += s_z;
        }
        else
        {
            p += g_z;
            y++;
        }
        x++;
        putpixel(x, y, RED);
        cout << x << " " << y << endl;
        dx--;
    } while (dx > 0);
    getch();
}
