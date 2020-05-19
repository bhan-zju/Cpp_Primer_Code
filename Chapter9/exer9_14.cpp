// exer9_14.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <list>
#include <vector>
#include <string>

int main()
{
    std::list<const char*> clist{ "lin","dai","yu" };
    std::vector<std::string> svec;
    svec.assign(clist.cbegin(), clist.cend());
    for (auto s : svec) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    return 0;
}

