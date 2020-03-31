// exer6_47.cpp : 改写exer6_33使用递归输出vector对象
//

#include <iostream>
#include <vector>

//#define NDEBUG

void print(std::vector<int>::iterator beg, std::vector<int>::iterator end, std::vector<int>::size_type sz)
{
#ifndef NDEBUG
    if (sz > 10)
        std::cout << __func__ << ": vector size is " << sz << std::endl;
#endif
    if (beg != end) {
        std::cout << *beg << " ";
        print(++beg, end, end - beg);
    }
}

int main()
{
    std::vector<int> v{ 3,1,4,1,5,9,2,6,5,3,5,8,9,7 };
    print(v.begin(), v.end(), v.size());

    return 0;
}

// 