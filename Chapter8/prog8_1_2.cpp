// prog8_1_2.cpp : IO对象的条件状态
//

#include <iostream>

int main()
{
    int ival;

    auto old_state = std::cin.rdstate();
    std::cout << old_state
        << " " << std::cin.bad()
        << " " << std::cin.fail()
        << " " << std::cin.eof()
        << " " << std::cin.good() << std::endl;

    std::cin >> ival;                    // 分别尝试读入 3 ，e ，ctrl+z
    std::cout << std::cin.rdstate() 
        << " " << std::cin.bad()
        << " " << std::cin.fail() 
        << " " << std::cin.eof() 
        << " " << std::cin.good() << std::endl;

    // 复位failbit 和 badbit，保持eofbit不变
    std::cin.clear(std::cin.rdstate() & ~std::cin.failbit & ~std::cin.badbit);
    std::cout << std::cin.rdstate()
        << " " << std::cin.bad()
        << " " << std::cin.fail()
        << " " << std::cin.eof()
        << " " << std::cin.good() << std::endl;

    // 所有条件状态复位
    std::cin.clear();
    std::cout << std::cin.rdstate()
        << " " << std::cin.bad()
        << " " << std::cin.fail()
        << " " << std::cin.eof()
        << " " << std::cin.good() << std::endl;

    std::cin.setstate(old_state);
    std::cout << std::cin.rdstate()
        << " " << std::cin.bad()
        << " " << std::cin.fail()
        << " " << std::cin.eof()
        << " " << std::cin.good() << std::endl;
}

//