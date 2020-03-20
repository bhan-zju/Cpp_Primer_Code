// exer4_21.cpp : 将容器中的奇数翻倍
//

#include <iostream>
#include <vector>

int main()
{
    // 生成一个斐波那契数列的前20位并输出
    std::vector<int> fi{ 0,1 };
    std::cout << "Init fi:" << std::endl;
    std::cout << fi[0] << " " << fi[1] << " ";
    for (int i = 2; i < 20; ++i) {
        fi.push_back(fi[i - 2] + fi[i - 1]);
        std::cout << fi[i] << " ";
    }
    std::cout << std::endl;

    auto iter = fi.begin();
    while (iter != fi.end()) {
        *iter = ((*iter) % 2 == 0) ? (*iter) : (2 * (*iter));
        ++iter;
    }
    std::cout << "After fi: " << std::endl;
    for (auto i : fi)
        std::cout << i << " ";
    std::cout << std::endl;
    
    return 0;
}

// 