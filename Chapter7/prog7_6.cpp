// prog7_6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Account.h"

int main()
{
    double r;
    r = Account::rate();     // 使用作用域运算符 :: 访问静态成员

    // 也可以使用Account对象或引用或指针来访问
    Account ac1;
    Account* ac2 = &ac1;
    r = ac1.rate();
    r = ac2->rate();

}

// 