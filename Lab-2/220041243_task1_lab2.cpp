#include<bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define result cout << answer << endl
using namespace std;

typedef long long ll;

int main(void)
{
    int a, b, c, d, top, bottom;

    cout << "Enter first fraction: ";
    cin >> a;
    cin.ignore();
    cin >> b;
    cout << "Enter second fraction: ";
    cin >> c;
    cin.ignore();
    cin >> d;

    top = (a * d) + (b * c);
    bottom = b * d;

    cout << "Sum = " << top << "/" << bottom;

    return 0;
}