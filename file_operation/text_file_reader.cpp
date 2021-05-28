#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Person
{
    int m_Age;
    char m_Name[64];
};


void text_reader(string path)
{
    ifstream ifs;
    ifs.open(path, ios::in);
    if (!ifs.is_open())
    {
        cout << "file open failed" <<endl;
        return;
    }
    // 第一种读取方式
    // char buf[50] = {'\0'};
    // while (ifs.getline(buf, sizeof(buf)))
    // {
    //     cout << buf << endl;
    //     cout << "-----" <<endl;
    // }
    // 第二种读取方式
    string buf;
    while (getline(ifs, buf))
    {
        cout << buf <<endl;
        cout << "----" << endl;
    }
    ifs.close();

}

void read_file_bin(string path)
{
    ifstream ifs(path, ios::binary);
    if (!ifs.is_open())
    {
        cout << "file open failed";
        return;
    }
    Person p;
    ifs.read((char*)&p, sizeof(Person));
    ifs.close();
    cout<<p.m_Name<<"   "<<p.m_Age;
}

int main()
{
    read_file_bin(".\\testdata\\person.bin");
}