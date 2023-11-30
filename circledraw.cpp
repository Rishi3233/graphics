#include <iostream>
#include <graphics.h>
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

void midPointCircleDraw(int x_centre, int y_centre, int r)
{
    int x = r, y = 0;
    drawcircle(x_centre, y_centre, x, y);
    cout << "(" << x + x_centre << ", " << y + y_centre << ") ";
    cout << "(" << x + x_centre << ", " << -y + y_centre << ") ";
    cout << "(" << y + x_centre << ", " << x + y_centre << ") ";
    cout << "(" << -y + x_centre << ", " << x + y_centre << ")\n";

    int P = 1 - r;
    while (x > y)
    {
        y++;

        if (P <= 0)
            P = P + 2 * y + 1;
        else
        {
            x--;
            P = P + 2 * y - 2 * x + 1;
        }
        drawcircle(x_centre, y_centre, x, y);
        delay(100);

        if (x < y)
            break;
        cout << "(" << x + x_centre << ", " << y + y_centre << ") ";
        cout << "(" << -x + x_centre << ", " << y + y_centre << ") ";
        cout << "(" << x + x_centre << ", " << -y + y_centre << ") ";
        cout << "(" << -x + x_centre << ", " << -y + y_centre << ")\n";
        if (x != y)
        {
            cout << "(" << y + x_centre << ", " << x + y_centre << ") ";
            cout << "(" << -y + x_centre << ", " << x + y_centre << ") ";
            cout << "(" << y + x_centre << ", " << -x + y_centre << ") ";
            cout << "(" << -y + x_centre << ", " << -x + y_centre << ")\n";
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    midPointCircleDraw(200, 200, 30);
    return 0;
}
