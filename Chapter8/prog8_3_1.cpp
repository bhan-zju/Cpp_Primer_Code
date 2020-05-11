// prog8_3_1.cpp : istringstream
//

#include <iostream>
#include <sstream>
#include <vector>

struct PersonInfo
{
    std::string name;
    std::vector<std::string> phones;
};

int main()
{
    std::string line, word;
    std::vector<PersonInfo> people;

    while (getline(std::cin, line)) {            // 从标准输入读入数据
        PersonInfo info;
        std::istringstream record(line);     // 将record绑定到字符串line
        record >> info.name;           // 从line中读取名字
        while (record >> word) {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }

    // 检验程序
    for (auto& member : people) {
        std::cout << member.name << ":" << std::endl;
        for (auto& phone : member.phones) {
            std::cout << phone << " ";
        }
        std::cout << std::endl;
    }
}

