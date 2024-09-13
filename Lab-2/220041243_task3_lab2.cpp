#include<bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define result cout << answer << endl
using namespace std;

typedef long long ll;

typedef struct fraction
{
    int numerator;
    int denominator;
} fraction;

int main(void)
{
    fraction first, second, answer;

    cout << "Enter first fraction: ";
    cin >> first.numerator;
    cin.ignore();
    cin >> first.denominator;

    cout << "Enter second fraction: ";
    cin >> second.numerator;
    cin.ignore();
    cin >> second.denominator;

    answer.numerator = (first.numerator * second.denominator) + (second.numerator * first.denominator);
    answer.denominator = first.denominator * second.denominator;

    cout << "Sum = " << answer.numerator << "/" << answer.denominator;

    return 0;
}