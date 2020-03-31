#include<iostream>
using namespace std;

double convertFromC2F(double c);

int main()
{
    cout << "Please enter a Celsius value:";
    double c;
    cin >> c;
    cout << c << " Celsius is " << convertFromC2F(c) << " degrees Fahrenheit.";
    return 0;
}

double convertFromC2F(double c)
{
    return 1.8 * c + 32.0;
}