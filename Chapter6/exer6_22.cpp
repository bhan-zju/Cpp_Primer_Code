// exer6_22.cpp : 交换两个int指针
//

#include <iostream>

void exchangeip(int*& p1, int*& p2)        // p1 p2 是对指针实参的引用
{
    int* temp = p1;
    p1 = p2;
    p2 = temp;
}

int main()
{
    int i1 = 3, * ip1 = &i1;
    int i2 = 5, * ip2 = &i2;
    exchangeip(ip1, ip2);           // ip1将指向i2，ip2将指向i1
    std::cout << "*ip1 = " << *ip1 << std::endl;
    std::cout << "*ip2 = " << *ip2 << std::endl;

    *ip1 = 10;
    *ip2 = 8;
    std::cout << "i1 = " << i1 << std::endl;
    std::cout << "i2 = " << i2 << std::endl;

    return 0;

}

// 
