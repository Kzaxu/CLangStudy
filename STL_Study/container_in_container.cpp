#include <iostream>
#include <vector>
using namespace std;

void pushNum(vector<int> &v)
{
    for (int i = 0; i < 4; ++i)
        v.push_back(i);
}

void test01()
{
    vector<vector<int> > v;
    vector<int> v1;
    pushNum(v1);
    vector<int> v2;
    pushNum(v2);
    vector<int> v3;
    pushNum(v3);
    vector<int> v4;
    pushNum(v4);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    // for (vector<vector<int> >::iterator it = v.begin(); it != v.end(); ++it)
    // {
    //     for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); ++vit)
    //         cout << *vit << " ";
    //     cout << endl;
    // }

    // for (auto x : v)
    // {
    //     for (auto y : x)
    //         cout << y << " ";
    //     cout << endl;
    // }
    cout << v[0][0];
}

int main()
{
    test01();
}