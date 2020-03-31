// exer6_44.cpp : 编写内联函数
//

#include <iostream>

inline bool isShorter(const std::string& s1, const std::string& s2)
{
    return s1.size() < s2.size();
}

int main()
{
    std::string s1 = "Xiaoxiang Feizi", s2 = "Lin Daiyu";
    std::cout << isShorter(s1, s2) << std::endl;
    std::cout << isShorter(s2, s1) << std::endl;

    return 0;
}

// 