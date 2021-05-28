#include <iostream>
#include <fstream>
#include <ctime>
#include <unistd.h>
using namespace std;

struct Person
{
    int m_Age;
    char m_Name[64];
    Person(int a, char b[]): m_Age(a)
    {
        strcpy(m_Name, b);
    }
};

void write_file(string path)
{
    ofstream ofs;
    ofs.open(path, ios::out);
    char time_string[64];
    for (int i = 0; i < 100; ++i)
    {   
        long now = time(0);
        tm *ltm = localtime(&now);      
        strftime(time_string, 64, "%Y-%m-%d %H:%M:%S", ltm);
        ofs << time_string << " the time mod 5 is " << now%5 << endl;
        usleep(1000);
    }
    ofs.close();
}

void write_file_bin(string path)
{
    ofstream ofs(path, ios::binary);
    // ofs.open(path, ios::binary);
    Person p= {10, (char*)"Tom"};
    ofs.write((const char*)&p, sizeof(Person));
    ofs.close();

}

int main()
{
    write_file_bin(".\\testdata\\person.bin");
}