// prog6_5_2.cpp : 内联函数 和 constexpr 函数
//

#include <iostream>

// 内联函数 inline：将它在每个调用点上 内联地(de) 展开，适合用于规模较小的函数
inline const std::string& shorterString(const std::string& s1, const std::string& s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}


// constexpr 函数：函数的返回值类型 以及 所有形参的类型 都是 字面值类型，而且函数体中 必须有且只有 一条 return 语句
// constexpr 函数 被隐式地指定为 内联函数
constexpr int new_sz()
{
    return 42;
}
// 允许 constexpr 函数 的返回值 并非一个常量
constexpr size_t scale(size_t cnt)      // 当scale的实参是常量表达式时，它的返回值也是常量表达式，反之则不然
{
    return new_sz() * cnt;
}


int main()
{
    std::string s1 = "Xiaoxiang Feizi", s2 = "Lin Daiyu";
    std::cout << shorterString(s1, s2) << std::endl;         // 编译过程中展开成 std::cout << (s1.size() <= s2.size() ? s1 : s2) << std::endl; 的形式

    const int foo = new_sz();

    int arr[scale(2)];            // 正确：2是常量表达式，scale(2)也是常量表达式
    int i = 2;                    // i 不是常量表达式
    //int a2[scale(i)];           // 错误：scale(i)不是常量表达式

    return 0;
}

// 