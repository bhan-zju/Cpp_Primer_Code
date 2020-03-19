// prog1_4_3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
    int value = 0, sum = 0;
    std::cout << "Enter numbers: " << std::endl;
    while (std::cin >> value)    // 读取数据知道遇到文件尾，计算所有读入数据的和
        sum += value;                      // 如果while循环中只有一条语句，可以不加花括号{ }
    std::cout << "Sum is " << sum << std::endl;
    return 0;
}

// 测试结果：
// input: 1 2 3 4 ctrl+z 5   output: 10
// input: 1 2 3.5 4          output: 6
