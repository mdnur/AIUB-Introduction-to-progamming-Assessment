/**
Amazon Bangladesh LTD. uses the following policies for its drivers to be insured within the company.
a. To get Type A insurance, driver's age must be between 25-45. Driver's gender must be
male, and driver must not have any previous accidents. E.g. 0.
b. To get Type B insurance, driver's age must be between 18-24 or 46-60 and gender must
be male. Driver may have 1-3 accidents in past.
c. To get Type C insurance for female drivers: age must be 25-34 and no accidental records
in past

In any other case, driver cannot be insured, and he/she will not be allowed to drive. Write a
program for Amazon Bangladesh where a driver can enter his/her age as integer, gender as
‘m’ or ‘f’ and accident record as integer to check the type of insurance he/she has in the company 

 */
#include <iostream>
using namespace std;
int main()
{
    int age;
    char gender;
    int accident_record;
    cout << "Enter you age :";
    cin >> age;
    cout << "Enter you gender (m/f) only: ";
    cin >> gender;
    cout << "Enter you accident record(interger): ";
    cin >> accident_record;

    if (age >= 25 && age <= 45 && gender == 'm' && accident_record == 0)
    {
        cout << "He will get the type A insurance" << endl;
    }
    else if (((age >= 18 && age <= 24) || (age >= 46 && age <= 60)) && gender == 'm' && accident_record <= 3)
    {
        cout << "He will get the type B insurance" << endl;
    }
    else if (age >= 25 && age <= 34 && gender == 'f' && accident_record == 0)
    {
        cout << "She will get the type C insurance" << endl;
    }
    else
    {
        cout << "He or She will not get any type  insurance" << endl;
    }

    return 0;
}