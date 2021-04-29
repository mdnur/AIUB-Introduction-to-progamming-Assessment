#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    string names[5];
    int votes[5];
    int i;
    int winner = 0;
    float total = 0.0;
    for (i = 0; i < 5; i++)
    {
        cout << "Enter Candidate names: ";
        cin >> names[i];
        cout << "Enter votes received: ";
        cin >> votes[i];
        total = total + votes[i];
    }
    cout << fixed << showpoint;
    cout << setprecision(2);

    cout << "Candidate Name" << '\t' << "Received Votes" << '\t' << "% of Total Votes" << endl;
    for (i = 0; i < 5; i++)
    {
        cout << names[i] << '\t' << '\t' << '\t' << votes[i] << '\t' << '\t' << (float)(votes[i] / total) * 100.0 << endl;
    }
    cout << "Total" << '\t' << '\t' << '\t' << total << endl;

    cout << endl;
    cout << endl;
    for (i = 1; i < 5; ++i)
    {
        if (votes[0] < votes[i])
        {
            votes[0] = votes[i];
            winner = i;
        }
    }
    cout << "The winner is " << names[winner] << "!" << endl;

    return 0;
}