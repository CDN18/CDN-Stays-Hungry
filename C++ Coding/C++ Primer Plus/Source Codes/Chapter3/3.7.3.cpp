#include<iostream>
using namespace std;
int main()
{
    const int convertor = 60;
    cout << "Enter a latitude in degrees, minutes, and seconds:" << endl
         << "First, enter the degrees:";
    double degree, minute, second;
    cin >> degree;
    cout << "Next, enter eht minutes of arc:";
    cin >> minute;
    cout << "Finally, enter the seconds of arc:";
    cin >> second;
    cout << degree << " degrees, " << minute << " minutes, " << second << " seconds = " << degree + minute / 60 + second / 60 / 60 << " degrees";
    return 0;
}