// exer5_25.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
    int a, b;
    std::cout << "Enter two numbers: \n";
    while (std::cin >> a >> b) {
        try {
            if (b == 0)
                throw std::runtime_error("The second numbers cannot be 0!");

            // b ≠ 0 时才能进行下面的语句
            std::cout << "The quotient of them is " << a / b << std::endl;
            std::cout << "Try again? Enter y or n: ";
            char c;
            std::cin >> c;
            if (!std::cin || c == 'n')
                break;                    // 输入 n 则跳出 while 循环
            else
                std::cout << "Enter two numbers: \n";
        }
        catch (std::runtime_error err) {
            std::cout << err.what()
                << "\nTry again? Enter y or n: ";
            char c;
            std::cin >> c;
            if (!std::cin || c == 'n')
                break;                    // 输入 n 则跳出 while 循环
            else
                std::cout << "Enter two numbers: \n";
        }
    }
    
    return 0;
}

// 