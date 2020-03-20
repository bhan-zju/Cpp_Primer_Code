// prog4_10.cpp : 逗号运算符
//

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ivec{ 3,1,4,1,5,9,2,6,5,3,5,8,9,7 };
    std::vector<int>::size_type cnt = ivec.size();
    for (std::vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
        ivec[ix] = cnt;
    for (auto i : ivec)
        std::cout << i << " ";
    std::cout << std::endl;

    // 改为后置版本的递增递减符
    cnt = ivec.size();
    for (std::vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
        ivec[ix] = cnt;
    for (auto i : ivec)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}

// 