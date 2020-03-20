// prog4_9.cpp : sizeof 运算符
//

#include <iostream>
#include <string>
#include <vector>
#include "Sales_data.h"

int main()
{
    Sales_data data, * p;
    std::cout << "sizeof\n" << "(Sales_data): " << sizeof(Sales_data) << std::endl;    // 竟然占40
    std::cout << "data: " << sizeof data << std::endl;
    std::cout << "p: " << sizeof p << std::endl;                       // 4
    std::cout << "*p: " << sizeof *p << std::endl;                     // 40
    std::cout << "data.revenue: " << sizeof data.revenue << std::endl;
    std::cout << "Sales_data::revenue: " << sizeof Sales_data::revenue << std::endl << std::endl;

    std::cout << "sizeof\n" << "(char): " << sizeof(char) << std::endl;             // 1
    std::cout << "(int): " << sizeof(int) << std::endl;                             // 4
    std::cout << "(unsigned): " << sizeof(unsigned) << std::endl;                   // 4
    std::cout << "(float): " << sizeof(float) << std::endl;                         // 4
    std::cout << "(double): " << sizeof(double) << std::endl << std::endl;          // 8

    // 字符串、容器 和 数组
    std::string s1, s2 = "Hi", s3 = "Hello";
    std::vector<int> iv1{ 0,3,45 }, iv2{ 66,2,341,98,26 };
    std::vector<double> iv3{ 1.2,2.45,13.4 }, iv4{ 3.14,6.28,9.42,12.56,15.7,18.84 };
    double arr1[5], arr2[7];
    std::cout << "sizeof\n" << "s1: " << sizeof s1 << std::endl;
    std::cout << "s2: " << sizeof s2 << std::endl;
    std::cout << "s3: " << sizeof s3 << std::endl;                                        // s1, s2, s3 都是 28
    std::cout << "iv1: " << sizeof iv1 << std::endl;
    std::cout << "iv2: " << sizeof iv2 << std::endl;
    std::cout << "size_t iv1: " << (sizeof iv1) / (sizeof(int)) << std::endl;
    std::cout << "size_t iv2: " << (sizeof iv2) / (sizeof(int)) << std::endl;
    std::cout << "iv3: " << sizeof iv3 << std::endl;
    std::cout << "iv4: " << sizeof iv4 << std::endl;                                     // iv1, iv2, iv3, iv4 都是16
    std::cout << "size_t iv3: " << (sizeof iv3) / (sizeof(double)) << std::endl;
    std::cout << "size_t iv4: " << (sizeof iv4) / (sizeof(double)) << std::endl;
    std::cout << "arr1: " << sizeof arr1 << std::endl;                                   // 5*8 = 40
    std::cout << "size_t arr: " << (sizeof arr1) / (sizeof(*arr1)) << std::endl;         // 得到了arr1 的数组大小 5
    std::cout << "arr2: " << sizeof arr2 << std::endl;                                   // 7*8 = 56
    std::cout << "size_t arr2: " << (sizeof arr2) / (sizeof(*arr2)) << std::endl;        // 得到了arr2 的数组大小 7，说明这种方法只适合数组，不能用于字符串和容器


    return 0;
}

// 