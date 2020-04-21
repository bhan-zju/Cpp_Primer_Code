// prog7_5_4.cpp : 隐式地类类型转换
//

// 如果构造函数只接受一个实参，则它实际上定义了转换为此类类型的隐式转换机制
// Sales_data类中只接受一个实参的构造函数有：
// Sales_data(const std::string &s): bookNo(s) { }
// Sales_data(std::istream&);

#include <iostream>
#include <string>
#include "Sales_data.h"

int main()
{
    Sales_data item("9-999-99999-9", 10, 15);

    std::string null_book = "9-999-99999-9";
    // 构造一个临时的 Sales_data 对象，对象的 units_sold 和 revenue 等于 0，bookNo 等于 null_book，然后该临时对象将被合并到item对象中
    item.combine(null_book);

    // 其他写法：
    item.combine(std::string("9-999-99999-9"));
    item.combine(Sales_data("9-999-99999-9"));
    //item.combine("9-999-99999-9");         // 错误：无法直接将"9-999-99999-9"转换为Sales_data对象

    // 使用构造函数Sales_data(std::istream&)：
    item.combine(std::cin);
}

// 