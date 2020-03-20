// exer5_20.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::string last;
    int flag = 0;
    while (std::cin >> str) {
        if (str == last) {
            flag = 1;
            break;
        }
        last = str;
    }

    if (flag) {
        std::cout << "The continuously appearing word is " << str << std::endl;
    }
    else {
        std::cout << "No continuously appearing word!" << std::endl;
    }

    return 0;
}

// 