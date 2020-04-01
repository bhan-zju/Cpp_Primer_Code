// exer6_54.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

int add(int a, int b)
{
    return a + b;
}
int subtract(int a, int b)
{
    return a - b;
}
int multiply(int a, int b)
{
    return a * b;
}
int divide(int a, int b)
{
    return a / b;
}

int main()
{
    std::vector<int(*)(int, int)> vec;
    std::vector<decltype(add)*> vec2;

    vec.push_back(add);
    vec.push_back(subtract);
    vec.push_back(multiply);
    vec.push_back(divide);

    std::cout << vec[0](10, 2) << std::endl;
    std::cout << vec[1](10, 2) << std::endl;
    std::cout << vec[2](10, 2) << std::endl;
    std::cout << vec[3](10, 2) << std::endl;

    return 0;
}

// 