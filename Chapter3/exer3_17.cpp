// exer3_17.cpp : 把所有的词改写成大写形式
//

#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> svec;
    std::string str;
    while (std::cin >> str)
        svec.push_back(str);

    for (auto &s : svec) {
        for (auto& c : s)
            c = std::toupper(c);
        std::cout << s << std::endl;
    }

}

// 