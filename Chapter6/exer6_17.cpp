// exer6_17.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

// 判断字符串对象中是否有大写
bool includeUpper(const std::string& s)
{
    for (auto c : s) {
        if (isupper(c))
            return true;
    }
    // s = "9";        // s是对实参的常量引用，不能改变s的值
    return false;
}

// 将字符串对象中所有大写改成小写
void toLower(std::string& s)
{
    for (auto& c : s)
        c = tolower(c);            // tolower(c) 是一个右值
}

int main()
{
    std::string s = "aunfhjkweSJGKNGSORINEIONFVRhfer";
    std::cout << includeUpper(s) << std::endl;
    toLower(s);
    std::cout << s << std::endl;

    return 0;
}

// 