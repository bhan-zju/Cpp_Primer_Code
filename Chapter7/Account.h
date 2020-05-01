#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account
{
public:
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }         // 静态成员函数
	static void rate(double);                             // 静态成员函数：设定新的利率
private:
	std::string owner;
	double amount;
	static double interestRate;      // 静态成员           // 利率             // 不能 在类内部 初始化 静态成员(字面值常量类型除外)
	static constexpr int period = 30;      // 字面值常量类型的 静态成员 可以在类内 初始化
	double daily_tbl[period];
	static double initRate();        // 静态成员函数       // 初始化利率

	static Account mem1;     // 静态成员可以是不完全类型
	Account* mem2;           // 指针成员可以是不完全类型
	//Account mem3;        // 错误：数据成员必须是完全类型
};

#endif // !ACCOUNT_H
