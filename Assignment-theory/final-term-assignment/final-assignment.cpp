#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Account
{
protected:
    string name;
    long accountNumber;
    int balance;
    string type;
    float deposit;
    float withdraw;

public:
    void getDetails(string type)
    {
        this->type = type;
        cout << "Enter Customer Name:";
        cin >> this->name;
        cout << "Enter Account number:";
        cin >> this->accountNumber;
        cout << "Enter Account balance:";
        cin >> this->balance;
    }
    void display()
    {
        cout << "Customer Name:" << this->name << endl;
        cout << "Account number:" << this->accountNumber << endl;
        cout << "Account Balance Name:" << this->balance << endl;
        cout << "Account Type:" << this->type << endl;
    }
    virtual void depositMoney()
    {
        cout << "Enter amount money to deposit:";
        cin >> this->deposit;
        display();
        cout << endl;
        this->balance += this->deposit;
        cout << "After deposit, the main balance is :" << this->balance << endl;
    }
    virtual void withdrawMoney()
    {
        cout << "Enter the amount of money to withdraw: ";
        cin >> this->withdraw;
        if (this->withdraw < this->balance)
        {
            display();
            this->balance -= this->withdraw;
            cout << "After withdraw, the main balance is :" << this->balance << endl;
        }
        else
        {
            cout << "You can't withdraw money fully, the  balance is :" << this->balance << endl;
        }
    }
};

class CurrentAccount : public Account
{
public:
    static float min;
    static float penalty;

    void checkBalance()
    {
        if (balance < CurrentAccount::min)
        {
            cout << "balance should not be less than 500" << endl;
            balance = balance - CurrentAccount::penalty;
            display();
            cout << "After Penalty, the main balance is :" << this->balance << endl;
        }
    }
};

class SavingsAccount : public Account
{
private:
    float interest;

public:
    static float interestRate;
    static float interestTime;
    void calculateInterest()
    {
        interest = (this->balance) * pow((1 + interestRate / 100), interestTime);
        interest = interest - balance;
        cout << "\nInterest rate is: " << this->interestRate << "% and time is " << this->interestTime << "years total interest amount for " << this->balance << "is:" << this->interest << endl;
        display();
    }
    void calculateInterestAndAdd()
    {
        interest = (this->balance) * pow((1 + interestRate / 100), interestTime);
        interest = interest - balance;
        cout << "\nInterest rate is: " << this->interestRate << "% and time is " << this->interestTime << "years total interest amount for " << this->balance << "is:" << this->interest << endl;
        display();
        balance = balance + interest;
        cout << "After Calculating interest, the main balance is :" << this->balance << endl;
    }
};

float CurrentAccount::min = 500;
float CurrentAccount::penalty = 100;
float SavingsAccount::interestRate = 12;
float SavingsAccount::interestTime = 1;

void clearIgnore()
{
    cin.clear();
    cin.ignore();
}
int main()
{
    CurrentAccount currentAccount;
    SavingsAccount savingAccount;
    int choice;
    int ch;

    cout << "Enter '1' for current and '2' for saving  Account: ";
    cin >> ch;
    if (ch == 1)
    {
        currentAccount.getDetails("current");
        currentAccount.checkBalance();
        while (choice != 4)
        {

            cout << "\n 1.Display \n 2.Deposit \n 3.Withdraw \n 4.Exit \n";
            cout << "Enter you choice:";
            cin >> choice;
            if (choice == 1)
            {
                currentAccount.display();

                clearIgnore();
            }
            else if (choice == 2)
            {
                currentAccount.depositMoney();
                clearIgnore();
            }
            else if (choice == 3)
            {
                currentAccount.withdrawMoney();
                clearIgnore();
            }
            else if (choice == 4)
            {
                cout << "\n ---Program End --- " << endl;
                cout << "\n ---Thank you--- " << endl;
                break;
            }
            else
            {
                cout << "please choice valid input" << endl;
                clearIgnore();
            }
        }
    }
    else if (ch == 2)
    {
        savingAccount.getDetails("saving");
        savingAccount.display();
        while (choice != 6)
        {

            cout << "\n 1.Display \n 2.Deposit \n 3.Withdraw \n 4.calculate Interest \n 5.calculate Interest And Add \n 6.Exit \n";
            cout << "Enter you choice:";
            cin >> choice;
            if (choice == 1)
            {
                savingAccount.display();
                clearIgnore();
            }
            else if (choice == 2)
            {
                savingAccount.depositMoney();
                clearIgnore();
            }
            else if (choice == 3)
            {
                savingAccount.withdrawMoney();
                clearIgnore();
            }
            else if (choice == 4)
            {
                savingAccount.calculateInterest();
                clearIgnore();
            }
            else if (choice == 5)
            {
                savingAccount.calculateInterestAndAdd();
                clearIgnore();
            }
            else if (choice == 6)
            {
                cout << "\n ---Program End --- " << endl;
                cout << "\n ---Thank you--- " << endl;
                break;
            }
            else
            {
                cout << "please choice valid input" << endl;
                clearIgnore();
            }
        }
    }
    else
    {
        cout << "Enter valid input";
    }
    return 0;
}