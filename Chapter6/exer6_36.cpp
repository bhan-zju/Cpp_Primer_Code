// exer6_36.cpp : 返回数组的引用
//

#include <iostream>

// 定义两个全局变量
int odd[] = { 1,3,5,7,9 };
int even[] = { 0,2,4,6,8 };

// 方法一：使用类型别名
typedef int arrT[5];        // arrT是一个类型别名，它表示的类型是含有5个整数的数组
// 或 using arrT = int[5];
arrT& func1(int i)            // 返回类型是 含有5个整数的数组 的引用
{
    return (i % 2) ? odd : even;
}

// 方法二：直接声明一个返回数组指针的函数 Type ( &function(parameter_list) ) [dimension]   外层括号同样不能省略
int(&func2(int i))[5]     // 返回一个 含有5个整数的数组 的引用
{
    return (i % 2) ? odd : even;
}

// 方法三：使用尾置返回类型
auto func3(int i) -> int(&)[5]          // 返回类型是 含有5个整数的数组 的引用
{
    return (i % 2) ? odd : even;
}

// 方法四：使用 decltype
decltype(odd)& func4(int i)         // decltype(odd)的类型是含有5个整数的数组，decltype(odd)&是对 该类型数组 的引用
{
    return (i % 2) ? odd : even;
}


int main()
{
    int(&ans1)[5] = func1(1);       // ans1是一个 含有5个整数的数组 的指针
    for (auto i : ans1)
        std::cout << i << " ";
    std::cout << std::endl;

    int (&ans2)[5] = func2(2);
    for (auto i : ans2)
        std::cout << i << " ";
    std::cout << std::endl;

    int (&ans3)[5] = func3(3);
    for (auto i : ans3)
        std::cout << i << " ";
    std::cout << std::endl;

    int (&ans4)[5] = func4(4);
    for (auto i : ans4)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;

}
