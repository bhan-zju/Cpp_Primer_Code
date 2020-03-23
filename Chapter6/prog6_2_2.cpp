// prog6_2_2.cpp : 传引用参数
//

#include <iostream>

void reset(int& i)          // 形参是实参的引用
{
    i = 0;
}

// 返回string对象中某个指定字符c第一次出现的位置，并统计该字符出现的总次数
// 引用形参occurs用来统计字符出现的总次数
std::string::size_type find_char(const std::string& s, char c, std::string::size_type& occurs)   // 函数无需修改形参的值时最好使用 常量引用
{
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size())
                ret = i;
            ++occurs;
        }
    }

    return ret;
}

int main()
{
    int j = 42;
    reset(j);
    std::cout << j << std::endl;

    // 
    std::string str = "fahuhfueianfoehufjaiowhfiuawfjasknscbgiufeqiofehiuqhfuanchiusguiafheriuh";
    std::string::size_type occurs = 0;
    auto index = find_char(str, 'e', occurs);

    std::cout << "The char occurs " << occurs << " times.\n"
        << "The first index is " << index << std::endl;

    return 0;
}

//