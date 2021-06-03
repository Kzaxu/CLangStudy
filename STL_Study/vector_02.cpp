#include <iostream>
#include <vector>
using namespace std;


template<class T>
void printVector(const vector<T> &v)
{
    for (auto x: v) cout << x << " ";
    cout << endl;
}

// vector 容器的容量大小操作
void test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; ++i) v1.push_back(i);
    

    if (v1.empty()) // 为真表示为空
        cout << "vector 容器为空" << endl;
    else
        cout << "vector 容器不为空" << endl;

    cout << "v1 的容量为：" << v1.capacity() << endl;
    cout << "v1 的元素个数为" << v1.size() << endl;

    // 重新指定大小
    v1.resize(15);      
    printVector(v1); // 如果重新指定的比原来size大，默认使用0来填充新的位置
    v1.resize(16, 1); // 指定1为默认填充的元素
    printVector(v1);

    v1.resize(5); // 如果重新指定的比原来的size小，超出部分直接删除
    printVector(v1);
    
}

// vector 容器的插入和删除
void test02()
{
    vector<int> v1;
    // 尾插
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    printVector(v1);

    // 尾删
    v1.pop_back();
    printVector(v1);

    // 插入 第一个参数是迭代器
    v1.insert(v1.begin()+1, 100);
    printVector(v1);

    v1.insert(v1.begin(), 2, 1000);
    printVector(v1);

    // 删除 参数也是迭代器
    v1.erase(v1.begin());
    printVector(v1);

    v1.erase(v1.begin(), v1.begin()+3);
    printVector(v1);

    // 清空 等价于 v1.erase(v1.begin(), v1.end())
    v1.clear();
    printVector(v1);

}

// vector 容器 数据存取 
void test03()
{

    // vector 数据存取
    vector<int> v1 = {2,4,6,8,10,12};
    cout << v1[0] << " " << v1.at(0) << endl;
    cout << "第一个元素为：" << v1.front() << endl;
    cout << "最后一个元素为：" << v1.back() << endl;

}

// vector 容器互换
void test04()
{
    vector<int> v1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v2;
    for (auto rit = v1.rbegin(); rit != v1.rend(); ++rit)
        v2.push_back(*rit);

    cout << "交换前：" << endl;
    printVector(v1);
    printVector(v2);

    v1.swap(v2);
    cout << "交换后：" << endl;
    printVector(v1);
    printVector(v2);
}


// vector 容器互换应用
// 巧用swap可以收缩内存空间
void test05()
{
    vector<int> v;
    for (int i = 0; i < 100000; ++i)
        v.push_back(i);
    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的元素个数为：" << v.size() << endl;

    v.resize(3);
    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的元素个数为：" << v.size() << endl;

    // vector<int> (v) 匿名对象调用拷贝构造函数，初始元素个数、容量都为3
    // vector<int> (v).swap(v) v指向先前匿名对象内存，匿名对象指向之前v对应的大vector
    // 本行结束时，匿名对象占用内存释放，也就是先前v占用空间，而v指向的则是匿名对象创建的小空间。
    vector<int> (v).swap(v);
    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的元素个数为：" << v.size() << endl;
}

int main()
{
    test05();
}