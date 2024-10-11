#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define result cout << answer << endl
#define all(entity) entity.begin(), entity.end()
#define forRange(i, n) for (ll i = 0; i < n; i++)
#define currentYear 2024
using namespace std;

typedef long long ll;

enum status
{
    low,
    moderate,
    high
};

class Employee
{
    private:
        string name;
        string dateOfBirth;
        float baseSalary;
        int joiningYear;
    public:
        Employee()
        {
            name = "John Doe";
            dateOfBirth = "01-01-2002";
            baseSalary = 10000.0;
        }

        void setName(string n);
        string getName() const;

        void setDateOfBirth(string dob);
        string getDateOfBirth() const;

        void setBaseSalary(float salary);
        float getBaseSalary() const;

        void setJoiningYear(int year);
        int getJoiningYear() const;

        void setInfo(Employee &employee);
        void getInfo(Employee &employee) const;

        Employee &compareTotalSalary(Employee &e, int size) const;

        float calculateTotalSalary() const;

        status getStatus() const;

        float calculateBonus() const;
};

#endif