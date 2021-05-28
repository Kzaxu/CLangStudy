#include <fstream>
#include <iostream>
#include <ctime>
#include <unistd.h>
using namespace std;

int main()
{
    clock_t start_Time, end_Time;
    start_Time = clock();
    time_t now = time(0);
    tm *ltm = localtime(&now); // time 结构体
    string time_String = ctime(&now);
    string time_String2 = to_string(1900 + ltm->tm_year) + "-" + to_string(1 + ltm->tm_mon) + "-" + to_string(ltm->tm_mday) + " " + to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
    char buf[64];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", ltm);
    cout << now << endl;
    cout << time_String2 << endl;
    cout << buf << endl;
    end_Time = clock();
    cout << "spend time: " << (float)(end_Time - start_Time)/CLOCKS_PER_SEC << "s" << endl;
}