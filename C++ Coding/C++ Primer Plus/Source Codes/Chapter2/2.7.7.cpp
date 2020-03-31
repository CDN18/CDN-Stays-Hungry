#include<iostream>
using namespace std;

int main()
{
    cout << "Enter the number of hours:";
    int hours, mins;
    cin >> hours;
    cout << "Enter the number of minutes:";
    cin >> mins;
    if(mins>60)
    {
        hours += mins / 60;
        mins %= 60;
    }
    hours %= 24;
    cout << "Time:" << hours << ":" << mins;
    return 0;
}