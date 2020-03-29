// prog6_4.cpp : 重载
//

// const_cast 和重载
// const_cast 见 prog4_11_3

#include <iostream>
#include <string>

// 比较两个string对象的长度，返回较短的那个的引用
const std::string& shorterString(const std::string& s1, const std::string& s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

// 重载，将常量引用换回一个普通引用
std::string& shorterString(std::string& s1, std::string& s2)
{
    auto& r = shorterString(const_cast<const std::string&>(s1), const_cast<const std::string&>(s2));
    return const_cast<std::string&>(r);
}

int main()
{
    std::string s1{ "Xiaoxiangfeizi" }, s2{ "Lindaiyu" };
    auto s = shorterString(s1, s2);                    // 运行时将调用 std::string& shorterString(std::string& s1, std::string& s2)
    std::cout << s << std::endl;

    return 0;
}

// 