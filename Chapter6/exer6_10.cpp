// exer6_10.cpp : 使用指针形参交换两个整数的值
//

#include <iostream>

// 交换两个整数的值
void exchange(int* p1, int* p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main()
{
    int v1 = 23, v2 = 6;
    int* p1 = &v1, * p2 = &v2;
    std::cout << "before:\n" << "v1 = " << v1 << "\tv2 = " << v2 << std::endl;
    exchange(p1, p2);
    std::cout << "after:\n" << "v1 = " << v1 << "\tv2 = " << v2 << std::endl;

    return 0;
}

// 