#include <iostream>
using namespace std;
class BankAccount
{
private:
    float amount;

public:
    BankAccount()
    {}
    BankAccount(float amount)
    {
        this->amount = amount;
    }
    void setAmount(float amount)
    {
        this->amount = amount;
    }
    void deposit(float amount)
    {
        this->amount += amount;
    }
    float withdraw(float amount)
    {
        if (this->amount < amount)
        {
            cout << "Don't have sufficent money";
            return this->amount;
        }
        this->amount -= amount;
        return this->amount;
    }
    float CurrentAmount()
    {
        return this->amount;
    }
};
int main()
{
    BankAccount account;

    account.setAmount(56000);
    cout << "After current account is " << account.CurrentAmount() << endl;

    account.deposit(5000);
     cout << "After deposit 5000" << account.CurrentAmount() << endl;

    account.withdraw(4000);
    cout << "After withdraw 4000" << account.CurrentAmount() << endl;
    return 0;
}