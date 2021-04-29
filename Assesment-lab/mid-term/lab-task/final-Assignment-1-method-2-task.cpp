#include <iostream>
#include <cstring>
using namespace std;

class Student
{
private:
    string StuName;
    string StuID;
    string CourseName;
    float quizMarks;
    float PerforMarks;
    string grade;

public:
    void SetStudentDetails(string sName, string SID, string cName)
    {
        StuName = sName;
        StuID = SID;
        CourseName = cName;
    }
    float QuizMarksCal(float quiz1, float quiz2)
    {
        quizMarks = quiz1 + quiz2;
        if (quizMarks > 50)
        {
            cout << "Quiz Marks should not be higher than 50 .Maximum value of any quiz should be 25" << endl;
            return 0;
        }
        return quizMarks;
    }

    float PerformCal(float per1, float per2)
    {
        PerforMarks = per1 + per2;
        if (PerforMarks > 50)
        {
            cout << "Perform Marks  should not be higher than 50 .Maximum value of any perform should be 25" << endl;
            return 0;
        }
        return PerforMarks;
    }
    void CalculateGrade()
    {
        float total = quizMarks + PerforMarks;
        if (total <= 100)
        {
            if (total >= 90)
            {
                grade = "A+";
            }
            else if (total >= 85)
            {
                grade = "A";
            }
            else if (total >= 80)
            {
                grade = "B+";
            }
            else if (total >= 75)
            {
                grade = "B";
            }
            else if (total >= 70)
            {
                grade = "C+";
            }
            else if (total >= 65)
            {
                grade = "C";
            }
            else if (total >= 60)
            {
                grade = "D+";
            }
            else if (total >= 50)
            {
                grade = "D";
            }
            else if (total < 50 && total >= 0)
            {
                grade = "F";
            }
            else
            {
                cout << "The total is undefined";
            }
        }
    }
    void ShowInfo()
    {
        cout << "Name:" << StuName << endl;
        cout << "ID:" << StuID << endl;
        cout << "CourseName: " << CourseName << endl;
        cout << "grade:" << grade << endl;
    }
};
int main()
{
    Student st;
    st.SetStudentDetails("Sirajul Shalahin", "21-44553-1", "Introduction to Progamming lab");
    st.QuizMarksCal(20, 24);
    st.PerformCal(21, 15);
    st.CalculateGrade();
    st.ShowInfo();

    return 0;
}