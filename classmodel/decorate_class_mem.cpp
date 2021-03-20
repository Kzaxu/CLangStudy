#include <iostream>
using namespace std;

struct Person
{
    int m_Age;
    mutable int m_B;
    // this 指针是一个指针常量
    Person(int a) : m_Age(a) {}
    void showAge() const
    {
        // const 修饰的成员函数不允许修改成员变量
        // this->m_Age = 10;
        // 成员变量使用 mutable 可以修改
        this->m_B = 10;
        cout << "age: " << this->m_Age << endl;
        cout << "m_B: " << this->m_B << endl;
    }
    void changeAge() {}
};

void test1()
{
    Person p(1);
    p.showAge();
}

void test2()
{
    Person const p(1);
    // const 修饰的对象不允许修改成员变量，但是 mutable 修饰后的除外。
    // p.m_Age = 10;
    p.m_B = 10;
    // const 修饰的对象只能调用 const 修饰的成员函数。
    // p.changeAge();
}
int main()
{
    test1();
}
