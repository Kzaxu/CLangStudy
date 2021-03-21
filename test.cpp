#include "function.h"
using namespace std;

struct Phone
{
    string name;
    // int price;
    Phone(string b)
    {
        this->name = b;
    }
};

void ff(char *b)
{
    while (*b != '\0')
    {
        cout << *b++;
    }
}

int &add()
{
    int *a = new int(10);
    return *a;
}

Phone *test()
{
    return new Phone("aaa");
}

int main()
{
    int a = 6;
    int b = 3;
    cout << a+b;
}
