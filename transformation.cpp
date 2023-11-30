#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Point
{
    float x, y;
};

void displayMatrix(float matrix[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void translate(Point &p, float tx, float ty)
{
    float matrix[3][3] = {
        {1, 0, tx},
        {0, 1, ty},
        {0, 0, 1}};

    cout << "Translation Matrix:" << endl;
    displayMatrix(matrix);

    float newX = matrix[0][0] * p.x + matrix[0][1] * p.y + matrix[0][2];
    float newY = matrix[1][0] * p.x + matrix[1][1] * p.y + matrix[1][2];

    p.x = newX;
    p.y = newY;
}

void rotate(Point &p, float angle)
{
    float radians = angle * 3.141592 / 180.0;
    float matrix[3][3] = {
        {cos(radians), -sin(radians), 0},
        {sin(radians), cos(radians), 0},
        {0, 0, 1}};

    cout << "Rotation Matrix:" << endl;
    displayMatrix(matrix);

    float newX = matrix[0][0] * p.x + matrix[0][1] * p.y + matrix[0][2];
    float newY = matrix[1][0] * p.x + matrix[1][1] * p.y + matrix[1][2];

    p.x = newX;
    p.y = newY;
}

void scale(Point &p, float sx, float sy)
{
    float matrix[3][3] = {
        {sx, 0, 0},
        {0, sy, 0},
        {0, 0, 1}};

    cout << "Scaling Matrix:" << endl;
    displayMatrix(matrix);

    float newX = matrix[0][0] * p.x + matrix[0][1] * p.y + matrix[0][2];
    float newY = matrix[1][0] * p.x + matrix[1][1] * p.y + matrix[1][2];

    p.x = newX;
    p.y = newY;
}

void shear(Point &p, float shx, float shy)
{
    float matrix[3][3] = {
        {1, shx, 0},
        {shy, 1, 0},
        {0, 0, 1}};

    cout << "Shearing Matrix:" << endl;
    displayMatrix(matrix);

    float newX = matrix[0][0] * p.x + matrix[0][1] * p.y + matrix[0][2];
    float newY = matrix[1][0] * p.x + matrix[1][1] * p.y + matrix[1][2];

    p.x = newX;
    p.y = newY;
}

int main()
{
    Point inputPoint;
    float tx, ty, angle, sx, sy, shx, shy;

    cout << "Enter initial point (x y): ";
    cin >> inputPoint.x >> inputPoint.y;

    int choice;
    do
    {
        cout << "\n1. Translate\n2. Rotate\n3. Scale\n4. Shear\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter translation values (tx ty): ";
            cin >> tx >> ty;
            translate(inputPoint, tx, ty);
            break;
        case 2:
            cout << "Enter rotation angle (degrees): ";
            cin >> angle;
            rotate(inputPoint, angle);
            break;
        case 3:
            cout << "Enter scaling factors (sx sy): ";
            cin >> sx >> sy;
            scale(inputPoint, sx, sy);
            break;
        case 4:
            cout << "Enter shearing factors (shx shy): ";
            cin >> shx >> shy;
            shear(inputPoint, shx, shy);
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

        cout << "Transformed Point: (" << inputPoint.x << ", " << inputPoint.y << ")\n";

    } while (choice != 0);

    return 0;
}
