#include <iostream>
#include <string>
using namespace std;

struct Person1
{
    string name;
    int age;
    Person1(string a, int b) : name(a), age(b) {}
};

struct Person2
{
    string name;
    Person2(string a) : name(a) {}
};

struct Person3
{
    string name;
    int age;
    Person3(string a, int b) : name(a), age(b) {}
    void getInfo()
    {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
    }
};

void test()
{
    // 成员函数和变量是分开存储的。
    Person1 p1("abc", 10);
    Person2 p2("abc");
    Person3 p3("abc", 10);
    cout <<"the size of p1: " << sizeof(p1) <<endl;
    cout <<"the size of p2: " << sizeof(p2) <<endl;
    cout <<"the size of p3: " << sizeof(p3) <<endl;
}

int main()
{
    test();
}
