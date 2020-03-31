#include<iostream>
using namespace std;
int main()
{
    long long globalpopu, uspopu;
    cout << "Enter the world's population:";
    cin >> globalpopu;
    cout << "Enter the population of the US:";
    cin >> uspopu;
    cout << "The population of the US is " << double(uspopu) * 100 / globalpopu << "% of the world population.";
    return 0;
}