#include <iostream>
using namespace std;

struct Animal
{
    virtual void vSpeak()
    {
        cout << "this is animal speaking" << endl;
    }
    void speak()
    {
        cout << "this is animal speaking" << endl;
    }
};
struct Cat: Animal 
{
    virtual void vSpeak()
    {
        cout << "this is cat speaking" << endl;
    }
    void speak()
    {
        cout << "this is cat speaking" << endl;
    }
};

void test1(Animal &a)
{
    a.speak();
    a.vSpeak();
}

int main()
{   
    Cat c;
    test1(c);
}