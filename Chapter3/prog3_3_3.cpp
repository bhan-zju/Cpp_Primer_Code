// prog3_3_3.cpp : vector 的常用操作
//

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{ 1,2,3,4,5,6,7,8,9 };
    for (auto &i : v)         // 范围 for 语句，这里 i 是对 v 中每个元素的 引用
        i *= i;          // i = i * i;
    for (auto i : v)
        std::cout << i << " ";
    std::cout << std::endl;

    // 以10分为一个分数段统计成绩的数量：0~9，10~19，…，90~99,100
    std::vector<unsigned> scores(11, 0);       // 11个分数段的人数，全都初始化为0
    unsigned grade;
    while (std::cin >> grade)         // 读取成绩
        if (grade <= 100)             // 只处理有效的成绩
            ++scores[grade / 10];     // 将对应分数段的计数加1，整数 / 整数 = 整数，因此 分数/10 正好等于所对应分数段的索引
    for (auto i : scores)
        std::cout << i << " ";
    std::cout << std::endl;

    // 不能用下标的形式添加元素
    std::vector<int> ivec;     // 空vector对象
    for (decltype(ivec.size()) ix = 0; ix != 10; ++ix)
        //ivec[ix] = ix;         // 严重错误：ivec不包含任何元素，不能赋值
        ivec.push_back(ix);
    for (auto i : ivec)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}

// 