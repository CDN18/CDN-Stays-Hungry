#include<iostream>
using namespace std;
int main()
{
    double distance, consumption;
    cout << "Enter the distance(km):";
    cin >> distance;
    cout << "Enter the gas consumption(L):";
    cin >> consumption;
    cout << "Your car consumes " << consumption * 100 / distance << " litres of gas per 100 km.";
    return 0;
}