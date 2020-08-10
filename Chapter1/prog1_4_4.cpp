// prog1_4_4.cpp :
// 统计输入中每个整型数字连续出现了多少次

#include <iostream>

int main()
{
    int currval = 0, val = 0;
    std::cout << "Enter numbers: " << std::endl;
    if (std::cin >> currval) {
        int cnt = 1;
        while (std::cin >> val) {
            if (val == currval) {
                ++cnt;
            }
            else {
                std::cout << currval << " occurs " << cnt << " times" << std::endl;
                currval = val;
                cnt = 1;
            }
        }
        std::cout << currval << " occurs " << cnt << " times" << std::endl;
    }
    return 0;
}

