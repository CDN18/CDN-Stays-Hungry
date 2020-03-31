#include<iostream>
using namespace std;
int main()
{
    const int convertor = 12;
    double height = 0;
    cout << "Input your height(foot):______\b\b\b\b\b\b";
    cin >> height;
    cout << "Your height is " << (int)height / 12 << " inch " << height - (int)height + (int)height % 12 << " feet.";
    return 0;
}