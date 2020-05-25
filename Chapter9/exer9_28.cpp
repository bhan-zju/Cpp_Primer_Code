// exer9_28.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <forward_list>

void insert_word(std::forward_list<std::string>& fst, const std::string& str1, const std::string& str2)
{
    auto prev = fst.before_begin(), curr = fst.begin();
    while (curr != fst.end()) {
        if (*curr == str1) {
            fst.insert_after(curr, str2);
            return;
        }
        ++prev;
        ++curr;
    }
    fst.insert_after(prev, str2);
    return;
}

int main()
{
    std::forward_list<std::string> fst{ "xiao","xiang","zi" };
    insert_word(fst, "xiang", "fei");
    for (auto s : fst)
        std::cout << s << " ";
    std::cout << std::endl;

    insert_word(fst, "who", "LinDaiyu");
    for (auto s : fst)
        std::cout << s << " ";
    std::cout << std::endl;

    return 0;
}

//