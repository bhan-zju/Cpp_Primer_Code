#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data
{
	// 为非成员函数做友元声明，从而使得这些函数能够使用类的private成员
	friend Sales_data add(const Sales_data&, const Sales_data&);      // 执行两个对象的加法
	friend std::ostream& print(std::ostream&, const Sales_data&);     // 将对象的值输出到ostream
	friend std::istream& read(std::istream&, Sales_data&);            // 将数据从istream读入到对象中，注意这里形参不能是const

private:
	std::string bookNo;              // 书本编号
	unsigned units_sold = 0;         // 销售数量
	double revenue = 0.0;            // 总销售输入
	double avg_price() const;                         // 返回平均价格

public:
	// 构造函数
	Sales_data() = default;                                                 // 默认构造函数
	/* explicit */
	Sales_data(const std::string &s): bookNo(s) { }           // explicit用于阻止隐式类类型转换
	Sales_data(const std::string &s, unsigned n, double p): 
		bookNo(s), units_sold(n), revenue(n*p) { }
	/* explicit */
	Sales_data(std::istream&);

	// 成员函数
	std::string isbn() const { return bookNo; }       // 返回对象的书本编号   // 也可以写成 return this->bookNo;
	Sales_data& combine(const Sales_data&);           // 将一个对象加到另一个对象上。成员函数的声明必须在类的内部，但定义可以在类的外部
};

// 非成员接口函数：概念上来说属于类的接口的组成部分，但它们实际上并不属于类本身；通常和类生命在同一个头文件内
// 必须在友元声明之外再专门对函数进行一次声明
Sales_data add(const Sales_data&, const Sales_data&);      // 执行两个对象的加法
std::ostream& print(std::ostream&, const Sales_data&);     // 将对象的值输出到ostream
std::istream& read(std::istream&, Sales_data&);            // 将数据从istream读入到对象中，注意这里形参不能是const

// 构造函数（之一）
Sales_data::Sales_data(std::istream& is)
{
	read(is, *this);
}

// 成员函数可以定义在类的外部
double Sales_data::avg_price() const          // 必须包含它所属的类名
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}
Sales_data& Sales_data::combine(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;            // 返回 调用了该函数的那个对象
}

// 非成员函数
// IO类属于不能被拷贝的类型，因此只能通过引用来传递它们
std::istream& read(std::istream& is, Sales_data& item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = item.units_sold * price;
	return is;
}
std::ostream& print(std::ostream& os, const Sales_data& item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}
Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

#endif