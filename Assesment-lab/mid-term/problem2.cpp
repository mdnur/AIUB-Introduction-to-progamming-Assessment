/** Write a program that has three arrays: float quiz1Marks[n], float quiz2Marks[n], float
bestQuiz[n]. Here n is the number of students in a class. The user will provide input for quiz 1 and
quiz 2 and the program will compare the best marks for students. Best marks will be then stored in
bestQuiz[n] array. Finally, the program will print the value of bestQuiz[n]. 
 */
#include <iostream>
using namespace std;

int main()
{
    int n;
    float quiz1Marks[n];
    float quiz2Marks[n];
    float bestQuiz[n];
    cout << "How many student in the class:";
    cin >> n;

    cout << "First Quiz " << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter marks quiz1 for roll " << i  << " :";
        cin >> quiz1Marks[i];
    }

    cout << "second Quiz " << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter marks quiz2 for roll " << i  << " :";
        cin >> quiz2Marks[i];
    }
    for (int i = 0; i < n; ++i)
    {
        if (quiz2Marks[i] > quiz1Marks[i])
        {
            bestQuiz[i] = quiz2Marks[i]; 
        }else{
            bestQuiz[i] = quiz1Marks[i]; 
        }
    }

    

    cout << "best number for each student "  << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << "Best marks for roll " << i + 1 << " is " <<   quiz2Marks[i] << endl;
    }
    return 0;
}