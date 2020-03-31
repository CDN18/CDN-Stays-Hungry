#include<iostream>
using namespace std;
int main()
{
    cout << "Enter the number of seconds:";
    long long second;
    cin >> second;
    long long day = second / 60 / 60 / 24;
    second = second - day * 24 * 60 * 60;
    int hours = second / 60 / 60;
    second = second - hours * 60 * 60;
    int minutes = second / 60;
    second = second - minutes * 60;
    cout << second << "seconds = " << day << " days, " << hours << " hours, " << minutes << " minutes, " << second << " seconds";
    return 0;
}