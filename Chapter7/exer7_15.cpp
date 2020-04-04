// exer7_15.cpp : 添加构造函数
//

#include <iostream>
#include "Person.h"

int main()
{
    // 使用构造函数
    Person lin;
    Person pin("PinEr", "YoufengLaiyi");
    Person dai(std::cin);

    print(std::cout, lin);
    std::cout << std::endl;
    print(std::cout, pin);
    std::cout << std::endl;
    print(std::cout, dai);
    std::cout << std::endl;

    return 0;
}

// 