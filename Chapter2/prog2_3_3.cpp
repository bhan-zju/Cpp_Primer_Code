// prog2_3_3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
    int ival = 1024;
    int* pi = &ival;    // 指针
    int** ppi = &pi;    // 指针的指针

    std::cout << "The value of ival\n"
        << "direct value: " << ival << "\n"
        << "indirect value: " << *pi << "\n"
        << "double indierect value: " << **ppi << std::endl;

    **ppi = 512;
    std::cout << "The value of ival\n"
        << "direct value: " << ival << "\n"
        << "indirect value: " << *pi << "\n"
        << "double indierect value: " << **ppi << std::endl;

    int i = 42;
    int *p;           // 指针
    int *&r = p;      // 指针p的引用

    r = &i;
    std::cout << "*p = " << *p << std::endl;

    *r = 21;
    std::cout << "*p = " << *p << std::endl;
}

// 