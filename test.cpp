#include "function.h"
using namespace std;

struct Phone
{
    string name;
    Phone(string b): name(b) {}
};

void ff(char *b)
{
    while (*b != '\0')
    {
        cout << *b++;
    }
}

int main()
{   
    string name = "asdadas";
    Phone p("sadada");
    Phone p1 = "sadadada";
}
