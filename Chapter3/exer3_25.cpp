// prog3_25.cpp : 用迭代器的方法，以10分为一个分数段统计成绩的数量：0~9，10~19，…，90~99,100
//

#include <iostream>
#include <vector>

int main()
{
    std::vector<unsigned> scores(11, 0);       // 11个分数段的人数，全都初始化为0
    auto beg = scores.begin();

    unsigned grade;
    while (std::cin >> grade)            // 读取成绩
        if (grade <= 100)                // 只处理有效的成绩
            ++* (beg + (grade / 10));        // 将对应分数段的计数加1，整数 / 整数 = 整数，因此 分数/10 正好等于所对应分数段的索引

    for (auto i : scores)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}

