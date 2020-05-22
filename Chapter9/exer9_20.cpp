// exer9_20.cpp : 
//

#include <iostream>
#include <list>
#include <deque>

int main()
{
    std::list<int> ilist{ 8,9,7,1,3,4,6,0 };
    std::deque<int> odd, even;    // odd奇  even偶

    for (auto i : ilist) {
        // i 和 000000000000001 进行 位与运算，如果i为奇数，则i的最后一位为1，i&1=1
        ((i & 1) ? odd : even).push_back(i);          // 条件运算符见4.7节
    }

    std::cout << "odd: ";
    for (auto o : odd) {
        std::cout << o << " ";
    }
    std::cout << std::endl;

    std::cout << "even: ";
    for (auto e : even) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

// 