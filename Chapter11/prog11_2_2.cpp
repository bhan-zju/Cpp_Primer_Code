// prog11_2_2.cpp : 关键字类型的要求
//

#include <iostream>
#include <set>
#include "Sales_data.h"

// 使用关键字的比较函数，定义一个严格弱序
bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.isbn() < rhs.isbn();
}

int main()
{
	// 为了使用自定义的操作，在定义multiset时，必须提供两个类型
	// 关键字类型Sales_data，以及 比较操作类型——是一种函数指针类型（必须要加上*）（见6.7节）
	// 自定义的操作类型 必须 在尖括号中 紧跟着元素类型给出
	std::multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);     
	// 使用compareIsbn函数来初始化bookstore对象，表示 向bookstore中添加元素时，通过调用compareIsbn函数来为这些元素排序
}

