#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data
{
	// Ϊ�ǳ�Ա��������Ԫ�������Ӷ�ʹ����Щ�����ܹ�ʹ�����private��Ա
	friend Sales_data add(const Sales_data&, const Sales_data&);      // ִ����������ļӷ�
	friend std::ostream& print(std::ostream&, const Sales_data&);     // �������ֵ�����ostream
	friend std::istream& read(std::istream&, Sales_data&);            // �����ݴ�istream���뵽�����У�ע�������ββ�����const

private:
	std::string bookNo;              // �鱾���
	unsigned units_sold = 0;         // ��������
	double revenue = 0.0;            // ����������
	double avg_price() const;                         // ����ƽ���۸�

public:
	// ���캯��
	Sales_data() = default;                                                 // Ĭ�Ϲ��캯��
	/* explicit */
	Sales_data(const std::string &s): bookNo(s) { }           // explicit������ֹ��ʽ������ת��
	Sales_data(const std::string &s, unsigned n, double p): 
		bookNo(s), units_sold(n), revenue(n*p) { }
	/* explicit */
	Sales_data(std::istream&);

	// ��Ա����
	std::string isbn() const { return bookNo; }       // ���ض�����鱾���   // Ҳ����д�� return this->bookNo;
	Sales_data& combine(const Sales_data&);           // ��һ������ӵ���һ�������ϡ���Ա��������������������ڲ������������������ⲿ
};

// �ǳ�Ա�ӿں�������������˵������Ľӿڵ���ɲ��֣�������ʵ���ϲ��������౾��ͨ������������ͬһ��ͷ�ļ���
// ��������Ԫ����֮����ר�ŶԺ�������һ������
Sales_data add(const Sales_data&, const Sales_data&);      // ִ����������ļӷ�
std::ostream& print(std::ostream&, const Sales_data&);     // �������ֵ�����ostream
std::istream& read(std::istream&, Sales_data&);            // �����ݴ�istream���뵽�����У�ע�������ββ�����const

// ���캯����֮һ��
Sales_data::Sales_data(std::istream& is)
{
	read(is, *this);
}

// ��Ա�������Զ���������ⲿ
double Sales_data::avg_price() const          // �������������������
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
	return *this;            // ���� �����˸ú������Ǹ�����
}

// �ǳ�Ա����
// IO�����ڲ��ܱ����������ͣ����ֻ��ͨ����������������
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