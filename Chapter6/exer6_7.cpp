// exer6_7.cpp : 第一次调用时输出为0，之后每次调用输出加1
//

#include <iostream>

size_t generate()
{
    static size_t ctr = 0;
    return ctr++;
}

int main()
{
    for (int i = 0; i != 10; ++i)
        std::cout << generate() << std::endl;

    return 0;
}

// 
