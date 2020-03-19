// prog2_5_2.cpp : auto 类型说明符
//

#include <iostream>

int main()
{
    int i = 0, &r = i;
    const int ci = i, &cr = ci;

    auto a = r;        // int a
    auto b = ci;       // int b         auto一般会忽略掉顶层const
    auto c = cr;       // int c
    auto d = &i;       // int *d
    auto e = &ci;      // const int *e
    const auto f = ci;         // const int f
    auto &g = ci;              // const int &g         设置一个类型为auto的引用时，初始值中的顶层const属性仍然保留
    //auto &h = 42;            // 错误：不能为 非常量 引用 绑定字面值
    const auto &j = 42;        // const int &j = 42    常量引用可以绑定字面值
    auto k = ci, &l = i;       // int k = ci; int &l = i;
    auto &m = ci, *p = &ci;    // const int &m = ci; const int *p = &ci;
    //auto &n = i, *p2 = &ci;  // 错误：int &n = i; 但不能 int *p2 = &ci;

    std::cout << "i = " << i << "\tr = " << r << "\n"
        << "ci = " << ci << "\tcr = " << cr << "\n"
        << "a = " << a << "\n"
        << "b = " << b << "\n"
        << "c = " << c << "\n"
        << "*d -> i = " << *d << "\n"
        << "*e -> ci = " << *e << "\n"
        << "f = " << f << "\n"
        << "g = " << g << "\n"
        << "j = " << j << "\n"
        << "k = " << k << "\n"
        << "l = " << l << "\n"
        << "m = " << m << "\n"
        << "*p -> ci = " << *p << "\n" << std::endl;

    a = 42;
    b = 43;
    c = 44;
    *d = 45;        // 指向i
    //*e = 46;      // const int *e 指向常量的指针不能改变所指对象的值
    //f = 47;       // f是常量
    //g = 48;       // const int &g 是常量引用，不能改变所引用对象的值
    //j = 49;       // const int &j = 42 是常量引用
    k = 50;
    //m = 51;       // const int &m 是常量引用
    //*p = 52;      // const int *p 是指向常量的指针

    std::cout << "i = " << i << "\tr = " << r << "\n"
        << "ci = " << ci << "\tcr = " << cr << "\n"
        << "a = " << a << "\n"
        << "b = " << b << "\n"
        << "c = " << c << "\n"
        << "*d -> i = " << *d << "\n"
        << "*e -> ci = " << *e << "\n"
        << "f = " << f << "\n"
        << "g = " << g << "\n"
        << "j = " << j << "\n"
        << "k = " << k << "\n"
        << "l = " << l << "\n"
        << "m = " << m << "\n"
        << "*p -> ci = " << *p << "\n" << std::endl;

    l = 53;        // i的引用
    std::cout << "i = " << i << "\tr = " << r << "\n"
        << "ci = " << ci << "\tcr = " << cr << "\n"
        << "a = " << a << "\n"
        << "b = " << b << "\n"
        << "c = " << c << "\n"
        << "*d -> i = " << *d << "\n"
        << "*e -> ci = " << *e << "\n"
        << "f = " << f << "\n"
        << "g = " << g << "\n"
        << "j = " << j << "\n"
        << "k = " << k << "\n"
        << "l = " << l << "\n"
        << "m = " << m << "\n"
        << "*p -> ci = " << *p << "\n" << std::endl;

    return 0;

}

//