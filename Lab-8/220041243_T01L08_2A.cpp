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

class Person {
    protected:
        string name;
    
    public:
        Person(string n) : name(n) {}

        virtual void display() const {
            cout << "Name: " << name << endl;
        }
};

class Employee : public Person {
    private:
        int employeeID;
    
    protected:
        float salary;

    public:
        Employee(string n, int ID, float s) : Person(n), employeeID(ID), salary(s) {}

        virtual void display() const {
            Person::display();
            cout << "Employee ID: " << employeeID << endl;
            cout << "Salary: $" << salary << endl;
        }
};

class Intern : public Employee {
    private:
        string schoolName;

    public:
        Intern(string n, int ID, float s, string sn) : Employee(n, ID, s), schoolName(sn) {}

        void display() const {
            Employee::display();
            cout << "School Name: " << schoolName << endl;
        }
};

class Manager : protected Employee {
    private:
        string department;
    
    public:
        Manager(string n, int ID, float s, string d) : Employee(n, ID, s), department(d) {}

        virtual void display() const {
            Employee::display();
            cout << "Department: " << department << endl;
        }
};

class Director : public Manager {
    private:
        float bonus;

    public:
        Director(string n, int ID, float s, string d, float b) : Manager(n, ID, s, d), bonus(b) {}

        void display() const {
            Manager::display();
            cout << "Bonus: $" << bonus << endl;
        }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Intern m("Bob", 10, 50, "CSE");
    Employee *p = &m;

    p->display();

    return 0;
}