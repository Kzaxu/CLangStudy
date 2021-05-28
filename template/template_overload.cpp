#include <iostream>
using namespace std;

// 如果函数模板和普通函数都可以实现，优先调用普通函数
// 可以通过空模板参数列表来强制调用函数模板
// 函数模板也可以发生重载
// 如果函数模板可以产生更好的匹配,优先调用函数模板
void myPrint(int a, int b)
{
    cout << a << " " << b << endl;
    cout << "调用的普通函数" << endl;
}

template <class T>
void myPrint(T a, T b)
{
    cout << a << " " << b << endl;
    cout << "调用的函数模板" << endl;
}

template <class T>
void myPrint(T a, T b, T c)
{
    cout << a << " " << b << endl;
    cout << "调用的重载后函数模板" << endl;
}

struct Person
{
    int m_Age;
    string m_Name;
    Person(int a, string b) : m_Age(a), m_Name(b) {}
};

template <class T>
bool myCmp(T &a, T &b)
{
    return a == b;
}

template <>
bool myCmp(Person &a, Person &b)
{
    return (a.m_Age == b.m_Age & a.m_Name == b.m_Name);
}

int main()
{
    myPrint(1, 2);
    myPrint<>(1, 2);
    myPrint(1, 2, 3);
    myPrint("ab", "cd");
    Person p1(10, "Tom");
    Person p2(10, "Tom");
    Person p3(20, "Tom");
    // 如果没有
    cout << myCmp(p1, p2) << " " << myCmp(p1, p3) << endl;
}