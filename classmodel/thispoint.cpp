#include <iostream>
using namespace std;

struct Person
{
    string name;
    int age;
    Person(string a, int b) : name(a), age(b) {}
    Person() : name("ttt"), age(-1) {}
    Person addAge(Person p)
    {
        this->age += p.age;
        // this 表示成员函数所属的对象实例地址，类似 python 中的 self。
        return *this;
    }
    Person &addPersonAge(Person p)
    {
        this->age += p.age;
        return *this;
    }
};

void test()
{
    Person p1("abc", 10);
    Person p2("bcs", 20);
    Person p3("bcs", 20);
    Person p4("bcs", 20);
    //返回值为 Person 时调用拷贝构造函数，下面一行运行完返回的 Person 实例不再是 p2 了。
    p2.addAge(p1).addAge(p1);
    //返回为 Person& 时还是返回的 p3。 
    p3.addPersonAge(p1).addPersonAge(p1);
    cout << "p2 age: " << p2.age << endl;
    cout << "p3 age: " << p3.age << endl;
    Person p5 = p4.addAge(p1).addAge(p1);
    cout << "p5 age: " << p5.age << endl;
}

int main()
{
    test();
}