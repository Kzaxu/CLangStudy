#include <iostream>
using namespace std;

struct Base
{
    int m_A;
    Base() : m_A(100) {}
    void print()
    {
        cout << "the func in Base" <<endl;
    }
    void print(string a)
    {
        cout << "the func in Base and " << a <<endl;
    }
};

struct Son : Base
{
    int m_A;
    Son() : m_A(200) {}
    void print()
    {
        cout << "the func in Son" <<endl;
    }
};

void test1()
{
    Son s;
    cout << sizeof(s) << endl;
    cout << s.m_A << endl;
    cout << s.Base::m_A << endl;
}

void test2()
{
    Son s;
    s.print();
    s.Base::print();
    // 如果子类中出现和父类同名的函数，会隐藏父类中所有同名函数，无法发生重载
    // s.print("test"); 会报错，必须加上作用域
    s.Base::print("test111");

}

int main()
{
    test2();
}