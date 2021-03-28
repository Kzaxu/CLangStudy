#include <iostream>
#include <thread>
using namespace std;

void printHello()
{
    cout << "hello!" <<endl;
}

int main()
{
    thread t1(printHello);
    t1.join();
    
}