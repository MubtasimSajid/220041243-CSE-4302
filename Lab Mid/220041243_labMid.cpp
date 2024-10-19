#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define result cout << answer << endl
#define all(entity) entity.begin(), entity.end()
#define full(entity) entity, entity + size
#define forRange(i, n) for (ll i = 0; i < n; i++)
#define pi 3.14159
using namespace std;

typedef long long ll;

class Circle
{
    private:
        float centerX;
        float centerY;
        float radius;
    public:
        Circle(float x, float y, float r)
        {
            centerX = x;
            centerY = y;
            if (r >= 0)
                radius = r;
            else
                radius = 0;
        }

        ~Circle() {}

        Circle(const Circle &c)
        {
            centerX = c.centerX;
            centerY = c.centerY;
            radius = c.radius;
        }

        float getArea() const
        {
            return pi * radius * radius;
        }

        void display() const
        {
            cout << "The center of the circle is at (" << centerX << ", " << centerY << ")." << endl;
            cout << "The radius of the circle is " << radius << endl;
            cout << "The area of the circle is " << getArea() << " square units." << endl;
            cout << "The circumference of the circle is " << getCircumference() << " units." << endl;
        }

        float getRadius() const
        {
            return radius;
        }

        void setRadius(float r)
        {
            if (r >= 0)
                radius = r;
            else
                radius = 0;
        }

        float getX() const
        {
            return centerX;
        }

        void setX(float x)
        {
            centerX = x;
        }

        float getY() const
        {
            return centerY;
        }

        void setY(float y)
        {
            centerY = y;
        }

        float getCircumference() const
        {
            return 2 * pi * radius;
        }

        void scale(float factor)
        {
            if (factor >= 0)
                radius *= factor;
        }
};

Circle &operator++(Circle &c)
{
    c.setRadius(c.getRadius() + 1);
    return c;
}

Circle operator++(Circle &c, int)
{
    Circle c1({c.getX(), c.getY(), c.getRadius()});
    c.setRadius(c.getRadius() + 1);
    return c1;
}

Circle &operator--(Circle &c)
{
    if (c.getRadius())
        c.setRadius(c.getRadius() - 1);
    return c;
}

Circle operator--(Circle &c, int)
{
    Circle c1({c.getX(), c.getY(), c.getRadius()});
    if (c.getRadius())
        c.setRadius(c.getRadius() - 1);
    return c1;
}

bool operator==(const Circle &a, const Circle &b)
{
    return (a.getX() == b.getX() && a.getY() == b.getY() && a.getRadius() == b.getRadius());
}

bool comparator(const Circle &a, const Circle &b)
{
    return a.getArea() < b.getArea();
}

void sortByArea(Circle circles[], int size)
{
    sort(circles, circles + size, comparator);
}

int main(void)
{
    Circle circles[10] = {{0, 0, 1}, {0, 0, 2}, {0, 0, 3}, {0, 0, 4}, {0, 0, 5}, {0, 0, 6}, {0, 0, 7}, {0, 0, 8}, {0, 0, 9}, {0, 0, 10}};

    circles[0]--;
    ++circles[1];
    sortByArea(circles, 10);

    for (int i = 0; i < 10; ++i)
    {
        circles[i].display();
        cout << endl;
    }

    return 0;
}