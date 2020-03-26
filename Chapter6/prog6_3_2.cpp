// prog6_3_2.cpp : 有返回值的函数：每条return必须返回一个值
//

#include <iostream>
#include <string>
#include <vector>

// 给定计数值、单词、结束符，判断计数值是否大于1，是则返回单词的复数形式
std::string make_plural(size_t ctr, const std::string& word, const std::string& ending)
{
    return (ctr > 1) ? word + ending : word;
}


// 返回引用
const std::string& shorterString(const std::string& s1, const std::string& s2)
{
    return s1.size() <= s2.size() ? s1 : s2;      // 返回更短的字符串，返回类型是引用
}
// 不能返回局部对象的引用或指针！！！！！
/*
const std::string& manip(std::string s)
{
    //std::string ret = s;
    if (!s.empty())
        return s;// ret;              // 错误：不能返回局部对象的引用
    else
        return "Empty";               // 错误："Empty"是一个局部临时量
}
*/


// 调用一个返回引用的函数得到的是左值
char& get_val(std::string& str, std::string::size_type ix)
{
    return str[ix];
}


// 列表初始化返回值
std::vector<std::string> process(std::string actual, std::string expected)
{
    if (expected.empty())
        return {};            // 返回一个空 vector 对象
    else if (actual == expected)
        return { "functionX","okay" };         // 返回列表初始化的 vector 对象
    else
        return { "functionX",expected, actual };
}


int main()
{
    std::string s1 = make_plural(1, "apple", "s");
    std::string s2 = make_plural(2, "apple", "s");
    std::string s3 = make_plural(3, "watch", "es");
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;

    std::cout << shorterString(s3, s2) << std::endl;
    //std::cout << manip(s1) << std::endl;               // manip函数编写错误

    // 调用一个返回引用的函数得到的是左值，可以对 返回类型是非常量引用 的函数 的结果 赋值
    std::string s("a value");
    std::cout << s << std::endl;
    get_val(s, 0) = 'A';               // s 的首字符将被赋值为 'A'
    std::cout << s << std::endl;
    //shorterString("hi", "bye") = "X";      // 错误：返回类型是 常量引用 的函数，不可以这样子赋值

    return 0;
}

// 