#include "employee.h"
#define endl '\n'

using namespace std;

typedef long long ll;

bool compareAscendingOrder(const Employee &a, const Employee &b)
{
    if (a.getName() == b.getName())
        a.calculateTotalSalary() < b.calculateTotalSalary();
    return a.getName() < b.getName();
}

string randomWord()
{
    int wordLength = 2 + rand() % 16;
    string word = "";

    for (int i = 0; i < wordLength; ++i)
    {
        char firstCharacter = 'a';
        if (!i)
            firstCharacter = 'A';
        char randomCharacter = firstCharacter + rand() % 26;
        word.push_back(randomCharacter);
    }

    return word;
}

void generateInformationRandom(Employee &employee)
{
    string n = randomWord();
    employee.setName(n);
    string dob = "01-01-" + to_string(1900 + rand() % 106);
    employee.setDateOfBirth(dob);
    float baseSalary = 10000.0 + rand() % 100000;
    employee.setBaseSalary(baseSalary);
    int joiningYear = 1900 + rand() % 123;
    employee.setJoiningYear(joiningYear);
}

void showAllBasedOnTotalSalary(Employee ar[], int size)
{
    sort(ar, ar + size, compareAscendingOrder);

    for (int i = 0; i < size; i++)
        cout << "Name: " << ar[i].getName() << ", Total Salary: " << ar[i].calculateTotalSalary() << endl;
}

int main(void)
{
    srand(static_cast<unsigned int>(time(0)));

    Employee employees[100];

    for (int i = 0; i < 100; i++)
        generateInformationRandom(employees[i]);

    showAllBasedOnTotalSalary(employees, 100);

    return 0;
}