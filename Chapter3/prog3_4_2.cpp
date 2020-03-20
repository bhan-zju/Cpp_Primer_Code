// prog3_4_2.cpp : 迭代器运算
//

#include <iostream>
#include <vector>

int main()
{
    // 二分搜索
    std::vector<int> text{ 0,1 };
    for (int i = 2; i != 20; ++i)
        text.push_back(text[i - 1] + text[i - 2]);     // 将斐波那契数列前20项存入容器text中

    for (auto i : text)
        std::cout << i << " ";
    std::cout << std::endl;

    int sought;
    std::cout << "Enter the number you want: ";
    std::cin >> sought;                                // 输入想要搜索的数字

    // 二分法查找
    auto beg = text.begin(), end = text.end();
    auto mid = beg + (end - beg) / 2;
    while (mid != end && *mid != sought) {
        if (sought < *mid)
            end = mid;
        else
            beg = mid + 1;
        mid = beg + (end - beg) / 2;
    }

    if (*mid == sought) {
        std::cout << "The " << mid - text.begin() << " number is " << text[mid - text.begin()] << std::endl;           //输出该数字的索引
    }
    else {
        std::cout << "The number is not in the text!" << std::endl;
    }

    return 0;
}

// 