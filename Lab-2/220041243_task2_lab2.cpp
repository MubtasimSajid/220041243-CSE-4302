#include<bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define result cout << answer << endl
using namespace std;

typedef long long ll;

int main(void)
{
    enum etype
    {
        laborer,
        secretary,
        manager,
        accountant,
        executive,
        researcher
    };

    etype employeeType;
    char type;

    cout << "Enter employee type (first letter only of laborer, secretary, manager, accountant, executive or researcher): ";

    cin >> type;

    switch (type)
    {
        case 'l':
            employeeType = laborer;
            break;
        case 's':
            employeeType = secretary;
            break;
        case 'm':
            employeeType = manager;
            break;
        case 'a':
            employeeType = accountant;
            break;
        case 'e':
            employeeType = executive;
            break;
        case 'r':
            employeeType = researcher;
            break;
        default:
            cout << "Invalid employee type" << endl;
            return 0;
    }

    cout << "Employee type is ";

    switch (employeeType)
    {
        case laborer:
            cout << "laborer.";
            break;
        case secretary:
            cout << "secretary.";
            break;
        case manager:
            cout << "manager.";
            break;
        case accountant:
            cout << "accountant.";
            break;
        case executive:
            cout << "executive.";
            break;
        case researcher:
            cout << "researcher.";
            break;
    }

    return 0;
}