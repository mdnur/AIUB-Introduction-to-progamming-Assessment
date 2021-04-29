#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

class Marks
{
public:
    int rollNumber;
    char *name;
    int *marks;
    int num_marks;

    void GenerateMarks(int num)
    {
        num_marks = num;
        marks = new int[num];

        for (int i = 0; i < num; i++)
            marks[i] = rand() % 5 + 1;
    }

    int sumOfMarks()
    {
        int sum = 0;

        for (int i = 0; i < num_marks; i++)
            sum += marks[i];

        return sum;
    }

    double avarage()
    {
        return round(((double)sumOfMarks() / num_marks) * 100) / 100;
    }

    void setMarks(int numberOfMarks, int newmarks)
    {
        marks[numberOfMarks] = newmarks;
    }

    int getMarks(int numberOfMarks)
    {
        return marks[numberOfMarks];
    }

    void setNumMarks(int num)
    {
        num_marks = num;

        delete[] marks;

        marks = new int[num];
    }

    ~Marks()
    {
        delete[] marks;
    }
};

class Physics : public Marks
{

public:
};

class Chemistry : public Marks
{
public:
};

class Mathematics : public Marks
{

public:
};

int main()
{
    int num;

    cout << "Enter the number of students ";
    cin >> num;

    Physics *CalcPhys = new Physics[num];         // array of student with marks in physics
    Chemistry *CalcChem = new Chemistry[num];     // array of student with marks in chemistry
    Mathematics *CalcMath = new Mathematics[num]; // array of student with marks in mathematics

    for (int i = 0; i < num; i++)
    { // Generate marks and roll numbers

        CalcPhys[i].rollNumber = CalcChem[i].rollNumber = CalcMath[i].rollNumber = i + 1;

        CalcPhys[i].GenerateMarks(9);
        CalcChem[i].GenerateMarks(5);
        CalcMath[i].GenerateMarks(2);
    }

    cout << "\nThe total marks of each student of a class in Physics, Chemistry and Mathematics: \n\n";

    for (int i = 0; i < num; i++)
    {
        cout << "Roll number of student is " << CalcPhys[i].rollNumber << endl;

        cout << "The total marks in Physics is " << CalcPhys[i].sumOfMarks() << endl;
        cout << "The total marks in Chemistry is " << CalcChem[i].sumOfMarks() << endl;
        cout << "The total marks in Mathematics is " << CalcMath[i].sumOfMarks() << endl;

        cout << endl;
    }

    cout << endl
         << "--------------------------" << endl;

    cout << "\nThe average marks : \n\n";

    for (int i = 0; i < num; i++)
    {
        cout << "Roll number of student is " << CalcPhys[i].rollNumber << endl;

        cout << "The average mark in Physics is " << CalcPhys[i].avarage() << endl;
        cout << "The average mark in Chemistry is " << CalcChem[i].avarage() << endl;
        cout << "The average mark in Mathematics is " << CalcMath[i].avarage() << endl;

        cout << endl;
    }

    return 0;
}