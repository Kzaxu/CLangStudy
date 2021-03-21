#include <iostream>
using namespace std;

struct Person
{
    int *m_Age;

    Person(int a)
    {
        m_Age = new int(a);
    }
    // 如果不更改拷贝构造函数在某些情况下，delete 同一个地址会报错。
    Person(Person &p)
    {
        m_Age = new int(*p.m_Age);
    }
    ~Person()
    {
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
    }
};

void test1()
{
    Person p1(10);
    Person p2 = p1;
    // 此时如果运行 p2 = p1; 依旧是浅拷贝。
    cout << "age of p1 is: " << *p1.m_Age << " address: " << p1.m_Age << endl;
    cout << "age of p2 is: " << *p2.m_Age << " address: " << p2.m_Age << endl;
}

int main()
{
    test1();
}