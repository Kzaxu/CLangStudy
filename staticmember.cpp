#include <iostream>
using namespace std;

class Person
{   
public:
    void comm()
    {
        cout << "comm 调用成功" << endl;
    }

    static void func(const int &a)
    {   
        p_mA = a;
        // 静态成员函数只能访问静态变量 p_a = a;
        cout << "func 调用成功: " << p_mA << endl;
    }

    static int p_mA;
    int p_a;
};


int Person::p_mA = 10;

void test()
{   

    // 非静态成员必须先实例化后才能访问 报错：Person::comm();
    // 静态变量只有在类体外指定值 报错：int Person::p_mA = 10;
    Person::func(100);
}

int main()
{
    test();
}