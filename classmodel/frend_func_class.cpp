#include <string>
#include <iostream>
using namespace std;


// 必须在使用类前提前声明。
class Building;
// 由于 Gay 类中的函数会使用到 Building 类中的变量，此时要么提前定义 Building 类中的成员变量，要么稍后定义。
class Gay
{
private:
    Building *building;

public:
    Gay();
    void fvisit();
    void visit();
    
};

class GoodGay;
void visit(const Building *b);

class Building
{
    friend class GoodGay;
    friend void visit(const Building *b);
    friend void Gay::fvisit();

private:
    string m_BeddingRoom;

public:
    string m_SittingRoom;
    Building();
};

class GoodGay
{
private:
    Building *building;
public:
    GoodGay();
    void visit();
};

Gay::Gay()
{
    this->building = new Building;
}

void Gay::fvisit()
{
    cout << "f visit: " << building->m_BeddingRoom << endl;
}

void Gay::visit()
{
    cout << "common visit: " << this->building->m_SittingRoom << endl;
    // 不是友元无法访问私有变量
    // cout << "common visit: " << this->building->m_BeddingRoom << endl;
}

GoodGay::GoodGay()
{
    this->building = new Building;
}

void GoodGay::visit()
{
    cout << "GoodGay visit: " << this->building->m_SittingRoom <<endl;
    cout << "GoodGay visit: " << this->building->m_BeddingRoom <<endl;
}

Building::Building()
{
    this->m_SittingRoom = "Sitting Room";
    this->m_BeddingRoom = "Bedding Room";
}

void visit(const Building *b)
{
    cout << "global visit: " << b->m_SittingRoom <<endl;
    cout << "global visit: " << b->m_BeddingRoom <<endl;
}

void test()
{     
    Building b;
    Gay g;
    GoodGay gg;
    // 不能直接初始化类的指针，例如直接 Building *building; 此时 building 是一个空指针，并没有初始化
    // 也可以 Building *buidling = new Building; 但是此时变量建立在堆区，无法自动释放，需要手动 delete。
    visit(&b);
    g.fvisit();
    g.visit();
    gg.visit();

}

int main()
{
    test();
}
