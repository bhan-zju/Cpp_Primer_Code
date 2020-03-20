// prog5_6_1.cpp : throw表达式：抛出异常
//

#include <iostream>
//#include <stdexcept>
#include "Sales_item.h"

int main()
{
    Sales_item item1, item2;
    // 输入两个item的ISBN号、售出的册数 和 销售价格
    std::cin >> item1 >> item2;
    // 检查两条数据是否属于同一种书籍
    if (item1.isbn() != item2.isbn())
        throw std::runtime_error("Data must refer to same ISBN");           // 抛出异常，暂停程序运行

    // 如果程序到了这里，说明两个ISBN是相同的
    std::cout << item1 + item2 << std::endl;

    return 0;
}

// 