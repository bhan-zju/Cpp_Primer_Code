#include <iostream>
#include "Chapter6.h"

// 求阶乘
int fact(int val)
{
	int ret = 1;
	while (val > 1)
		ret *= val--;          // 后置递减，返回初始值后减1
	return ret;
}

int func()
{
	int v;
	std::cout << "Enter a number: ";
	std::cin >> v;
	return fact(v);
}

int abs(int val)
{
	if (val < 0)
		return -val;
	return val;
}