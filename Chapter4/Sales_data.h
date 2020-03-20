#ifndef SALES_DATA_H     // 头文件保护符，意为：如果名为SALES_DATA_H的预处理变量未定义为真（即未被定义），则执行后面直到endif
#define SALES_DATA_H     // 定义预处理变量SALES_DATA_H

#include <string>
struct Sales_data
{
    std::string bookNO;       // 图书ISBN编号    初始化为空串，不占内存
    unsigned units_sold = 0;      // 销售数量    占4
    double revenue = 0.0;           // 收入      占8
};

#endif // !SALES_DATA_H    // endif

