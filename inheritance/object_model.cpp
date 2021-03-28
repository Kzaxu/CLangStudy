#include <iostream>
using namespace std;

class Base
{
public:
    int m_A;
};

class Son : public Base
{
public:
    int m_B;
    Son(int a, int b)
    {
        m_A = a;
        m_B = b;
    }
};

void test()
{
    Son s(2,3);
    // 子类会将父类的变量一并储存在内。
    cout << "Son 所占的内存大小為：" << sizeof(s) << endl;
}

int main()
{
    test();
}