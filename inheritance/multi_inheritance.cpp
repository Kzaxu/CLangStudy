#include <iostream>
using namespace std;

struct Base1
{
    int m_A;
    Base1():m_A(100) {}
};

struct Base2
{
    int m_A;
    Base2():m_A(200) {}

};

struct Son : Base1, Base2
{
    int m_C;
    int m_D;
    Son() : m_C(10), m_D(20) {}
};

void test1()
{
    Son s;
    cout << s.Base1::m_A << endl;
    cout << s.Base2::m_A << endl;
}

int main()
{
    test1();
}