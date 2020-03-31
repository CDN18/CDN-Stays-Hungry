#include<iostream>
using namespace std;
int main()
{
    double Lp100km;
    cout << "Enter how much litre of gas ur car comsumps per 100km:";
    cin >> Lp100km;
    cout << "It's equal to " << 1 / (Lp100km / 3.875) * 62.14 << " mpg." << endl;
    return 0;
}