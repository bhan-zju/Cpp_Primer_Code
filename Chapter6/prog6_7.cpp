// prog6_7.cpp : 函数指针
//

#include <iostream>

bool lengthCompare(const std::string& s1, const std::string& s2)
{
    return s1.size() >= s2.size() ? true : false;
}

std::string::size_type sumLength(const std::string& s1, const std::string& s2)
{
    return s1.size() + s2.size();
}
std::string::size_type largerLength(const std::string& s1, const std::string& s2)
{
    return s1.size() >= s2.size() ? s1.size() : s2.size();
}

bool cstringCompare(const char*, const char*);


// 函数指针形参
void useBigger1(const std::string& s1, const std::string& s2, bool pf(const std::string&, const std::string&));
void useBigger2(const std::string& s1, const std::string& s2, bool (*pf)(const std::string&, const std::string&));
// 两种声明等价
// 可以使用类型别名简化代码
// Func 和 Func2 是函数类型
typedef bool Func(const std::string&, const std::string&);
typedef decltype(lengthCompare) Func2;     // 等价的类型
// FuncP 和 FuncP2 是函数指针类型
typedef bool (*FuncP)(const std::string&, const std::string&);
typedef decltype(lengthCompare)* FuncP2;    // 等价的类型
// useBigger 的等价声明：使用了类型别名
void useBigger3(const std::string& s1, const std::string& s2, FuncP);
void useBigger4(const std::string& s1, const std::string& s2, FuncP2);

// 返回指向函数的指针：和prog6_3_3中返回数组的指针十分类似
// 方法一：使用类型别名
using F = int(int*, int);          // F 是类型别名，不是指针
using PF = int(*) (int*, int);     // PF 是函数的指针类型
PF f1(int);          // 正确：f1返回指向函数的指针
//F f2(int);         // 错误：F是函数类型，f2不能返回一个函数  
F* f3(int);          // 正确：显示地指定返回类型是 指向函数的指针
// 方法二：直接声明
int (*f4(int)) (int*, int);
// 方法三：使用尾置返回类型
auto f5(int) -> int (*) (int*, int);

// 返回指向函数的指针 举例
decltype(sumLength)* getFcn(const std::string& s)
{
    if (s == "larger")
        return &largerLength;        // 取地址符 & 可以不加
    else if (s == "sum")
        return sumLength;

    return nullptr;
}


int main()
{
    // 定义一个函数指针：函数指针 指向 某种特定类型的函数，精准匹配
    // 函数的类型 由它的 返回类型 和 形参类型 共同决定
    bool (*pf)(const std::string&, const std::string&);          // *pf 两侧括号不可以省略
    // 为pf赋值
    pf = lengthCompare;    // 或 pf = &lengthCompare; 取地址符&是可选的
    // 可以直接使用 函数的指针 调用该函数
    bool b1 = pf("Xiaoxiang Feizi", "Lin Daiyu");
    bool b2 = (*pf)("Xiaoxiang Feizi", "Lin Daiyu");
    bool b3 = lengthCompare("Xiaoxiang Feizi", "Lin Daiyu");     // 这三种赋值语句是等价的
    std::cout << b1 << " " << b2 << " " << b3 << std::endl;
    // 可以赋值为空指针
    pf = 0;
    // 不可以赋值为 类型不匹配的函数 的指针
    //pf = sumLength;           // 错误：返回类型不匹配
    //pf = cstringCompare;      // 错误：形参类型不匹配
    
    //
    std::string::size_type sz1 = getFcn("sum")("Xiaoxiang Feizi", "Lin Daiyu");
    std::string::size_type sz2 = getFcn("larger")("Xiaoxiang Feizi", "Lin Daiyu");
    std::cout << sz1 << " " << sz2 << std::endl;

    return 0;
}

// 