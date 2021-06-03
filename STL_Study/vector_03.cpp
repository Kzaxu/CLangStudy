#include <iostream>
#include <vector>
using namespace std;


template<class T>
void printVector(const vector<T> &v)
{
    for (auto x: v) cout << x << " ";
    cout << endl;
}

// vector 预留空间
void test01()
{
    vector<int> v;
    //  利用reserve 预留空间
    v.reserve(100000);
    int num = 0;
    int *p = NULL;
    for (int i = 0; i < 100000; ++i)
    {
        v.push_back(i);
        if ( p != &v[0])
        {
            p = &v[0];
            ++num;
        }
    }
    cout << "num = " << num << endl;
        
}

int main()
{
    test01();
}