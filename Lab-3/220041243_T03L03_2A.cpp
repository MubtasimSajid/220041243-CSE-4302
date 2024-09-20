#include<iostream>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define result cout << answer << endl
#define all(entity) entity.begin(), entity.end()
#define for (i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

enum typeOfAccount
{
    current,
    saving
};

class BankAccount
{
    private:

        string customerName;
        int accountNumber;
        typeOfAccount accountType;
        int balanceAmount;

    public:

        BankAccount()
        {
            customerName = "";
            accountNumber = 0;
            accountType = current;
            balanceAmount = 0;
        }

        void customerDetails(string name, int accNo)
        {
            customerName = name;
            accountNumber = accNo;
        }

        void accountType(typeOfAccount type)
        {
            accountType = type;
        }

        void balance()
        {
            cout << "Current Balance: " << balanceAmount << endl;
        }

        void deposit(int amount)
        {
            balanceAmount += amount;

            cout << "Deposit successful! Current valance is: " << balanceAmount << endl;
        }

        void withdraw(int amount)
        {
            if (amount <= balanceAmount)
            {
                balanceAmount -= amount;

                cout << "Withdraw successful! Current balance is: " << balanceAmount << endl;
            }
            else
            {
                cout << "Sorry, withdrawal failed! Current balance is insufficient to complete withdrawal. Current balance is: " << balanceAmount << endl;
            }
        }

        void display()
        {
            cout << "Customer Name: " << customerName << endl;
            cout << "Account Number: " << accountNumber << endl;
            cout << "Account Type: " << (accountType == current ? "Current" : "Saving") << endl;
            cout << "Balance amount: " << balanceAmount << endl;
        }
};

int main(void)
{
    BankAccount customer;

    customer.customerDetails("John Doe", 220041243);
    customer.accountType(saving);
    customer.balance();
    customer.deposit(5000);
    customer.balance();
    customer.withdraw(3000);
    customer.balance();
    customer.withdraw(3000);
    customer.balance();
    customer.display();

    return 0;
}