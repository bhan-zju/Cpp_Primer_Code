// exer6_33.cpp : 使用递归函数输出vector对象
//

#include <iostream>
#include <vector>

void print(std::vector<int>::iterator beg, std::vector<int>::iterator end)
{
    if (beg != end) {
        std::cout << *beg << " ";
        print(++beg, end);
    }
}

int main()
{
    std::vector<int> v{ 3,1,4,1,5,9,2,6,5,3,5,8,9,7 };
    print(v.begin(), v.end());

    return 0;
}

// 