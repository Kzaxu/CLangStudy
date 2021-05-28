#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// vector 存放内置的数据类型

void myPrint(int val)
{
    cout << val << endl;
}

void test01()
{
    // 创建vector容器
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    // 通过迭代器访问数组中数据
    // vector<int>::iterator itBegin = v.begin(); // 起始迭代器，指向容器第一个元素位置
    // vector<int>::iterator itEnd = v.end();     // 结束迭代器，指向的是容器中最后一个元素的下一个元素的位置
    // // 第一种遍历方式
    // while (itBegin!=itEnd)
    //     cout << *itBegin++ <<endl;

    // 第二种遍历方式
    // for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    //     cout << *it << endl;

    // 第三种遍历方式  利用STL提供的遍历算法
    for_each(v.begin(), v.end(), myPrint);
}

int main()
{
    test01();
}