// exer7_41.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

class Sales_data {
	friend std::ostream& print(std::ostream&, const Sales_data&);
	friend std::istream& read(std::istream&, Sales_data&);
public:
	std::string isbn() const { return bookNo; }       // 返回对象的书本编号   // 也可以写成 return this->bookNo;
	//Sales_data& combine(const Sales_data&);           // 将一个对象加到另一个对象上。成员函数的声明必须在类的内部，但定义可以在类的外部
	double avg_price() const;                         // 返回平均价格
	// 构造函数
	// 非委托构造函数：使用对应实参初始化成员
	Sales_data(std::string s, unsigned cnt, double price) :
		bookNo(s), units_sold(cnt), revenue(cnt* price) {
		std::cout << "Constructor1" << std::endl;
	}
	// 委托构造函数：使用其他构造函数执行初始化
	Sales_data() : Sales_data("", 0, 0.0) { std::cout << "Constructor2" << std::endl; }
	Sales_data(std::string s) : Sales_data(s, 0, 0.0) { std::cout << "Constructor3" << std::endl; }
	Sales_data(std::istream& is) : Sales_data() {
		read(is, *this); 
		std::cout << "Constructor4" << std::endl;
	}

private:
	std::string bookNo;              // 书本编号
	unsigned units_sold = 0;         // 销售数量
	double revenue = 0.0;            // 总销售输入
};

std::ostream& print(std::ostream&, const Sales_data&);     // 将对象的值输出到ostream
std::istream& read(std::istream&, Sales_data&);            // 将数据从istream读入到对象中，注意这里形参不能是const

double Sales_data::avg_price() const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}
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

int main()
{
	// 分别用4个构造函数定义4个对象
	Sales_data item1("XXFZ520", 15, 20);
	Sales_data item2;
	Sales_data item3("LDY520");
	Sales_data item4(std::cin);

	std::cout << "**************************************************************\n";

	print(std::cout, item1);
	std::cout << std::endl;
	print(std::cout, item2);
	std::cout << std::endl;
	print(std::cout, item3);
	std::cout << std::endl;
	print(std::cout, item4);
	std::cout << std::endl;

	return 0;
}

//