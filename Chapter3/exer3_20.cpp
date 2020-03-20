// exer3_20.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<int> ivec;
    int num;
    std::cout << "输入数字：";
    while (std::cin >> num)
        ivec.push_back(num);

    if (ivec.empty()) {
        std::cout << "input at least one integer." << std::endl;
        return -1;
    }
    else if (ivec.size() == 1) {
        std::cout << ivec[0] << " don't have any adjacent elements.";
    }
    else {
        for (decltype(ivec.size()) i = 0; i != ivec.size() - 1; ++i)
            std::cout << ivec[i] + ivec[i + 1] << " ";
    }

    std::cout << std::endl;

    decltype(ivec.size()) size = ivec.size();
    if (size % 2 != 0)
        size = size / 2 + 1;
    else
        size /= 2;                // size = size / 2;

    for (decltype(ivec.size()) i = 0; i != size; ++i)
        std::cout << ivec[i] + ivec[ivec.size() - i - 1] << " ";
    std::cout << std::endl;

    return 0;
}

// 