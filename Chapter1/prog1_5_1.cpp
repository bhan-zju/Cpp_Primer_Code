// prog1_5_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item book;
    std::cin >> book;         //读入ISBN号、售出的册数以及销售价格
    std::cout << book << std::endl;    //写入ISBN号、售出的册数、总销售额和平均价格

    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    std::cout << item1 + item2 << std::endl;
    return 0;
}

// 