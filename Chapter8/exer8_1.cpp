// exer8_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

std::istream& fun(std::istream& is)
{
    std::string st;
    while (is >> st) {
        std::cout << st << std::endl;
    }

    // 对流进行复位
    is.clear();

    return is;
}

int main()
{
    std::istream& is = fun(std::cin);
    std::cout << is.rdstate() << std::endl;
    return 0;
}

