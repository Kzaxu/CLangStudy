#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void initVec(vector<int> &v)
{
    v.clear();
    for (int i = 0; i < 10; ++i)
        v.push_back(i);
}

// 谓词 - 返回bool类型的仿函数被称为谓词
// 一元谓词
struct GreaterFive
{
    bool operator()(int a)
    {
        return a > 5;
    }
};

void test01()
{
    vector<int> v;
    initVec(v);

    // 查找容器中 有没有大于5的数字
    // GreaterFive() 匿名函数对象
    auto it = find_if(v.begin(), v.end(), GreaterFive()); // 找到一段迭代区间内谓词为真的迭代器
    if (it == v.end())
        cout << "未找到" << endl;
    else
        cout << "找到了大于5的数字为：" << *it << endl;
}

// 二元谓词
struct MyCompare
{
    bool operator()(int a, int b) { return a > b; }
};

void test02()
{
    vector<int> v{10, 40, 20, 30, 50};

    sort(v.begin(), v.begin() + 3);
    for (auto x : v)
        cout << x << " ";
    cout << endl;

    // 使用仿函数改变算法策略，变为排序规则从大到小
    sort(v.begin(), v.begin() + 3, MyCompare());
    for (auto x : v)
        cout << x << " ";
    cout << endl;
}

int main()
{
    test02();
}