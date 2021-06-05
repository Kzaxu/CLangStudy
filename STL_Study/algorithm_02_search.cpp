#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.hpp"
using namespace std;

// 常用查找算法 find

// 查找内置数据类型
void test01()
{
    vector<int> v = range(10);

    // 查找容器中是否有 5 整个元素
    auto it = find(v.begin(), v.end(), 15); // 从起始至结束迭代器寻找 5 这个元素
    if (it == v.end())
        cout << "没有找到" << endl;
    else
        cout << "找到：" << *it << endl;
}

// 查找自定义数据类型
struct Person
{
    string m_Name;
    int m_Age;

    void toString()
    {
        cout << "Name: " << m_Name << endl;
        cout << "Age: " << m_Age << endl;
    }

    // 必须重载 == ，否则 find 不知道如何对比
    bool operator==(const Person &p)
    {
        return (p.m_Name == m_Name) & (p.m_Age == m_Age);
    }
};

void test02()
{
    Person p1{"aaa", 10};
    Person p2{"bbb", 20};
    Person p3{"ccc", 30};
    Person p4{"ddd", 40};

    vector<Person> v{p1, p2, p3, p4};

    auto it = find(v.begin(), v.end(), Person{"ccc", 40});
    if (it == v.end())
        cout << "没有找到" << endl;
    else
    {
        cout << "找到：" << endl;
        it->toString();
    }
}

// 常用查找算法 find_if
// 查找内置数据类型
struct GreaterFive
{
    bool operator()(int a)
    {
        return a > 5;
    }
};

void test03()
{
    vector<int> v = range(10);

    auto it = find_if(v.begin(), v.end(), GreaterFive());

    if (it == v.end())
        cout << "没有找到" << endl;
    else
        cout << "找到大于5的数字为：" << *it << endl;
}

// 查找自定义数据类型
struct Greater20
{
    bool operator()(Person &p)
    {
        return p.m_Age > 20;
    }
};

void test04()
{
    vector<Person> v{
        Person{"aaa", 10},
        Person{"bbb", 20},
        Person{"ccc", 30},
        Person{"ddd", 40},
    };

    // 找年龄大于20的人
    auto it = find_if(v.begin(), v.end(), Greater20());
    if (it == v.end())
        cout << "没有找到" << endl;
    else
        cout << "找到年龄大于20的人为：" << it->m_Name << endl;
}

// 查找相邻重复元素 adjacent_find
void test05()
{
    vector<int> v{
        0,
        2,
        0,
        3,
        1,
        4,
        3,
    };
    auto it = adjacent_find(v.begin(), v.end());
    if (it == v.end())
        cout << "没有找到相邻重复元素" << endl;
    else
        cout << "找到相邻重复元素：" << *it << " " << *++it << endl;
}

// 常用查找算法 binary_search
// 查找元素是否存在 binary_search 不同于 find 返回 bool 值
// 但是必须在有序的序列中才能使用
void test06()
{
    vector<int> v = range(10, 0, -1);
    printVec(v);
    // 查找容器中是否有 9 存在
    // 必须有序，如果无序，查找的结果不一定正确
    cout << binary_search(v.begin(), v.end(), 9);
}

// 常用查找算法 count 统计元素个数
// 内置数据类型
void test07()
{
    vector<int> v{10, 40, 30, 40, 20, 40};
    cout << "40的元素个数为：" << count(v.begin(), v.end(), 40) << endl;
}

// 自定义数据类型
struct Person02
{
    string m_Name;
    int m_Age;

    void toString()
    {
        cout << "Name: " << m_Name << endl;
        cout << "Age: " << m_Age << endl;
    }

    // 必须重载 == ，否则 find 不知道如何对比
    bool operator==(const Person &p)
    {
        return (p.m_Age == m_Age);
    }
};
void test08()
{
    vector<Person02> v{
        Person02{"aaa", 10},
        Person02{"bbb", 20},
        Person02{"ccc", 10},
        Person02{"ddd", 30},
    };

    Person p{"eee", 10};
    cout << "age 和 eee 一样的元素个数为：" << count(v.begin(), v.end(), p) << endl;
}

// 常用查找算法 count_if
// count_if 按条件统计元素个数
// 统计内置数据类型
struct GreaterT
{
    bool operator()(int x) { return x > 20; }
};

void test09()
{
    vector<int> v{10, 40, 30, 20, 40, 20};
    cout << "大于20的元素个数为："
         << count_if(v.begin(), v.end(), GreaterT());
}

// 统计自定义数据类型个数

struct AgeGreater20
{
    bool operator()(const Person &x) { return x.m_Age > 20; }
};

void test10()
{
    vector<Person> v{
        Person{"aa", 30},
        Person{"bb", 30},
        Person{"cc", 20},
        Person{"dd", 15},
    };

    cout << "age 大于20的人数个数为："
         << count_if(v.begin(), v.end(), AgeGreater20());
}

int main()
{
    test10();
}