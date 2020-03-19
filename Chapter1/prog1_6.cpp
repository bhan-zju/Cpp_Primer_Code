// prog1_6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item trans, total;
    if (std::cin >> total) {
        while (std::cin >> trans) {
            if (trans.isbn() == total.isbn()) {
                total += trans;
            }
            else {
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total;
    }
    else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}

// 