#include <iostream>
using namespace std;

struct Animal
{
    // 如果不加 virtual，在 delete 父类指针时不会调用子类的析构函数。
    // 如果子类有成员变量是指针，可能造成内存泄漏。
    // 虚析构和纯虚析构是为了解决通过父类指针释放子类对象的问题。
    virtual ~Animal()
    {
        cout << "正在调用Animal析构函数"<<endl;
    }
    virtual void speak() = 0;
};

struct Cat : Animal
{
    string *m_Name;
    Cat(string name)
    {
        m_Name = new string(name);
    }
    
    ~Cat()
    {
        if (m_Name != NULL)
        {
            delete m_Name;
            m_Name = NULL;
        }
        cout << "正在调用Cat析构函数"<<endl;
    }
    virtual void speak()
    {
        cout << *m_Name << " is speaking" << endl;
    }
};
void test1()
{   
    Animal *a = new Cat("Tom");
    a->speak();
    delete a;
}

int main()
{
    test1();
}