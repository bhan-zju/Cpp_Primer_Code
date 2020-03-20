// exer5_3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
    int sum = 0, val = 1;
    while (val <= 10)
        sum += val, ++val;
    std::cout << sum << std::endl;

    return 0;
}

// 