// prog2_6_2.cpp : Struct 类
//

#include <iostream>
#include <string>

struct Sales_data
{
    std::string bookNO;       // 图书ISBN编号
    unsigned units_sold = 0;      // 销售数量
    double revenue = 0.0;           // 收入
};

int main()
{
    Sales_data trans, total;
    double price = 0;    //书的单价

    if (std::cin >> total.bookNO >> total.units_sold >> price) {
        total.revenue = total.units_sold * price;
        while (std::cin >> trans.bookNO >> trans.units_sold >> price) {
            if (trans.bookNO == total.bookNO) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.units_sold * price;
            }
            else {
                std::cout << total.bookNO << " " << total.units_sold << " " << total.revenue << " ";
                if (total.units_sold != 0) {
                    std::cout << total.revenue / total.units_sold << std::endl;
                }
                else {
                    std::cout << "(no sales)" << std::endl;
                }
                total = trans;
                total.revenue = total.units_sold * price;
            }
        }
        std::cout << total.bookNO << " " << total.units_sold << " " << total.revenue << " ";
        if (total.units_sold != 0) {
            std::cout << total.revenue / total.units_sold << std::endl;
        }
        else {
            std::cout << "(no sales)" << std::endl;
        }
        total = trans;
        total.revenue = total.units_sold * price;
    }
    else {
        // 没有正确输入
        std::cerr << "No data?!" << std::endl;
        return -1;
    }

    return 0;
}

//