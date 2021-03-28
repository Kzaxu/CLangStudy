#include <iostream>
using namespace std;

struct Animal
{
    int m_Age;
};

struct Sheep : virtual Animal
{
};

struct Camel : virtual Animal
{
};

struct SheepCamel : Sheep, Camel
{
};

void test1()
{
    // SheepCamel 虚继承数据形式
    // +---
    // | +--- (base class Sheep)
    // | | {vbptr} (virtual base pointer)
    // | +---
    // | +--- (base class Camel)
    // | | {vbptr}
    // | +---
    // +---
    // +--- (virtual base Animal)
    // |m_Age
    // +---
    // SheepCamel::$vbtable@Sheep@:(virtual base table 记录引用数据的 offset)
    // SheepCamel::$vbtable@Camel@:
    // vbptr->offst->data，实际上根据 offset 找到的 m_Age 是同一份数据。
    SheepCamel sc;
    sc.Sheep::m_Age = 10;
    sc.Camel::m_Age = 20;
    cout << sc.Sheep::m_Age << endl;
    cout << sc.Camel::m_Age << endl;
    // 如果不是虚继承，下面会报错。
    cout << sc.m_Age << endl;

}

int main()
{
    test1();
}