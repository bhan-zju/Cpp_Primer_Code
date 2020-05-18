// exer9_13.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::list<int> ilis{ 8,9,7,1,3,4,6,0 };
    std::vector<double> dvec(ilis.begin(), ilis.end());
    for (auto d : dvec) {
        std::cout << d << " ";
    }
    std::cout << std::endl;

    std::vector<int> ivec{ 8,9,7,1,3,4,6,0 };
    std::vector<double> dvec2(ivec.begin(), ivec.end());
    for (auto d : dvec2) {
        std::cout << d << " ";
    }
    std::cout << std::endl;
}

