// prog2_4_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
    int i = 42;
    const int &r1 = i;
    const int &r2 = 42;
    const int &r3 = r1 * 2;
    std::cout << "i = " << i << "\n"
        << "r1 = " << r1 << "\n"
        << "r2 = " << r2 << "\n"
        << "r3 = " << r3 << std::endl << std::endl;

    i = 21;
    std::cout << "i = " << i << "\n"
        << "r1 = " << r1 << "\n"            // r1的值会跟着i变成21
        << "r2 = " << r2 << "\n"
        << "r3 = " << r3 << std::endl << std::endl;

    double dval = 3.14;
    const int &ri = dval;                  // ri 是 int 类型的引用
    std::cout << "dval = " << dval << "\n"
        << "ri = " << ri << std::endl << std::endl;      // ri  = 3
    dval = 6.28;
    std::cout << "dval = " << dval << "\n"
        << "ri = " << ri << std::endl;               // ri 依然为 3

    return 0;
}

