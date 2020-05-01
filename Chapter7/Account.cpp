// 定义Account类内的成员函数

#ifndef ACCOUNT_CPP
#define ACCOUNT_CPP

#include "Account.h"

// 在类的外部定义 静态成员函数 时，不能重复 static 关键字
void Account::rate(double newRate)
{
	interestRate = newRate;
}

// 必须在 类的外部 初始化 静态成员
double Account::interestRate = initRate();

constexpr int Account::period;     // 类内已经初始化了period，这里只需要定义，不需要带初始值

#endif // !ACCOUNT_CPP
