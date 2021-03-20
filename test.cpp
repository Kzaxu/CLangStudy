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
    // Phone p1 = "sadadada", 3;
    // test();
    Phone *p = test();
    cout << p->name << endl;
}
