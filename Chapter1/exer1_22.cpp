// exer1_22.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 读取多个具有相同ISBN的销售记录，输出所有记录的和

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item sum, book;
    std::cin >> book;
    sum = book;
    while (std::cin >> book)
        sum += book;
    std::cout << sum << std::endl;
    return 0;
}

// 