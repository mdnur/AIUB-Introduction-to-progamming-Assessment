#include <iostream>
#include <cstring>
using namespace std;
class Employee{
    private:
        string name;
        int yearOfJoining;
        float salary;
        string address;
    public:
        void setName(string name)
        {
            this->name = name;
        }
        void setYearOfJoining(int yearOfJoining)
        {
            this->yearOfJoining = yearOfJoining;
        }
        void setSalary(float salary)
        {
            this->salary = salary;
        }
        void setAddress(string address)
        {
            this->address = address;
        }

        void display()
        {
           cout << "Name" << '\t' << "Year of Joning " << '\t' << "Salary" << '\t' << "address" << endl;
           cout << this->name << "\t" << this->yearOfJoining << "\t\t" << this->salary << '\t' << this->address << endl;
        }
    

};
int main()
{
    Employee e1;
    e1.setName("Robert");
    e1.setYearOfJoining(1994);
    e1.setSalary(80000);
    e1.setAddress("64C- WallsStreat");
    e1.display();

     Employee e2;
    e2.setName("Sam");
    e2.setYearOfJoining(2000);
    e2.setSalary(70000);
    e2.setAddress("68D- WallsStreat");
    e2.display();



     Employee e3;
    e3.setName("John");
    e3.setYearOfJoining(1999);
    e3.setSalary(75000);
    e3.setAddress("26B- WallsStreat");
    e3.display();


    return 0;
}