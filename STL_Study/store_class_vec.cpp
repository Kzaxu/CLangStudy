#include <iostream>
#include <vector>
using namespace std;

struct Person
{
    string m_Name;
    int m_Age;

    Person(string x, int y): m_Name(x), m_Age(y) {}
    void to_String() 
    {
        cout << "Name: " << m_Name <<endl;
        cout << "Age: " << m_Age <<endl;
    }
};

void test01()
{
    vector<Person> v;

    Person p1("a", 1);
    Person p2("b", 2);
    Person p3("c", 3);
    Person p4("d", 4);
    Person p5("e", 5);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    // for (auto x:v)
    //     x.to_String();
    for (vector<Person>::iterator it = v.begin(); it!=v.end(); ++it)
        (*it).to_String();

}

// 存放自定义数据类型的指针
void test02()
{
    vector<Person*> v;

    Person p1("a", 1);
    Person p2("b", 2);
    Person p3("c", 3);
    Person p4("d", 4);
    Person p5("e", 5);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    for (vector<Person*>::iterator it= v.begin(); it!=v.end();++it)
        (*it)->to_String();
}

int main()
{
    test02();
}