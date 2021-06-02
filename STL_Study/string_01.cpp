#include <iostream>
using namespace std;

// 字符串初始化
void test01()
{
    string s1;
    const char *str = "hello world";
    string s2(str);
    string s3(s2);
    string s4(10, 'a');

    cout << "s1: " << s1 <<endl;
    cout << "s2: " << s2 <<endl;
    cout << "s3: " << s3 <<endl;
    cout << "s4: " << s4 <<endl;
}

// 字符串赋值操作
void test02()
{
    string s1;
    s1 = "hello world";
    cout << "s1: " << s1 <<endl;

    string s2;
    s2 = s1;
    cout << "s2: " << s2 << endl;

    string s3;
    s3 = 'a';
    cout << "s3: " << s3 << endl;
   
    string s4;
    s4.assign("hello cpp");
    cout << "s4: " << s4 << endl;

    string s5;
    s5.assign("hello cpp", 5);
    cout << "s5: " << s5 << endl;
    
    string s6;
    s6.assign(10, 'a');
    cout << "s6: " << s6 << endl;

}

// 字符串拼接
void test03()
{
    string s1 = "我爱玩游戏";
    s1 += "爱玩游戏";
    cout << "s1: " << s1 << endl;

    string s3 = "I";
    s3.append(" love ");
    cout << "s3: " << s3 << endl;
    s3.append("game abcde", 4);
    cout << "s3: " << s3 << endl;
    
    string s2 = "LOL DNF";
    s3.append(s2, 3, 4); // append s2[3:3+4]
    cout << "s3: " << s3 << endl;
}


int main()
{
    test03();
}