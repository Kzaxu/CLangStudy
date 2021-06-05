#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "utils.hpp"
using namespace std;

// 常用排序算法 sort
void test01()
{
    vector<int> v{10, 30, 50, 20, 40};

    // 利用 sort 排序（默认升序）
    sort(v.begin(), v.end());
    printVec(v);

    // 改变为降序排序
    sort(v.begin(), v.end(), greater<int>());
    printVec(v);
}


// 常用排序算法 random_shuffle
void test02()
{
    vector<int> v = range(10);

    // 根据时间设置随机种子
    srand((unsigned int) time(nullptr));
    // srand(100);

    // 随机将原有容器元素打乱
    random_shuffle(v.begin(), v.end(), [](int n) { return rand() % n; });
    printVec(v);

    random_shuffle(v.begin(), v.end(), [](int n) { return rand() % n; });
    printVec(v);

    // todo random_shuffle 不一定调用rand 这个随机数生成器。

}   


// 常用排序算法 merge
// 两个有序序列合并，并存储到另一个容器中
void test03()
{
    vector<int> v1 = range(10);
    vector<int> v2 = range(1, 11);

    vector<int> vTar(v1.size()+v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTar.begin());
    printVec(vTar);
    
}


// 常用排序算法 reverse
// 将容器中的元素进行反转

void test04()
{
    vector<int> v{10 ,30, 50, 20, 40};

    cout << "反转前：" << endl;
    printVec(v);

    reverse(v.begin(), v.begin()+3);
    cout << "反转后：" << endl;
    printVec(v);

}

int main()
{
    test04();
}