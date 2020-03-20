// prog4_11_3.cpp : 显式转换
//
// cast-name<type>(expression)
// type 是转换的目标类型，expression是要转换的值，cast-name 包括 static_cast, dynamic_cast, const_cast 和 reinterpret_cast

#include <iostream>

int main()
{
    // static_cast：用于具有明确定义的类型转换，只要不包含底层 const
    int i = 23, j = 8;
    double slope = i / j;
    std::cout << slope << std::endl;       // 未转换 结果为 2
    // static_cast<double>(i);
    // std::cout << "i = " << i << std::endl;
    slope = static_cast<double>(i) / j;       // static_cast<double>(i) 返回的是将 i 转换为浮点数后的右值，而并没有改变 i 本身的类型
    std::cout << slope << std::endl;
    // 可以使用 static_cast 找回存在于 void* 指针中的值
    double d;
    void *p = &d;      // 任何非常量对象的地址都能存入 void*
    double *dp = static_cast<double*>(p);

    // const_cast：只能改变运算对象的底层const性质
    char a = 'a';
    const char b = 'b';
    const char *pc1 = &a, *pc2 = &b;   // 
    //*pc1 = 'c';
    //const_cast<char*>(pc1);
    //*pc1 = 'c';
    char *p1 = const_cast<char*>(pc1);     // const_cast<char*>(pc1) 返回的是 普通char*指针的类型，但仍然是一个右值，pc1仍然还是指向常量的指针类型，仍然不能用pc1改变a的值
    *p1 = 'c';
    std::cout << a << std::endl;                // p1 指向的是 a
    char *p2 = const_cast<char*>(pc2);
    std::cout << *p2 << std::endl;
    *p2 = 'd';
    std::cout << *p2 << std::endl;           // p2 指向的是一个未知的对象？
    std::cout << b << std::endl;             // 无法用p2改变b的值

    return 0;
}

// 