#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.hpp"
using namespace std;

// 常用遍历算法 for_each

// 普通函数
void print01(int val)
{
    cout << val << " ";
}

// 仿函数
struct MyPrint
{
    void operator()(int val)
    {
        cout << val << " ";
    }
};

struct AddOne
{
    void operator()(int &a) { a += 1; } 
};


void test01()
{
    vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for_each(v.begin(), v.end(), print01);
    cout << endl;

    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;

    // 元素都加一
    for_each(v.begin(), v.end(), AddOne());
    printVec(v);

    
}

// 常用遍历算法 transform
// 搬运容器到另一个容器中，同时可以做一些运算

struct Transform
{
    int operator()(int a)
    {
        return a;
    }
};

void test02()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i)
        v.push_back(i);

    vector<int> vTar(v.size()); // 需要提前开辟空间
    transform(v.begin(), v.end(), vTar.begin(), Transform());
    for_each(vTar.begin(), vTar.end(), MyPrint());
    cout << endl;
}


int main()
{
    test01();
}