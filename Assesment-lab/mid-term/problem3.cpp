/** Write a program to find the largest among three entered numbers by the user and display whether the
largest number is prime or not */
#include <iostream>
using namespace std;

bool isprime(int num)
{
    if (num == 0 || num == 1)
    {
        return false;
    }
    else
    {
        for (int i = 2; i <= num / 2; ++i)
        {
            if (num % i == 0)
            {
                return false;
                break;
            }
        }
    }
    return false;
}
int highestNumber(int num1, int num2, int num3)
{
    if (num1 >= num2 && num1 >= num3)
        return num1;

    if (num2 >= num1 && num2 >= num3)
        return num2;

    if (num3 >= num1 && num3 >= num2)
        return num3;

    return 0;
}
int main()
{
    float num1, num2, num3;

    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;

    if (highestNumber(num1, num2, num3) == num1)
    {
        if (isprime(num1))
            cout << num1 << " number is prime and largest";
        else
            cout << num1 << " number is not prime and largest";
    }
    if (highestNumber(num1, num2, num3) == num2)
    {
        if (isprime(num2))
            cout << num2 << " number is prime and largest";
        else
            cout << num2 << " number is not prime and largest";
    }
    if (highestNumber(num1, num2, num3) == num3)
    {
        if (isprime(num3))
            cout << num3 << " number is prime and largest";
        else
            cout << num3 << " number is not prime and largest";
    }

    return 0;
}