#include<iostream>
#define endl '\n'
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
        string accountNumber;
        typeOfAccount accountType;
        float balanceAmount;

    public:

        BankAccount()
        {
            customerName = "";
            accountNumber = "";
            accountType = current;
            balanceAmount = 0;
        }

        void customerDetails(string name, string accNo)
        {
            customerName = name;
            accountNumber = accNo;
        }

        void accType(typeOfAccount type)
        {
            accountType = type;
        }

        void balance()
        {
            cout << "Current Balance: " << balanceAmount << endl;
        }

        void deposit(float amount)
        {
            balanceAmount += amount;

            cout << "Deposit successful! Current balance is: " << balanceAmount << endl;
        }

        void withdraw(float amount)
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

    customer.customerDetails("John Doe", "220041243");
    customer.accType(saving);
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