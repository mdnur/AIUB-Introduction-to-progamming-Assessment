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
    float score;
    bool validInput;

public:
    Student()
    {
        validInput = true;
    }
    void SetStudentDetails(string StuName, string StuID, string CourseName) // Show studentName, Id, Coursename, Grade
    {
        this->StuName = StuName;
        this->StuID = StuID;
        this->CourseName = CourseName;
    }
    float QuizMarksCal(float quiz1, float quiz2) //50 marks highest for adding 2 quizzes
    {
        this->quizMarks = quiz1 + quiz2;
        if (this->quizMarks > 50)
        {
            this->quizMarks = 0;
            this->validInput = false;
            cout << "Quiz Marks should not be higher than 50 .Maximum value of any quiz should be 25" << endl;
            return 0;
        }
        this->score += this->quizMarks;
        return this->quizMarks;
    }

    float PerformCal(float per1, float per2) //50 marks highest for adding 2 performs
    {
        this->PerforMarks = per1 + per2;
        if (this->PerforMarks > 50)
        {
            this->PerforMarks = 0;
            this->validInput = false;
            cout << "Perform Marks  should not be higher than 50 .Maximum value of any perform should be 25" << endl;
            return 0;
        }
        this->score += this->PerforMarks;
        return this->PerforMarks;
    }
    void CalculateGrade() // grade based on your marks
    {
        if (this->score <= 100)
        {
            if (score >= 90)
            {
                this->grade = "A+";
            }
            else if (score >= 85)
            {
                this->grade = "A";
            }
            else if (score >= 80)
            {
                this->grade = "B+";
            }
            else if (score >= 75)
            {
                this->grade = "B";
            }
            else if (score >= 70)
            {
                this->grade = "C+";
            }
            else if (score >= 65)
            {
                this->grade = "C";
            }
            else if (score >= 60)
            {
                this->grade = "D+";
            }
            else if (score >= 50)
            {
                this->grade = "D";
            }
            else if (score < 50 && score >= 0)
            {
                this->grade = "F";
            }
            else
            {
                cout << "The score is undefined";
            }
        }
    }
    void ShowInfo() // Show studentName, Id, Coursename, Grade
    {
        if (this->validInput != false)
        {
            cout << "Name: \t\t" << this->StuName << endl;
            cout << "ID: \t\t" << this->StuID << endl;
            cout << "CourseName: \t" << this->CourseName << endl;
            cout << "Total Mask: \t" << this->score << endl;
            cout << "grade: \t\t" << this->grade << endl;
        }
        else
        {
            cout << "Enter valid Data input" << endl;
        }
    }
};
int main()
{
    Student st;
    st.SetStudentDetails("Mohammad Nur", "21-44540-1", "Introduction to Progamming lab");
    st.QuizMarksCal(24, 23);
    st.PerformCal(25, 25);
    st.CalculateGrade();
    st.ShowInfo();

    return 0;
}