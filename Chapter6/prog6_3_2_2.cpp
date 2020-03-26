// prog6_3_2_2.cpp : 递归函数；main函数的返回值
//

#include <iostream>
//#include <cstdlib>

// 计算val的阶乘
int factorial(int val)
{
    if (val > 1)
        return factorial(val - 1) * val;    // 递归函数
    return 1;             // 递归终止条件：val <= 1时，返回1
}

int main()
{
    std::cout << factorial(5) << std::endl;

    // main函数的返回值：cstdlib头文件定义了两个预处理变量
    if (factorial(6) < 200)
        return EXIT_FAILURE;
    else
        return EXIT_SUCCESS;

}

// 