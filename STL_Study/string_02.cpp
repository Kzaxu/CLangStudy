#include <iostream>
using namespace std;

// 字符串 增删改查

// 字符串查找和替换

// 查找
void test01()
{
    string str1 = "abcdefgde";

    int pos = str1.find("de"); // 返回字符串"de"第一次出现的位置，如果没有返回-1 

    if (pos==-1)
        cout << "未找到字符串" <<endl;
    else
        cout <<  "找到字符串，" << "pos = " << pos << endl;

    // rfind 和 find 的区别
    // rfind 从右往左查找
    pos = str1.rfind("de");
    cout << "pos = " << pos <<endl;
}

// 替换
void test02()
{
    string str1 = "abcdefg";
    // 从一号位置起的三个字符替换为 “1111”
    str1.replace(1, 3, "1111");

    cout << "str1: " << str1 <<endl;
}

// 字符串之间的比较，主要用于比较两个字符串是否相等。

void test03()
{
    string s1 = "hxllo";
    string s2 = "hello";

    if (s1.compare(s2)==0)
        cout << "s1 等于 s2" <<endl;
    else if (s1.compare(s2) > 0)
        cout << "s1 大于 s2" <<endl;
    else
        cout << "s1 小于 s2" <<endl;
        
}


// string 字符存取

void test04()
{
    string s1 = "hello";

    // 通过 [] 访问单个字符
    for (int i = 0; i < s1.size(); ++i)
        cout << s1[i] << " ";
    cout << endl;

    // 通过 at 访问单个字符
    for (int i = 0; i < s1.size(); ++i)
        cout << s1.at(i) << " ";
    cout << endl;

    for (auto x:s1)
        cout << x << " ";
    cout << endl;

    // 修改单个字符
    s1[0] = 'x';
    cout << "s1: " << s1 << endl;
    s1.at(2) = 'x';
    cout << "s1: " << s1 << endl;
}


// string 插入和删除

void test05()
{
    string str = "hello";
    
    // 插入
    str.insert(1, "1111"); // 在位置1 插入字符串 “1111”，输出 “h1111ello”
    cout << "str: " << str << endl;

    // 删除
    str.erase(1, 4);
    cout << "str: " << str << endl;
}

// string 字串

void test06()
{
    string str = "abcdef";

    string subStr = str.substr(1,3); // 从位置1 开始截取三个字符
    cout << "subStr: " << subStr << endl;

}

// 实用操作
void test07()
{
    string email = "hello@sina.com";
    
    // 从邮件地址中获取 用户名信息
    int pos = email.rfind('@');
    cout << "用户名为：" << email.substr(0, pos);
}


int main()
{
    test07();
}