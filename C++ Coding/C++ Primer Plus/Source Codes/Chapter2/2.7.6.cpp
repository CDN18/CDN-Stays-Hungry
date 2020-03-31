#include<iostream>
using namespace std;

double convert(double lightyear);

int main()
{
    cout << "Enter the number of light years:";
    double lightyr;
    cin >> lightyr;
    cout << lightyr << " light years = " << convert(lightyr) << " astronomical units.";
    return 0;
}

double convert(double lightyear)
{
    return 63240 * lightyear;
}