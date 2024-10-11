#include "employee.h"

bool compareEmployees(const Employee &e1, const Employee &e2)
{
    if (e1.calculateTotalSalary() == e2.calculateTotalSalary())
        return e1.getDateOfBirth() > e2.getDateOfBirth();
    return e1.calculateTotalSalary() > e2.calculateTotalSalary();
}

void Employee::setName(string n)
{
    name = n;
}

string Employee::getName() const
{
    return name;
}

void Employee::setDateOfBirth(string dob)
{
    dateOfBirth = dob;
}

string Employee::getDateOfBirth() const
{
    return dateOfBirth;
}

void Employee::setBaseSalary(float salary)
{
    baseSalary = salary;
}

float Employee::getBaseSalary() const
{
    return baseSalary;
}

void Employee::setJoiningYear(int year)
{
    joiningYear = year;
}

int Employee::getJoiningYear() const
{
    return joiningYear;
}

void Employee::setInfo(Employee &employee)
{
    string n, dob;
    float salary;
    int yearOfJoining;

    cout << "Enter name: ";
    cin >> n;
    cout << "Enter date of birth (dd-mm-yyyy): ";
    cin >> dob;
    cout << "Enter base salary: ";
    cin >> salary;
    cout << "Enter joining year: ";
    cin >> yearOfJoining;

    if (n.size() > 2)
        employee.setName(n);
    else
        employee.setName("John Doe");

    int birthYear;
    birthYear = 0 + ((dob[6] - '0') * 1000);
    birthYear += 0 + ((dob[7] - '0') * 100);
    birthYear += 0 + ((dob[8] - '0') * 10);
    birthYear += 0 + (dob[9] - '0');

    if (currentYear - birthYear <= 18)
        employee.setDateOfBirth("01-01-2002");
    else
        employee.setDateOfBirth(dob);

    if (salary >= 10000 && salary <= 100000)
        employee.setBaseSalary(salary);
    else
        employee.setBaseSalary(10000);

    employee.setJoiningYear(yearOfJoining);
}

void Employee::getInfo(Employee &employee) const
{
    cout << "Name: " << employee.getName() << endl;
    cout << "Date of Birth: " << employee.getDateOfBirth() << endl;
    cout << "Base Salary: " << employee.getBaseSalary() << endl;
    cout << "Joining Year: " << employee.getJoiningYear() << endl;
}

float Employee::calculateTotalSalary() const
{
    float currentSalary = baseSalary;
    for (int i = 0; i < (currentYear - joiningYear); i++)
        currentSalary += (currentSalary * 3.0 / 100.0);
    float totalSalary = currentSalary;
    totalSalary += currentSalary / 10.0;
    totalSalary += currentSalary * (30.0 / 100.0);
    totalSalary += currentSalary / 10.0;

    return totalSalary;
}

status Employee::getStatus() const
{
    int birthYear;
    birthYear = 0 + (dateOfBirth[6] - '0') * 1000;
    birthYear += 0 + ((dateOfBirth[7] - '0') * 100);
    birthYear += 0 + ((dateOfBirth[8] - '0') * 10);
    birthYear += 0 + (dateOfBirth[9] - '0');

    if ((currentYear - birthYear) <= 25)
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
        else if (calculateTotalSalary() <= 60000)
            return moderate;
        else
            return high;
    }
}

float Employee::calculateBonus() const
{
    status employeeStatus = getStatus();
    float totalSalary = calculateTotalSalary();

    if (employeeStatus == low)
        return totalSalary * 5.0 / 100.0;
    else if (employeeStatus == moderate)
        return totalSalary * 10.0 / 100.0;
    else
        return totalSalary * 15.0 / 100.0;
}

Employee &Employee::compareTotalSalary(Employee &e, int size) const
{
    sort(&e, &e + size, compareEmployees);
    return e;
}