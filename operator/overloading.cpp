#include <iostream>
using namespace std;

// 运算符重载，+ << ++ = == ()。
// 全局运算符重载，类运算符重载。
struct Person
{
    int m_Age;

    Person(int a) : m_Age(a) {}
    Person operator+(Person &p)
    {
        Person temp = *this;
        temp.m_Age += p.m_Age;
        return temp;
    }

    Person &operator++()
    {
        ++m_Age;
        return *this;
    }

    Person operator++(int)
    {
        Person temp = *this;
        ++m_Age;
        return temp;
    }
    void operator()(int a)
    {
        if (m_Age < a)
        {
            cout << "猜的年龄过大" << endl;
        }
        else if (m_Age > a)
        {
            cout << "猜的年龄过小" << endl;
        }
        else
        {
            cout << "猜对了" << endl;
        }
    }
};

struct Person2
{
    int *m_Age;
    Person2(int a)
    {
        m_Age = new int(a);
    }
    Person2(Person2 &p)
    {
        if (m_Age != NULL)
        {
            delete m_Age;
        }
        m_Age = new int(*p.m_Age);
    }
    ~Person2()
    {
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
    }
    Person2 &operator=(Person2 &p)
    {
        if (m_Age != NULL)
        {
            delete m_Age;
        }
        m_Age = new int(*p.m_Age);
        return *this;
    }

    bool operator==(Person2 &p)
    {
        if (*m_Age == *p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// 重要，此处要用 const reference。
ostream &operator<<(ostream &cout, const Person &p)
{
    cout << "age of person is " << p.m_Age;
    return cout;
}

void test()
{
    Person p1(10), p2(20);
    // 函数接受到 rvalue 如果有 const 修饰，会延长 rvalue 的生命周期直至函数调用结束，
    // 也可使使用 Person&& 接受 rvalue，但是不兼容 一般的 lvalue。
    // 所以左移重载运算符中 Person 需要 const 修饰，否则下面一句报错。
    cout << (p1 + p2) << endl;
    cout << p1 << " " << p2 << endl;
    cout << ++(++p1) << " " << p1 << endl;
    cout << p2++ << " " << p2 << endl;

    Person2 p3(10), p4(20);
    p3 = p4;
    cout << "p3 value: "<<*p3.m_Age << " address: " << p3.m_Age << endl;
    cout << "p4 value: "<<*p4.m_Age << " address: " << p4.m_Age << endl;

    int a = -1;
    cout << "请猜测p1年龄：";
    cin >> a;
    p1(a);

}

int main()
{
    test();
}