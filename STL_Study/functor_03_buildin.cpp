#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

// 内建仿函数 算术仿函数

// negate 一元仿函数 取反仿函数
void test01()
{
    negate<int> n;
    cout << n(50) << endl;
}

// plus 二元仿函数 加法
void test02()
{
    plus<int> p;
    cout << p(10, 20) << endl;
}

template<class T>
void printVector(vector<T> &v)
{
    for (auto x:v) cout << x << " ";
    cout << endl;
}

// 内建仿函数 关系仿函数
// 大于 greater
void test03()
{
    vector<int> v{10, 30, 40, 20, 50};
    printVector(v);

    // greater 内建仿函数
    sort(v.begin(), v.end(), greater<int>());
    printVector(v);
}

// 内建仿函数 逻辑仿函数
// 逻辑非 logical_not
void test04()
{
    vector<bool> v{1, 0, 1, 0};
    for (auto x: v) cout << x << " ";
    cout << endl;

    // 利用逻辑非 将容器v 搬运到v2中，并执行取反操作
    vector<bool> v2{0,0,0,0};
    // v2.resize(v.size());
    transform(v.begin(), v.begin()+2, v2.begin(), logical_not<bool>());
    printVector(v2);
}

int main()
{
    test04();
}