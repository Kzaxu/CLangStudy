#include <iostream>
using namespace std;

template <class T>
void mySort(T arr[], int length)
{
    int ind_max;
    T value_tmp;
    for (int i = 0; i < length; ++i)
    {
        ind_max = i;
        for (int inner_ind = i + 1; inner_ind < length; ++inner_ind)
        {
            if (arr[inner_ind] > arr[ind_max])
            {
                ind_max = inner_ind;
            }
        }
        value_tmp = arr[i];
        arr[i] = arr[ind_max];
        arr[ind_max] = value_tmp;
    }
}

template <class T>
void printArray(T *arr, int num)
{
    for (int i = 0; i < num; ++i)
    {
        cout << arr[i];
    }
    cout << endl;
}
int main()
{
    int a[] = {3, 2, 1, 4};
    char b[] = "adcbe";
    mySort(a, sizeof(a) / sizeof(int));
    printArray(a, sizeof(a) / sizeof(int));
    mySort(b, sizeof(b) / sizeof(char));
    printArray(b, sizeof(b) / sizeof(char));
}