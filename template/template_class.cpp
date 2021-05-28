#include <iostream>
using namespace std;

// 类模板没有自动类型推导的使用方式
// 类模板在模板参数列表中可以有默认参数

template <class AgeType = int, class NameType = string>
struct Person
{
    AgeType m_Age;
    NameType m_Name;
    Person(AgeType a, NameType b) : m_Age(a), m_Name(b) {}
    void showPerson()
    {
        cout << "Name: " << this->m_Name << endl;
        cout << "Age: " << this->m_Age << endl;
    }
};

template <class T>
struct myClass
{
    T obj;

    void showPerson()
    {
        obj.showPerson();
    }

    void showBuilding()
    {
        obj.showBuilding();
    }
};

// 普通类中的成员函数一开始就可以创建
// 类模板中的成员函数在调用时才创建

void test1()
{
    Person<int, string> p1(10, "Tom");
    p1.showPerson();
    // Person p2(20, "Jerry"); 报错，类模板没有自动类型推导的使用方式
    Person<> p2(20, "Jerry");
    p2.showPerson();
    myClass<Person<>> c = {{30, "Alex"}};
    c.showPerson();
    // c.showBuilding(); 执行报错，类模板成员函数调用时才创建，所以编译器不会报错
}

// 类模板做函数参数一共有三种传入方式：
// 指定传入的类型 — 直接显示对象的数据类型
// 参数模板化 — 将对象中的参数变为模板进行传递
// 整个类模板化 — 将这个对象类型 模板化进行传递

void printPerson1(Person<> &p)
{
    cout << "Name: " << p.m_Name << endl;
    cout << "Age: " << p.m_Age << endl;
}

template <class T1, class T2>
void printPerson2(Person<T1, T2> &p)
{
    cout << "Name: " << p.m_Name << endl;
    cout << "Age: " << p.m_Age << endl;
    cout << "T1 name is " << typeid(T1).name() << endl;
    cout << "T2 name is " << typeid(T2).name() << endl;
}

template <class T>
void printPerson3(T &p)
{
    cout << "Name: " << p.m_Name << endl;
    cout << "Age: " << p.m_Age << endl;
    cout << "T name is " << typeid(T).name() << endl;
}

void test2()
{
    Person<> p(10, "Tom");
    printPerson1(p);
    printPerson2(p);
    printPerson3(p);
}
int main()
{
    test2();
}