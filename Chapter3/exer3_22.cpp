// exer3_22.cpp : 将文本中的第一段文字改成大写
//

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string nullstr;       // 定义一个空字符串，nullstr.empty() == True
    std::vector<std::string> text{ "I", " ", "love", " ", "you.", nullstr, "Do", " ", "you", " love me", "?" };    // 两段文字用空字符串间隔
    // 将第一段文字改成大写
    for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)     // it->empty() 等价于 (*it).empty;
        for (auto& c : *it)
            c = std::toupper(c);
    // 输出这段文字
    for (auto s : text)
        if (!s.empty())
            std::cout << s;
        else
            std::cout << "\n";
    std::cout << std::endl;

    return 0;
}

// 