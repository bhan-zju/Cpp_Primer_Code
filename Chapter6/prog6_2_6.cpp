// prog6_2_6.cpp : 含有可变形参的函数
//

#include <iostream>
#include <string>
#include <initializer_list>

// initializer_list 类型的参数
void error_msg(std::initializer_list<std::string> il)
{
    for (auto beg = il.begin(); beg != il.end(); ++beg)
        std::cout << *beg << " ";
    std::cout << std::endl;
}

int main()
{
    std::string actual, expected = "LinDaiyu";
    std::cin >> actual;
    if (expected != actual)
        error_msg({ "functionX",expected,actual });
    else
        error_msg({ "functionX","okey" });


    return 0;
}

// 