#include <iostream>
#include <vector>
using namespace std;


template<class T>
void printVector(const vector<T> &v)
{
    for (auto x: v) cout << x << " ";
    cout << endl;
}

// vector 容器构造
void test01()
{
    vector<int> v1; // 默认无参构造
    for (int i = 0; i<10 ; ++i) v1.push_back(i);
    printVector(v1);

    // 通过区间方式构造
    vector<int> v2(v1.begin(), v1.begin()+3);
    printVector(v2);

    // n个element构造
    vector<int> v3(10, 100);
    printVector(v3);
    vector<int> v6(10); // 默认element为0
    printVector(v6);

    // 拷贝构造
    vector<int> v4(v3);
    printVector(v4);

    // 数组赋值
    vector<int> v5 = {1,2,3,4};
    printVector(v5);

}


// vector 容器赋值
void test02()
{
    vector<int> v1;
    for (int i = 0; i<10; ++i) v1.push_back(i);
    
    // operator= 
    vector<int> v2;
    v2 = v1;
    printVector(v2);

    // assign
    vector<int> v3;
    v3.assign(v1.begin(), v1.begin()+3);
    printVector(v3);

    // n个element 赋值
    vector<int> v4;
    v4.assign(10, 100);
    printVector(v4);
}

int main()
{
    test01();
}