// prog2_5_3.cpp : decltype 类型指示符
//

#include <iostream>

int main()
{
    const int ci = 0, & cj = ci;
    decltype(ci) x = 0;       // const int x
    decltype(cj) y = x;       // const int &y, 绑定到x
    //decltype(cj) z;         // 错误：引用必须初始化

    int i = 42, *p = &i, &r = i;
    int j = 43, k = 44, m = 45;
    decltype(i) a;            // int a
    decltype(r) b = j;        // int &b 是一个引用，必须初始化
    decltype(r + 0) c;        // r+0的结果是整数，因此是 int c，可以不初始化
    decltype(p) d;            // int *d
    decltype(*p) e = k;       // 注意！！！！！如果表达式是解引用操作，将得到引用类型 int &e，必须初始化
    decltype((i)) f = m;      // 注意！！！！！变量加上一层括号，将会得到引用类型 int &f，必须初始化

    d = &i;
    *d = 0;
    b = 1;
    e = 2;
    f = 3;
    std::cout << "i = " << i << "\n"
        << "j = " << j << "\n"
        << "k = " << k << "\n"
        << "m = " << m << std::endl;

    return 0;
}

// 
