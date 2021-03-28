#include <iostream>
using namespace std;

struct Base
{
    virtual void func() = 0;
};

struct Son : Base
{
    void func()
    {
        cout << "re constructed function in son class" << endl;
    }
};

struct Son2 : Base
{
};

void test1()
{
    Son s;
    s.func();
    // 抽象类无法直接初始化，必须重写其中的纯虚函数，Base b; 会报错。
    // 如果没有重写也会报错。Son2 s2;
}

int main()
{
    test1();
}