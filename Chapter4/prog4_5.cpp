// prog4_5.cpp : 递增递减运算符
//

#include <iostream>
#include <vector>

int main()
{
    int i = 0, j;
    j = ++i;        // 前置版本返回递增后的值，i=1,j=1
    std::cout << "i = " << i << "\tj = " << j << std::endl;

    i = 0;
    j = i++;        // 后置版本返回递增前的值，i=1,但j=0;
    std::cout << "i = " << i << "\tj = " << j << std::endl;

    // 输出vector对象的值直至遇到（但不包括）第一个负值为止
    std::vector<int> iv{ 4,3,2,1,0,-1,-2 };
    auto iter = iv.begin();
    while (iter != iv.end() && *iter >= 0)
        std::cout << *iter++ << " ";                // 即*(iter++)，iter++返回初始的iter，再将自己+1后赋值给自己
    std::cout << std::endl;

    return 0;
}

// 