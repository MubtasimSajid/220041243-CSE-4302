#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define result cout << answer << endl
#define nl cout << endl
#define all(v) v.begin(), v.end()
#define full(a) a, a + (sizeof(a) / sizeof(a[0]))
#define printV(v) for (auto &x : v) cout << x << " "; nl
#define printP(p) cout << p.first << " " << p.second << endl
#define debug(x) cerr << x << endl
#define sum(v) accumulate(all(v), 0ll)
#define maxElement(v) *max_element(all(v))
#define minElement(v) *min_element(all(v))

using namespace std;
using ll = long long;

class Shape {
    public:
        virtual void whoAmI() const = 0;
};

class TwoDimensionalShape : public Shape {
    public:
        virtual void whoAmI() const {
            cout << "I am a two-dimensional shape." << endl;

            return;
        }

        virtual float area() const = 0;
        virtual float perimeter() const = 0;
};

class ThreeDimensionalShape : public Shape {
    public:
        virtual void whoAmI() const {
            cout << "I am a three-dimensional shape." << endl;

            return;
        }

        virtual float surfaceArea() const = 0;
        virtual float volume() const = 0;
};

class Square : public TwoDimensionalShape {
    private:
        float side;

    public:
        Square(int s) { side = s; }

        float area() const {
            return side * side;
        }

        float perimeter() const {
            return 4 * side;
        }

        void whoAmI () const {
            cout << "I am a square. ";
            TwoDimensionalShape::whoAmI();
        }
};

class Circle : public TwoDimensionalShape {
    private:
        float radius;

    public:
        Circle(int r) { radius = r; }

        float area() const {
            return 3.1416 * radius * radius;
        }

        float perimeter() const {
            return 2 * 3.1416 * radius;
        }

        void whoAmI () const {
            cout << "I am a circle. ";
            TwoDimensionalShape::whoAmI();
        }
};

class Cube : public ThreeDimensionalShape {
    private:
        float side;

    public:
        Cube(float s) { side = s; }

        float surfaceArea() const {
            return 6 * side * side;
        }

        float volume() const {
            return side * side * side;
        }

        void whoAmI() const {
            cout << "I am a cube. ";
            ThreeDimensionalShape::whoAmI();
        }
};

class Sphere : public ThreeDimensionalShape {
    private:
        float radius;

    public:
        Sphere(float r) { radius = r; }

        float surfaceArea() const {
            return 4 * 3.1416 * radius * radius;
        }

        float volume() const {
            return (4.0 / 3.0) * 3.1416 * radius * radius * radius;
        }

        void whoAmI() const {
            cout << "I am a sphere. ";
            ThreeDimensionalShape::whoAmI();
        }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Circle c1(5);
    TwoDimensionalShape *shape = &c1;

    shape->whoAmI();
    cout << shape->area();

    return 0;
}