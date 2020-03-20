// prog3_4_1.cpp : 迭代器
//

#include <iostream>
#include <string>
#include <vector>

int main()
{
    // 将string对象的第一个字母改成大写形式
    std::string s("some string");
    if (s.begin() != s.end()) {                 // 判断 s 是否非空，即if(!s.emoty())
        auto it = s.begin();                   // 迭代器
        *it = std::toupper(*it);               // *it 返回迭代器 it 所指元素的引用，类似于指针的解引用
    }
    std::cout << s << std::endl;

    // 将第一个词改写成大写形式
    for (auto iter = s.begin(); iter != s.end() && !isspace(*iter); ++iter)      // 遇见空白处即停止循环
        *iter = std::toupper(*iter);
    std::cout << s << std::endl;

    std::vector<int> v;
    const std::vector<int> cv;           // 常量容器
    auto it1 = v.begin();             // it1 的类型是 std::vector<int>::iterator
    auto it2 = cv.begin();            // it2 的类型是 std::vector<int>::const_iterator
    auto it3 = v.cbegin();            // it1 的类型是 std::vector<int>::const_iterator，该类型不能改变所指对象的值

    std::string nullstr;       // 定义一个空字符串，nullstr.empty() == True
    std::vector<std::string> text{ "I", " ", "love", " ", "you.", nullstr, "Do", " ", "you", " love me", "?" };    // 两段文字用空字符串间隔
    // 只输出第一段文字
    for (auto iter1 = text.cbegin(); iter1 != text.cend() && !iter1->empty(); ++iter1)     // iter1->empty() 等价于 (*iter1).empty;
        std::cout << *iter1;
    std::cout << std::endl;

    return 0;
}

// 