#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Customer
{
private:
    string name;
    int balance;
    string type;
    long accountNumber;
    float deposit;
    float withdraw;

public:
    void setCustomerDetails(string name, long accountNumber, int balance, string type)
    {
        this->name = name;
        this->balance = balance;
        this->accountNumber = accountNumber;
        this->type = type;
    }
    void depositMoney(float deposit)
    {
        this->deposit += deposit;
    }
    void withdrawMoney(float withdraw)
    {
        if (this->withdraw < balance)
        {
            this->withdraw -= withdraw;
        }
        else
        {
            cout << "You can't withdraw amount";
        }
    }
    void displayAccountDetails()
    {
        cout << "Customer Name:" << this->name << endl;
        // cout << "Account number:" << this->accountNumber << endl;
        cout << "Account Balance Name:" << this->balance << endl;
        cout << "Account Type:" << this->type << endl;
    }
    float currentBalance()
    {
        return this->balance;
    }
};

class Account
{
private:
    long accountNumber;
    float interest;
    // Account Detail ...
public:
    void setAccountDetails(long accountNumber)
    {
        this->accountNumber = accountNumber;
    }

    void calculateInterest(float balance, float interestRate, float interestTime)
    {
        interest = (balance)*pow((1 + interestRate / 100), interestTime);
        interest = interest - balance;
        cout << "\nInterest rate is: " << interestRate << "% and time is " << interestTime << "years total interest amount for "
             << "is:" << interest << endl;
    }
};

class RBI
{
protected:
    Customer c; //hasA relationship
    Account a;  //hasA relationship
    double minimumInterestRate;
    double minimumBalanceAllowed;
    double maximumWithdrawalLimit; /*  */

public:
    double getInterestRate()
    {
        return this->minimumInterestRate;
    }
    double getWithdrawalLimit()
    {
        return this->maximumWithdrawalLimit;
    }
    void setInterestRate(double minimumInterestRate)
    {
        if (minimumInterestRate < 4)
        {
            cout << "Interest rate should be lower than 4";
        }
        this->minimumInterestRate = minimumInterestRate;
    }

    void setWithdrawalLimit(double maximumWithdrawalLimit)
    {
        this->maximumWithdrawalLimit = maximumWithdrawalLimit;
    }
    void setminimumBalanceAllowed(double minimumBalanceAllowed)
    {
        this->minimumBalanceAllowed = minimumBalanceAllowed;
    }
    void withdraw(Customer c, float amount)
    {
        if (this->maximumWithdrawalLimit > amount)
        {
            float temp = c.currentBalance();
            temp -= amount;
            if (this->minimumBalanceAllowed < temp)
            {
                c.withdrawMoney(amount);
                c.currentBalance();
            }
            else
            {
                cout << "You should have minimum " << this->minimumBalanceAllowed << endl;
            }
        }
        else
        {
            cout << "You can not withdraw more than" << this->maximumWithdrawalLimit << endl;
        }
    }
    void Interest(Customer c, Account a, float rate, float interestTime)
    {
        if (this->minimumInterestRate <= rate)
        {
            a.calculateInterest(c.currentBalance(), rate, interestTime);
        }
    }
};

class SBI : public RBI
{

    //Use RBI functionality or define own functionality.
};

class ICICI : public RBI
{
private:
public:
};

class PNB : public RBI
{
private:
public:
};
int main()
{
    Customer c;
    c.setCustomerDetails("Mohammad NUr", 123456789, 1500000, "saving");
    c.displayAccountDetails();
    Account a;
    a.setAccountDetails(123456789);

    SBI sbi;
    sbi.setminimumBalanceAllowed(500);
    sbi.setWithdrawalLimit(150000);
    sbi.setInterestRate(5);
    sbi.withdraw(c, 50000);
    sbi.Interest(c, a, 5, 1);

    ICICI icic;
    icic.setminimumBalanceAllowed(1000);
    icic.setWithdrawalLimit(300000);
    icic.setInterestRate(6);
    icic.withdraw(c, 150000);
    icic.Interest(c, a, 6, 1);

    PNB pnb;
    pnb.setminimumBalanceAllowed(700);
    pnb.setWithdrawalLimit(150000);
    pnb.setInterestRate(5);
    pnb.withdraw(c, 150000);
    pnb.Interest(c, a, 5, 2);
    return 0;
}