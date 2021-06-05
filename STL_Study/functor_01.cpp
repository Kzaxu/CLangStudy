#include <iostream>
using namespace std;


// 函数对象（仿函数）

// 使用类实现像函数调用一样的操作
// 同时可以使用成员变量记录一些状态

struct MyAdd
{
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};

// 1. 函数对象调用时可以像普通函数那样调用
void test01()
{
    MyAdd myAdd;
    cout << myAdd(10, 20) <<endl;
}

// 2. 函数对象超出了普通函数的概念，函数对象可以有自己的状态
// 例如保存函数被调用了多少次
struct MyPrint
{
    int count; // 状态，调用次数

    MyPrint(): count(0) {}

    void operator()(string test) 
    {   
        ++count;
        cout << test << endl;
    }
};

void test02()
{
    MyPrint myPrint;
    myPrint("hello world");
    myPrint("hello world");
    myPrint("hello world");
    myPrint("hello world");

    cout << "myPrint 调用次数为：" << myPrint.count << endl;
}


// 3. 函数对象可以作为参数传递

void doPrint(MyPrint &mp, string test)
{
    mp(test);
}

void test03()
{
    MyPrint mp;
    doPrint(mp, "hello c++");
}


int main()
{
    test03();
}