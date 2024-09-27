#include<iostream>
#include<iomanip>
#define endl '\n'
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
        string empName;
        int ID;
        float baseSalary;
        int joiningYear;
        int birthYear;

        float calculateTotalSalary()
        {
            baseSalary += (currentYear - joiningYear) * 3.0 / 100.0;
            float transportationAllowance = baseSalary / 10.0;
            float housingAllowance = baseSalary * 30.0 / 100.0;
            float miscellaneousAllowance = baseSalary / 10.0;
        }

        status getStatus()
        {
            if (currentYear - birthYear <= 25)
            {
                if (calculateTotalSalary() <= 20000)
                    return low;
                else
                    return moderate;
            }
            else
            {
                if (calculateTotalSalary() <= 21000)
                    return low;
                else if (calculateTotalSalary() > 21000 && calculateTotalSalary() <= 60000)
                    return moderate;
                else
                    return high;
            }
        }

        float calculateBonus()
        {
            float totalSalary = calculateTotalSalary();
            status currentStatus = getStatus();

            if (currentStatus == low)
                return totalSalary * 5.0 / 100.0;
            else if (currentStatus == moderate)
                return totalSalary * 10.0 / 100.0;
            else
                return totalSalary * 15.0 / 100.0;
        }

    public:
        Employee(string name, int id, float salary, int year, int yearOfBirth)
        {
            empName = name;
            ID = id;
            baseSalary = salary;
            joiningYear = year;
            birthYear = yearOfBirth;
        }

        Employee()
        {
            empName = "";
            ID = 0;
            baseSalary = 0.0;
            joiningYear = 0;
            birthYear = 1990;
        }

        ~Employee()
        {
            cout << "Employee " << empName << " was removed." << endl;
        }

        void feedInfo(string name, int id, float salary, int year)
        {
            empName = name;
            ID = id;
            baseSalary = salary;
            joiningYear = year;
        }

        void showInfo()
        {
            cout << "Employee Name: " << empName << endl;
            cout << "Employee ID: " << ID << endl;
            cout << "Base Salary: $" << fixed << setprecision(2) << baseSalary << endl;
            cout << "Joining Year: " << joiningYear << endl;
        }
};

int main(void)
{
    Employee exampleEmployee("Arian", 220041243, 5000, 2022, 2002);

    return 0;
}