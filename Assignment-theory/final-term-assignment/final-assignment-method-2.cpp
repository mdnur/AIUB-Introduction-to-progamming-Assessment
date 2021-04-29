#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Account
{
protected:
    string customer_name;
    int acc_no;
    double balance;
    string type_of_account;

public:
    void setData(string customer_name, int acc_no, double balance, string type_of_account)
    {
        this->customer_name = customer_name;
        this->acc_no = acc_no;
        this->balance = balance;
        this->type_of_account = type_of_account;
    }
    void withdraw(float amount)
    {
        if (this->balance > amount)
        {
            cout << "Withdraw amount: " << amount << endl;
            this->balance -= amount;
        }
    }
    void deposit(float amount)
    {
        cout << "Deposit amount: " << amount << endl;
        this->balance += amount;
    }
    void display()
    {
        cout << "Customer Name:" << this->customer_name << endl;
        cout << "Acc_no:" << this->acc_no << endl;
        cout << "Account Balance Name:" << this->balance << endl;
        cout << "Account Type:" << this->type_of_account << endl;
    }
    void updateBal()
    {
        cout << "Updated balanced is :" << this->balance << endl;
    }
};

class Current : public Account
{
private:
    double servicecharge;
    string chequebook;

public:
    void issueCheque()
    {
        cout << "ChequeBook is issued";
    }
    void checkBal()
    {
        if (this->balance < 500)
        {
            this->imposePenalty();
        }
    }
    void imposePenalty()
    {
        this->balance -= 150;
        cout << "Reduced 150tk from you account for impose penalty. Because you kept under 500" << endl;
    }
};

class Saving : public Account
{
private:
    float interest;

public:
    void computeInterest()
    {
        double rate = 12;
        int times = 1;

        interest = balance * (pow((1 + rate / 100), times));

        interest = interest - balance;
        cout << "Total interest is :" << interest << endl;
    }
    void depositInterest()
    {
        this->balance += this->interest;
    }
};

int main()
{
    cout << "====User 1 Saving====" << endl;
    Current cus1;
    cus1.setData("John Doe", 1234568787, 25000, "current");
    cus1.display();
    cus1.withdraw(15000);
    cus1.updateBal();
    cus1.deposit(50000);
    cus1.updateBal();
    cus1.issueCheque();
    cus1.checkBal();
    
    
    cout << endl;

    cout << endl;

    cout << "====User 2 Saving =====" << endl;

    Saving cus2;
    cus2.setData("John Doe 2", 987654242, 45000, "saving");
    cus2.display();
    cus2.withdraw(15000);
    cus2.updateBal();
    cus2.deposit(50000);
    cus2.updateBal();
    cus2.computeInterest();
    cus2.depositInterest();
    cus2.updateBal();

    return 0;
}