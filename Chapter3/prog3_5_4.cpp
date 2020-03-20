// prog3_5_4.cpp : C风格字符串
//

#include <iostream>
#include <string>
#include <cstring>

int main()
{
    // 定义一个C风格字符串，存放在字符数组中并以空字符结束
    char ca[] = { 'C','+','+','\0' };
    std::cout << strlen(ca) << std::endl;          // strlen(ca) 返回ca的长度

    // 字符串比较
    // 标准库string对象的比较
    std::string s1 = "A string example", s2 = "A different string";
    std::cout << (s1 > s2) << std::endl;          // 直接用 >,< 等符号比较
    // C风格字符串的比较
    const char ca1[] = "A string example";
    const char ca2[] = "A different string";
    //std::cout << (ca1 > ca2) << std::endl;          // 错误：试图比较两个无关的地址
    std::cout << strcmp(ca2, ca1) << std::endl;       // 如果ca1=ca2，strcmp(ca1, ca2)返回0；如果ca1>ca2，返回一个正值；如果ca1<ca2，返回一个负值

    // 字符串的连接和拷贝
    // 标准库string对象
    std::string largeStr1 = s1 + " " + s2;        // 直接相加
    std::cout << largeStr1 << std::endl;
    // C风格字符串
    //char largeStr2[] = ca1 + ca2;               // 错误：不能将两个指针相加
    char largeStr2[36];
    strcpy_s(largeStr2, ca1);                     // 将 ca1 拷贝给largeStr2，largeStr2的大小必须计算正确，不能小于ca1的大小17
    std::cout << largeStr2 << std::endl;
    strcat_s(largeStr2, " ");        // 在largeStr2末尾加一个空格，largeStr2末尾必须有足够空位置
    std::cout << largeStr2 << std::endl;
    strcat_s(largeStr2, ca2);        // 将ca2连接到largeStr2后面，largeStr2末尾必须有足够空位置
    std::cout << largeStr2 << std::endl;

    // exercise 3.37
    const char ca3[] = { 'h','e','l','l','o','\0' };
    const char* cp = ca3;
    while (*cp) {
        std::cout << *cp << std::endl;
        ++cp;
    }

    return 0;
}

// 