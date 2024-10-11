#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define result cout << answer << endl
#define all(entity) entity.begin(), entity.end()
#define full(entity) entity, entity + size
#define forRange(i, n) for (ll i = 0; i < n; i++)
using namespace std;

typedef long long ll;

class Celsius;
class Fahrenheit;
class Kelvin;

class Celsius
{
    private:
        double celsius;
    public:
        Celsius()
        {
            celsius = 0;
        }
        Celsius(double c)
        {
            if (c >= -273.15)
                celsius = c;
            else
                celsius = -273.15;
        }
        void assign(double temperature)
        {
            if (temperature >= -273.15)
                celsius = temperature;
            else
                celsius = -273.15;
        }
        void display() const
        {
            cout << "The temperature is " << celsius << " Celsius." << endl;
        }
        operator Fahrenheit() const;
        operator Kelvin() const;
        double getCelsius() const
        {
            return celsius;
        }
};

class Fahrenheit
{
    private:
        double fahrenheit;
    public:
        Fahrenheit()
        {
            fahrenheit = 0;
        }
        Fahrenheit(double f)
        {
            if (f >= -460)
                fahrenheit = f;
            else
                fahrenheit = -460;
        }
        void assign(double temperature)
        {
            if (temperature >= -460)
                fahrenheit = temperature;
            else
                fahrenheit = -460;
        }
        void display() const
        {
            cout << "The temperature is " << fahrenheit << " Fahrenheit." << endl;
        }
        operator Kelvin() const;
        operator Celsius() const;
        double getFahrenheit() const
        {
            return fahrenheit;
        }
};

class Kelvin
{
    private:
        double kelvin;
    public:
        Kelvin()
        {
            kelvin = 0;
        }
        Kelvin(double k)
        {
            if (k >= 0)
                kelvin = k;
            else
                kelvin = 0;
        }
        void assign(double temperature)
        {
            if (temperature >= 0)
                kelvin = temperature;
            else
                kelvin = 0;
        }
        void display() const
        {
            cout << "The temperature is " << kelvin << " Kelvin." << endl;
        }
        operator Celsius() const;
        operator Fahrenheit() const;
};

Celsius::operator Fahrenheit() const
{
    return Fahrenheit(celsius * 9.0 / 5.0 + 32);
}

Celsius::operator Kelvin() const
{
    return Kelvin(celsius + 273.15);
}

Fahrenheit::operator Kelvin() const
{
    return Kelvin((fahrenheit - 32) * 5.0 / 9.0 + 273.15);
}

Fahrenheit::operator Celsius() const
{
    return Celsius((fahrenheit - 32) * 5.0 / 9.0);
}

Kelvin::operator Celsius() const
{
    return Celsius(kelvin - 273.15);
}

Kelvin::operator Fahrenheit() const
{
    return Fahrenheit((kelvin - 273.15) * 9.0 / 5.0 + 32);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Kelvin k = 0;
    Celsius c = k;
    Fahrenheit f = 212;
    c = f;

    cout << c.getCelsius() << endl;

    return 0;
}