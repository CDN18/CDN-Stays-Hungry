#include<iostream>
using namespace std;
int main()
{
    const int inch_foot = 12;
    const float foot_meter = 0.0254;
    const float kilo_pound = 2.2;
    double inch, foot;
    cout << "Please input your height,it should be two figures separated with a space,the first is inch and the second is foot:";
    cin >> inch >> foot;
    double height = (foot + inch * inch_foot) * foot_meter;
    double pound;
    cout << "Then input your weight(pounds):";
    cin >> pound;
    double weight = pound / kilo_pound;
    double BMI = weight / height / height;
    cout << "Your BMI:" << BMI;
    return 0;
}