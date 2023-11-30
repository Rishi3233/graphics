#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int left = 100, top = 200, right = 300, bottom = 250;
    int wheel1_left = 120, wheel1_top = 250, wheel1_right = 150, wheel1_bottom = 280;
    int wheel2_left = 250, wheel2_top = 250, wheel2_right = 280, wheel2_bottom = 280;
    int road_y = 280;

    while (!kbhit())
    {
        cleardevice();
        setcolor(LIGHTGRAY);
        line(0, road_y, getmaxx(), road_y);
        setcolor(WHITE);
        rectangle(left, top, right, bottom);
        line(left, top, right - 50, top - 50);
        line(right, top, right - 50, top - 50);
        setcolor(WHITE);
        circle(wheel1_left, wheel1_top, 15);
        circle(wheel2_left, wheel2_top, 15);
        left++;
        right++;
        wheel1_left++;
        wheel2_left++;
        delay(10);
    }

    closegraph();
    return 0;
}
