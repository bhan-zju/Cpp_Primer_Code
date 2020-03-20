// prog3_2_3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <cctype>

int main()
{
    // 范围 for 语句
    std::string str("some string");
    for (auto c : str)                         // 每次循环 c 分别依次被赋值 str 中的其中一个字符
        std::cout << c << std::endl;

    std::string s("Hello, World!!!");
    decltype(s.size()) punct_cnt = 0;          // 与 s.size()同类型(std::string::size_type类型)的参数 punct_cnt，用来记录字符串中标点符号的数量
    for (auto c : s)
        if (std::ispunct(c))           // std::ispunct(c) 判断字符 c 是否为标点符号，用到头文件 cctype
            ++punct_cnt;
    std::cout << punct_cnt << " punctuation characters in " << s << std::endl;

    // 改变字符串里的字符的值，必须把循环变量定义成引用类型
    for (auto &c : s)                  // c 必须是引用类型，否则 c 只是被赋值而不能改变 s 中的字符的值
        c = std::toupper(c);           // std::toupper(c) 将小写字符改成大写，要用到头文件 cctype
    std::cout << s << std::endl;

    // 仅改变一部分字符的值，可以用下标
    if (!str.empty())                       // 确保 str[0] 的位置确实有字符
        str[0] = std::toupper(str[0]);      // 下标从 0 开始，到 str.size()-1   将第一个字母改成大写
    std::cout << str << std::endl;

    // 将第一个词改成大写，依次处理str中的字符直至 处理完全部字符 或 遇到一个空白（空格、横向制表符、纵向制表符、回车符、换行符、进纸符中的一种）
    for (decltype(str.size()) index = 0; index != str.size() && !std::isspace(str[index]); ++index)    // std::isspace(c) 当c为空白时为真
        str[index] = std::toupper(str[index]);
    std::cout << str << std::endl << std::endl;


    // 把 0 ~ 15 之间的十进制数转换成对应的十六进制形式
    const std::string hexdigits = "0123456789ABCDEF";     // 字符串常量
    std::cout << "Enter a series of numbers between 0 and 15 separated by spaces. Hit ENTER when finished: " << std::endl;
    std::string result;           // 用于存放结果
    std::string::size_type n;     // 用于保存从输入流保存的数
    while (std::cin >> n)
        if (n < hexdigits.size())        // 忽略无效的输入
            result += hexdigits[n];      // 得到对应的十六进制数字
    std::cout << "You hex number is " << result << std::endl;

    return 0;

}

// 