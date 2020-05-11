// exer8_10.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main()
{
    std::ifstream ifs("text8_10.txt");
    if (!ifs) {
        std::cerr << "Coundn't open: text8_10.txt" << std::endl;
        return -1;
    }

    std::vector<std::string> lineVec;
    std::string line;
    while (getline(ifs, line)) {              // 将text8_10.txt中的行读入line
        lineVec.push_back(line);
    }

    for (auto& s : lineVec) {
        std::istringstream ist(s);
        std::string word;
        while (ist >> word)
            std::cout << word << std::endl;
    }

    return 0;
}

