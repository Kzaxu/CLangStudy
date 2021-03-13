#include "function.h"
using namespace std;

void Student::setInfo()
{
    cin >> name >> num;
}
void Student::showInfo()
{
    cout << name << ":" << num << endl;
}

int Person::multiple(int k)
{
    return a * k;
}
