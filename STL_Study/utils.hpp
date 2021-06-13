#ifndef _UTILES_H_
#define _UTILES_H_
#include <vector>
#include <iostream>


std::vector<int> range(int start, int end, int step)
{
    std::vector<int> v;
    if (step > 0)
        for (int i = start; i < end; i += step)
            v.push_back(i);
    else
        for (int i = start; i > end; i += step)
            v.push_back(i);
    return v;
}

std::vector<int> range(int start, int end)
{
    return range(start, end, 1);
}

std::vector<int> range(int end)
{
    return range(0, end, 1);
}

template<class T>
void printVec(const std::vector<T> &v)
{
    for (auto x:v) std::cout << x << " ";
    std::cout << std::endl;
}

#endif
