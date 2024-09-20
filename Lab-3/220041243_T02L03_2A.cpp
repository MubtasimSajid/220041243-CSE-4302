#include<iostream>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define result cout << answer << endl
#define all(entity) entity.begin(), entity.end()
#define for (i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

class RationalNumber
{
    private:

        int numerator;
        int denominator;

    public:

        RationalNumber()
        {
            numerator = 0;
            denominator = 1;
        }

        void assign(int assignNumerator, int assignDenominator)
        {
            if (!assignDenominator)
            {
                cout << "You cannot assign 0 as denominator." << endl;
                return;
            }

            numerator = assignNumerator;
            denominator = assignDenominator;
        }

        float convert()
        {
            return (1.0 * numerator / denominator);
        }

        void invert()
        {
            if (!numerator)
            {
                cout << "You cannot assign 0 as denominator." << endl;
                return;
            }

            int temp = numerator;
            numerator = denominator;
            denominator = temp;
        }

        void print()
        {
            cout << "The Rational Number is " << numerator << "/" << denominator << endl;
        }
};

int main(void)
{
    RationalNumber rn;

    rn.assign(1, 2);

    cout << "The decimal form of the rational number is " << rn.convert() << endl;

    rn.invert();

    cout << "The inverted form of the rational number is " << rn.convert() << endl;

    rn.print();

    rn.assign(1, 0);

    rn.assign(0, 1);

    rn.invert();

    return 0;
}