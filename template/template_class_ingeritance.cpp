#include <iostream>
using namespace std;

template <class T>
struct Base
{
    T m;
};

struct Son1 : Base<int>
{
};

template <class T>
struct Son2 : Base<T>
{};

void test()
{
    Son2<int> s;
    cout << s.m << endl;
}

int main()
{
    test();
}