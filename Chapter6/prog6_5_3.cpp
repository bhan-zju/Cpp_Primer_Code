// prog6_5_3.cpp : assert 和 NDEBUG
//

// assert(expr); 如果expr为假，则终止程序的执行

#include <iostream>

#define NDEBUG                 // 如果定义了 NDEBUG 预处理器变量，则关闭 assert 的调试。注意：必须写在 #include <cassert> 之前！！！！！！！！！！
#include <cassert>


int main()
{
    std::string word = "Lin Daiyu";
    std::string::size_type threshold = 10;
    assert(word.size() >= threshold);           // assert 定义在 <cassert>头文件中
    std::cout << word << std::endl;

    if (word.size() < threshold) {
        std::cerr << "Error: " << __FILE__                      // __FILE__ 存放 文件名的 字符串字面值
            << " : in Function " << __func__                    // __func__ 存放 当前调试的函数名 的 字符串字面值
            << " at line " << __LINE__ << std::endl             // __LINE__ 存放 当前行号的 整型字面值
            << "        Compiled on " << __DATE__               // __DATE__ 存放 文件编译日期的 字符串字面值
            << " at " << __TIME__ << std::endl                  // __TIME__ 存放 文件编译时间的 字符串字面值
            << "        World read was \"" << word
            << "\": Length too short" << std::endl;
    }

    return 0;
}

// 