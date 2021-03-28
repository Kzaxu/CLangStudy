#include <iostream>
using namespace std;

struct Base
{
    static int m_A;
    static void print()
    {
        cout << "print in Base" <<endl;
    }
};
int Base::m_A = 10;

struct Son : Base
{
    static int m_A;
    static void print()
    {
        cout << "print in Son" <<endl;
    }
};
int Son::m_A = 20;

void test1()
{
    // 通过对象访问
    Son s;
    cout << "m_A in Son : " << s.m_A << endl;
    cout << "m_A in Base: " << s.Base::m_A << endl;

    // 通过类名访问
    cout << "m_A in Son : " << Son::m_A << endl;
    cout << "m_A in Base: " << Son::Base::m_A << endl;
}

void test2()
{
    // 通过对象访问
    Son s;
    s.print();
    s.Base::print();

    // 通过类名访问
    Son::print();
    Son::Base::print();

}


int main()
{
    test2();
}