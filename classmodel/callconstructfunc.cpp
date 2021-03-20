#include "function.h"
using namespace std;

struct Person
{
    string name;
    int age;
    Person()
    {
        name = "null";
        age = -1;
        cout << "调用无参数构造函数" << endl;
    }
    Person (const int &a)
    {
        name = "null";
        age = a;
        cout << "调用有参数构造函数" << endl;
    }
    Person(const string &n, const int &a)
    {
        name = n;
        age = a;
        cout << "调用有参数构造函数" << endl;
    }
    Person(const Person &p)
    {
        name = p.name;
        age = p.age;
        cout << "调用复制参数构造" << endl;
    }
    void getInfo()
    {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
    }
};

int main()
{
    // 初始化类的几种方式
    // 1. 直接声明
    Person p1("xuxu", 27);
    Person p2;
    Person p3(p1);
    // 2. 括号内什么都没有会被认为是函数
    Person p4();
    p1.getInfo();
    p2.getInfo();
    p3.getInfo();
    // 会报错 p4.getInfo();

    // 显式初始化类
    Person p5 = Person("xuxu", 27);
    Person p6;
    Person p7 = Person(p1);
    p5.getInfo();
    p6.getInfo();
    p7.getInfo();

    // 隐式初始化方法
    Person p8 = 10;
    // 拷贝构造的本质
    Person p9 = p1;
}