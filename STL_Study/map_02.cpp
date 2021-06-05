#include <iostream>
#include <map>
using namespace std;

template<class T1, class T2>
void printMap(const map<T1, T2> &m)
{
    for (auto x: m)
        cout << "key: " << x.first << ", value: " << x.second << endl;
    cout << endl;
}

// map 容器 插入和删除
void test01()
{
    map<int, int> m;

    m.insert(pair<int,int>(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(map<int, int>::value_type(3, 30));
    m[4] = 40;

    // [] 不建议用作插入，用途：可以利用 key 来访问 value
    cout << m[4] << endl;
    printMap(m);

    // 相当于 dict update 操作，但是冲突时保留原有值！！！
    map<int, int> m2 = {
        {3, 50},
    };
    m2.insert(m.begin(), m.end());
    printMap(m2);

    // 删除
    m.erase(m.begin());
    printMap(m);

    m.erase(3); // 按照 key 来删除
    printMap(m);

    m.erase(m.begin(),++m.begin());
    printMap(m);
}

// insert 和 [] 取值的区别
void test00()
{
    map<int, int> m = {{1,2}};
    m.insert(make_pair(1,5));
    printMap(m);
    m[1] = 5;
    printMap(m);
}

// map 容器查找与统计
void test02()
{
    map<int, int> m = {
        {1, 10}, {2, 20}, {3, 30},
    };
    auto pos = m.find(4);
    if (pos != m.end())
        cout << "查到了key: " << pos->first << " value: " << pos->second << endl;
    else
        cout << "未找到元素" << endl;

    // 统计
    bool num = m.count(3); // map 要么是0 要么是 1
    cout << "num: " << num << endl;
}

struct MyCompare
{
    bool operator()(int v1, int v2) const
    {
        // 降序
        return v1 > v2;
    }
};


// map 容器中的排序
void test03()
{
    map<int, int> m = {
        {1, 10}, {2, 20}, {3, 30}, {4, 40}, {5, 50}
    };
    printMap(m);

    // 改为从大到小的规则排序
    map<int, int, MyCompare> m2 = {
        {1, 10}, {2, 20}, {3, 30}, {4, 40}, {5, 50}
    };
    for (auto x: m2)
        cout << "key: " << x.first << ", value: " << x.second << endl;
    cout << endl;
}

int main()
{
    test03();


}