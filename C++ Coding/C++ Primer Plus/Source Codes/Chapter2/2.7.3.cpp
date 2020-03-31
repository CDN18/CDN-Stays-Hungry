#include<iostream>

using namespace std;

void cout1();
void cout2();

int main()
{
    cout1();
    cout1();
    cout2();
    cout2();
    return 0;
}

void cout1()
{
    cout << "Three blind mice" << endl;
}

void cout2()
{
    cout << "See how they run" << endl;
}