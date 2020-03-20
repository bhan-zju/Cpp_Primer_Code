// prog3_5_5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string s("Hello World");
    const char *str = s.c_str();
    std::cout << *str << std::endl;
    std::cout << str[2] << std::endl;
    
    // 使用数组初始化 vector 对象
    int arr[] = { 0,1,2,3,4,5 };
    std::vector<int> ivec(std::begin(arr), std::end(arr));
    for (auto i : ivec)
        std::cout << i << " ";
    std::cout << std::endl;
    std::vector<int> subvec(arr + 1, arr + 4);
    for (auto i : subvec)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}

// 