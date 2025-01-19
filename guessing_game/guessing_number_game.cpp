#include <iostream>
#include<ctime>
using namespace std;

int main()
{
    int user_input, random_number, attempt = 0;

    cout << "Welcome to the guessing number game !" << endl;

    //random number generation
    srand(time(0));
    random_number = rand() % 100 + 1;
    do
    {
        cout << "Enter a number between 1 to 100: ";
        cin >> user_input;


        if (user_input<1 || user_input >101)
        {
            cout << "Invalid input"<<endl;
            continue;
        }

        attempt++;

        if (user_input == random_number)
        {
            cout << "Congratulations ! you win." << endl;
            cout<<"attempt :"<< attempt<<endl;
            break;
        }
        else if (user_input > random_number)
        {
            cout << "Your number is greater than the random number." << endl;
        }
        else
        {
            cout << "your number is less than random number." << endl;
        }
    
    } while (true);
    return 0;
}
