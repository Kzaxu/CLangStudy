#include <iostream>
#include <map>
using namespace std;

template<class T1, class T2>
void printMap(map<T1, T2> &m)
{
    for (auto x: m)
        cout << "key: " << x.first << ", value: " << x.second << endl;
    cout << endl;
}

// map 容器构造与赋值
void test01()
{   
    // 创建 map 容器
    map<int, int> m;

    // 四种插值方式
    m.insert(pair<int, int>(1, 10));
    m.insert({2, 20});
    m[3] = 30;
    m.insert(make_pair(4,40));

    printMap(m);

    // 拷贝构造
    map<int, int> m2(m);
    printMap(m2);

    // 赋值
    map<int, int> m3;
    m3 = m;
    printMap(m3);

    // 列表初始化
    map<int, int> m4 = {
        {1, 10}, {2, 20}, {3, 30}, {4, 40}
    };
    printMap(m4);
    
}

// map 大小和交换
// 大小
void test02()
{
    map<int, int> m = {
        {1, 10}, {2, 20}, {3, 30},
    };
    
    if (m.empty())
        cout << "m为空" << endl;
    else
    {
        cout << "m不为空" << endl;
        cout << "m的大小为：" << m.size() << endl;
    }
    
}

// 交换
void test03()
{
    map<int, int> m1= {
        {1, 10}, {2, 20}, {3, 30},
    };

    map<int, int> m2 = {
        {3, 30}, {4, 40}, {5, 50},
    };

    cout << "交换前: " << endl;;
    printMap(m1);
    printMap(m2);

    m1.swap(m2);
    cout << "交换前: " << endl;;
    printMap(m1);
    printMap(m2);
}

int main()
{
    test03();
}