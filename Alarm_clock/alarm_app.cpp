#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
using namespace std;

void Stopwatch(){
    int hours = 0, minutes = 0, seconds = 0;
    while (true){

        cout << "\rStopwatch: "
        << (hours < 10 ? "0" : "") << hours << ":"
        << (minutes < 10 ? "0" : "") << minutes << ":"
        << (seconds < 10 ? "0" : "") << seconds << flush;
    this_thread::sleep_for(chrono::seconds(1));

        seconds++;
    if(seconds>=59){
        seconds=0;
        minutes++;
    }
    if(minutes>=59){
        minutes=0;
        hours++;
    } ;
    if(hours>=23){
        hours=0;
    }

    
    }
}

void timer_funct(int hours, int minutes, int seconds)
{

    while (seconds > 0 || minutes > 0 || hours > 0)
    {
        cout << "\rTime remaining: "
             << (hours < 10 ? "0" : "") << hours << ":"
             << (minutes < 10 ? "0" : "") << minutes << ":"
             << (seconds < 10 ? "0" : "") << seconds << flush;

        // Wait for 1 second before updating
        this_thread::sleep_for(chrono::seconds(1));

        // Decrease the time by 1 second
        if (seconds > 0)
        {
            seconds--;
        }
        else if (minutes > 0)
        {
            minutes--;
            seconds = 59;
        }
        else if (hours > 0)
        {
            hours--;
            minutes = 59;
            seconds = 59;
        }
    }
    if (seconds == 0 && minutes == 0 && hours == 0)
    {
        cout << endl;
        cout << "Timer as been compeleted" << endl;
    }
}

void digitalClock(int hours, int minutes, int seconds)
{
    cout << "Alarm set time: "
         << (hours < 10 ? "0" : "") << hours << ":"
         << (minutes < 10 ? "0" : "") << minutes << ":"
         << (seconds < 10 ? "0" : "") << seconds << endl;

    while (true)
    {
        // Get the current time
        auto now = chrono::system_clock::now();
        time_t currentTime = chrono::system_clock::to_time_t(now);
        tm *ltm = localtime(&currentTime);

        // Convert to Indian Standard Time (IST), which is UTC +5:30
        ltm->tm_hour += 5;
        ltm->tm_min += 30;

        // Adjust for overflow in minutes and hours
        if (ltm->tm_min >= 60)
        {
            ltm->tm_min -= 60;
            ltm->tm_hour += 1;
        }
        if (ltm->tm_hour >= 24)
        {
            ltm->tm_hour -= 24;
        }

        // Display the current time dynamically in a single line with leading zeros
        cout << "\rCurrent time in India: "
             << (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour << ":"
             << (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min << ":"
             << (ltm->tm_sec < 10 ? "0" : "") << ltm->tm_sec << flush;

        // Check if the alarm time matches
        if (ltm->tm_hour == hours && ltm->tm_min == minutes && ltm->tm_sec == seconds)
        {
            cout << "\nALARM! Time's up!" << endl;
            break;
        }

        // Wait for 1 second before updating
        this_thread::sleep_for(chrono::seconds(1));
    }
}
void display()
{
    cout << "Enter the below status " << endl;
    cout << "1. Alarm :" << endl;
    cout << "2. Timer :" << endl;
    cout << "3. Stopwatch :" << endl;
}
int main()
{
    display();
    int choice;
    cout << "Enter the choice : ";
    cin >> choice;
    if (choice == 1)
    {
        cout << "Alarm clock" << endl;
        int hours, minutes, seconds;
        cout << "Enter the Alarm time (HH MM SS): ";
        cin >> hours >> minutes >> seconds;

        digitalClock(hours, minutes, seconds);
    }
    else if (choice == 2)
    {
        cout << "Timer" << endl;
        int hours, minutes, seconds;
        cout << "Enter the time  (HH MM SS): ";
        cin >> hours >> minutes >> seconds;

        timer_funct(hours, minutes, seconds);
    }
    else if (choice == 3)
    {
        cout << "Stopwatch" << endl;
        Stopwatch();
    }
    else
    {
        cout << "Invalid choice" << endl;
    }

    return 0;
}

