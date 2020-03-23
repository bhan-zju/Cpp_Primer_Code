// prog6_1_3.cpp : 分离式编译
//

#include <iostream>
#include "Chapter6.h"            // 无需include fact.cpp

int main()
{
    int val = 5;
    std::cout << val << "! = " << fact(val) << std::endl;
    int ret = func();
    std::cout << "The factorial of this number is " << ret << std::endl;

    int val2 = -10;
    std::cout << "|" << val2 << "| = " << abs(val2) << std::endl;

    return 0;
}

// 