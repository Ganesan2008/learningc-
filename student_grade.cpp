#include <iostream>
using namespace std;

int main()
{
    string name;
    int a;
    float Total = 0;

    string sub_name[5] = {"Tamil", "English", "Maths", "Science", "Social"};
    cout << "Enter student name : " << endl;


    getline(cin, name);
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter student mark for below subject:" << endl;
        cout << sub_name[i] << endl;
        cin >> a;
        if (a < 0 || a > 100)
        {
            cout << "invalid mark" << endl;
        }
        Total += a;
        cout << sub_name[i] << "grade :" << a << endl;
    };
    cout << "Student name:" << name << endl;
    cout << "Total mark of the student is :" << Total << "/500" << endl;

    if (Total > 175)
    {
        cout << "Pass" << endl;
    }
    else
    {
        cout << "Fail" << endl;
    }
    return 0;
}