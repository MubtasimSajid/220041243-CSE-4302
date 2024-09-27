#include<iostream>
#define endl '\n'
using namespace std;

typedef long long ll;

void displayStat();

enum type
{
    current,
    savings
};

class BankAccount
{
    private:
        string accountNumber;
        string holderName;
        type accountType;
        float currentBalance;
        const float minimumBalance;
        static float totalSourceTax;
        static int totalAccounts;
        static int activeAccounts;

    public:
        BankAccount() : minimumBalance(100.0)
        {
            accountNumber = "";
            holderName = "";
            accountType = current;
            currentBalance = 0.0;
            totalAccounts++;
            activeAccounts++;
        }

        BankAccount(string accNo, string name, string accType, float currentAmount, float minBalance)
            : minimumBalance(minBalance)
        {
            accountNumber = accNo;
            holderName = name;
            if (accType == "Current")
                accountType = current;
            else if (accType == "Savings")
                accountType = savings;
            currentBalance = currentAmount;
            totalAccounts++;
            activeAccounts++;
        }

        ~BankAccount()
        {
            cout << "Account of Mr. " << holderName << " with account no " << accountNumber << " is destroyed with a balance of BDT " << currentBalance << endl;
            activeAccounts--;
        }
        
        void setValues(string accNo, string name, string accType, float currentAmount, float minBalance)
        {
            accountNumber = accNo;
            holderName = name;
            if (accType == "Current")
                accountType = current;
            else if (accType == "Savings")
                accountType = savings;
            currentBalance = currentAmount;
        }

        void displayAccountInfo() const
        {
            cout << "Account Number: " << accountNumber << endl;
            cout << "Holder Name: " << holderName << endl;
            cout << "Account Type: " << (accountType == current ? "Current" : "Savings") << endl;
            cout << "Current Balance: " << currentBalance << endl;
            cout << "Minimum Balance To Withdraw Money: " << minimumBalance << endl;
        }

        void showBalance()
        {
            cout << "Current Balance: " << currentBalance << endl;
        }

        void deposit(float amount)
        {
            if (amount <= 0)
            {
                cout << "Invalid deposit amount." << endl;
                return;
            }
            currentBalance += amount;
            cout << "Deposit successful." << endl;
            cout << "Current Balance: " << currentBalance << endl;
        }

        void withdrawal(float amount)
        {
            if ((amount > currentBalance) || (currentBalance - amount > minimumBalance))
                cout << "Insufficient funds. Cannot withdraw." << endl;
            else if (amount <= 0)
                cout << "Invalid amount." << endl;
            else
            {
                currentBalance -= amount;
                cout << "Withdrawal successful." << endl;
                cout << "Current Balance: " << currentBalance << endl;
            }
        }

        void giveInterest(float interestPercent = 3.0)
        {
            float interestAmount = currentBalance * (interestPercent / 100.0);
            interestAmount -= (interestAmount / 10.0);
            currentBalance += interestAmount;
            totalSourceTax += interestAmount;
            cout << "Interest earned: " << interestAmount << endl;
            cout << "Current Balance: " << currentBalance << endl;
        }

        float getBalance() const
        {
            return currentBalance;
        }

        static int getTotalAccounts()
        {
            return totalAccounts;
        }

        static int getActiveAccounts()
        {
            return activeAccounts;
        }

        static float getTotalTax()
        {
            return totalSourceTax;
        }
};

int BankAccount::totalAccounts = 0;
int BankAccount::activeAccounts = 0;
float BankAccount::totalSourceTax = 0.0;

BankAccount larger(const BankAccount first, const BankAccount second)
{
    if (first.getBalance() > second.getBalance())
        return first;
    else
        return second;
}

void displayStat()
{
    cout << "Total no. of accounts created: " << BankAccount::getTotalAccounts() << endl;
    cout << "Total no. of accounts active: " << BankAccount::getActiveAccounts() << endl;
    cout << "Total amount of source tax collected: " << BankAccount::getTotalTax() << endl;
}

int main(void)
{
    BankAccount testAccount("123456789", "John Doe", "Current", 500.0, 50.0);
    testAccount.displayAccountInfo();

    return 0;
}
