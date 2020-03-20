// prog3_3_1.cpp : 初始化vector模板
//

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> svec1;       // 默认初始化，string类型的空vector，svec1不含任何元素
    std::vector<int> ivec1;           // 初始状态为空
    std::vector<int> ivec2(ivec1);    // 把 ivec1 的元素拷贝给 ivec2
    std::vector<int> ivec3 = ivec1;   // 把 ivec1 的元素拷贝给 ivec3，同上
    //std::vector<std::string> ivec4(ivec1);   // 错误：拷贝时两个vector对象的类型必须相同

    // 列表初始化
    std::vector<std::string> v1 = { "a","an","the" };
    std::vector<std::string> v2{ "a","an","the" };         // 两种形式
    //std::vector<std::string> v3( "a","an","the" );       // 错误：只能把初始值放在花括号里进行列表初始化

    // 创建指定数量的元素初始化
    std::vector<int> ivec4(10, -1);              // ivec4 中包含10个 int 类型的元素，每个都被初始化为 -1
    std::vector<std::string> svec2(10, "hi");    // svec2 中包含10个 std::string 类型的元素，每个都被初始化为 "hi"

    // 值初始化：只提供vector对象容纳的元素数量而略去初始值
    std::vector<int> ivec5(10);            // 10个元素，每个都初始化为0
    std::vector<std::string> svec3(10);    // 10个元素，每个都是空串对象

    // 注意区分 列表初始值 和 元素数量
    std::vector<int> v4(10);           // 圆括号，v4 有10个元素，每个初始值都是0
    std::vector<int> v5{10};           // 花括号，v5 有1个元素，值是 10，属于列表初始值
    std::vector<int> v6(10, 1);        // 圆括号，v6 有10个元素，每个初始值都是1
    std::vector<int> v7{10, 1};        // 花括号，v7 有2个元素，值分别是 10 和 1，属于列表初始值

    std::vector<std::string> v8{ "hi" };             // 花括号，列表初始化：v8 有一个元素"hi"
    //std::vector<std::string> v9( "hi" );           // 错误：不能用圆括号来进行列表初始化
    std::vector<std::string> v10{ 10 };              // 花括号，但不是列表初始化，而是v10 有10个默认初始化的元素，因为 10 不是 std::string 类型
    std::vector<std::string> v11{ 10, "hi" };        // v11 有10个值为"hi"的元素

    return 0;
}

// 