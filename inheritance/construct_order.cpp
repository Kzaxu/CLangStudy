#include <iostream>
using namespace std;

struct Base
{
    Base()
    {
        cout << "Base construct func" << endl;
    }
    ~Base()
    {
        cout << "Base deconstruct func" << endl;
    }
};

struct Son : public Base
{
    Son()
    {
        cout << "Son construct func" << endl;
    }
    ~Son()
    {
        cout << "Son deconstruct func" << endl;
    }
};

void test()
{
    Son s;
}

int main()
{
    test();
}