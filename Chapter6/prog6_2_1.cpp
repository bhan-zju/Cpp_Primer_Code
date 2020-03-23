// prog6_2_1.cpp : 传值参数：实参的值拷贝给形参
//

#include <iostream>

// 指针形参
void reset(int* ip)
{
    *ip = 0;            // 改变了指针所指对象的值
    ip = 0;             // 只改变了ip的局部拷贝，实参并不会改变
}

int main()
{
    int val = 42;
    reset(&val);     // &是取地址符，输入val的地址
    std::cout << val << std::endl;

    // 或者直接定义指针
    int val2 = 23, *p = &val2;
    reset(p);
    std::cout << val2 << std::endl;
    val2 = 45;
    std::cout << *p << std::endl;          // p仍然指向val2，而不会变成空指针

    return 0;
}

// 