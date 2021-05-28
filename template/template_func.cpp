#include <iostream>
using namespace std;

template <class T, class M>
void printInfo(T t, M m)
{
    cout << t << "\n"
         << m << endl;
}

template <class T>
int my_Add(T t1, T t2)
{
    return t1 + t2;
}

void test0()
{
    int a = 10;
    int *b = &a;
    // 1. 自动类型推导调用方式
    printInfo(b, a);
    // 2. 显式指定类型
    printInfo<int, int *>(a, b);
}

template <class T>
void print()
{
    cout << "just test，print invoked" << endl;
}

void test1()
{
    // print(); 无法推断出 T 的类型，会报错 
    print<int>();
    int a = 10;
    char b = 'a';
    // 会报错，自动推导类型不会强制转换类型
    // cout << my_Add(a, b) <<endl;
    cout << my_Add<int>(a, b) <<endl;
    
}

int main()
{
    test1();
}