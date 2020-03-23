// prog6_1_1.cpp : 局部静态对象
//

#include <iostream>

// 该函数统计自己被调用了多少次
size_t count_calls() 
{
    static size_t ctr = 0;                  // 调用结束后，这个值仍然有效
    return ++ctr;         // 前置递增运算符
}

int main()
{
    for (size_t i = 0; i != 10; ++i) {
        std::cout << count_calls() << std::endl;
    }

    // std::cout << ctr << std::endl;     // 错误：不能在这个函数里使用
    return 0;
}

// 