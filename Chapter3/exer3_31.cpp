// exer3_31.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
    constexpr size_t array_size = 10;
    int a[array_size];
    for (size_t ix = 0; ix < array_size; ++ix) {
        a[ix] = ix;
    }
    for (auto i : a)
        std::cout << i << " ";
    std::cout << std::endl;
}

// 