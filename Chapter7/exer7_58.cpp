// exer7_58.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

class Example {
public:
    static double rate;
    static const int vecSize = 20;
    static std::vector<double> vec;
};

const int Example::vecSize;
std::vector<double> Example::vec(vecSize);

int main()
{
    std::cout << "Hello World!\n";
}
