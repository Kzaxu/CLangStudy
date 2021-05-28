#include <iostream>
using namespace std;

template <class T1, class T2>
struct Person
{
    T1 m_Name;
    T2 m_Age;

    void showPerson();
    Person(T1 a, T2 b);
};

template <class T1, class T2>
Person<T1, T2>::Person(T1 a, T2 b)
{
    this->m_Name = a;
    this->m_Age = b;
}

template <class T1, class T2>
void Person<T1, T2>::showPerson()
{
    cout << "Name: " << this->m_Name << endl;
    cout << "Age: " << this->m_Age << endl;
}

void test()
{
    Person<char*, int> p((char*)"Tom", 10);
    p.showPerson();
}


int main()
{
    test();
}