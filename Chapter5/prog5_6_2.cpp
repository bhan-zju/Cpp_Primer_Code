// prog5_6_2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
//#include <stdexcept>
#include "Sales_item.h"

int main()
{
    Sales_item item1, item2;

    // 输入两个item的ISBN号、售出的册数 和 销售价格
    while (std::cin >> item1 >> item2) {
        try {
            // 检查两条数据是否属于同一种书籍
            if (item1.isbn() != item2.isbn())
                throw std::runtime_error("Data must refer to same ISBN");           // 抛出异常，暂停程序运行

            // 如果程序到了这里，说明两个ISBN是相同的
            std::cout << item1 + item2 << std::endl;
        }
        catch (std::runtime_error err) {                    // 如果捕捉到std::runtime_error类型的异常
            std::cout << err.what()
                << "\nTry again? Enter y or n: " << std::endl;
            char c;
            std::cin >> c;
            if (!std::cin || c == 'n')
                break;                           // 如果输入n，则跳出while循环
        }
    }

    return 0;
}

