// prog7_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Sales_data.h"

int main()
{
    // 分别调用4个构造函数
    Sales_data item1;
    Sales_data item2("IXL8495");
    Sales_data item3("ILX8495", 6, 13);
    Sales_data item4(std::cin);
    // 测试
    print(std::cout, item1);
    std::cout << std::endl;
    Sales_data item5 = add(item2, item3);
    print(std::cout, item5);
    std::cout << std::endl;
    print(std::cout, item4);
    std::cout << std::endl;

    // 交易处理程序
    Sales_data total;
    if (read(std::cin, total)) {
        Sales_data trans;
        while (read(std::cin, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(std::cout, total);
                std::cout << std::endl;
                total = trans;
            }
        }
        print(std::cout, total);
        std::cout << std::endl;
    }
    else {
        std::cerr << "No Data?!" << std::endl;
    }
}

// 