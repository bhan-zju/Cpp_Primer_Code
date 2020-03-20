// prog5_4_4.cpp : do while 语句
//

#include <iostream>
#include <string>

int main()
{
    // 不断提示用户输入两个数，然后求和
    std::string rsp;
    do {
        std::cout << "please enter two values: ";
        int val1 = 0, val2 = 0;
        std::cin >> val1 >> val2;
        std::cout << "The sum of " << val1 << " and " << val2
            << " = " << val1 + val2 << "\n\n"
            << "More? Enter yes or no: ";
        std::cin >> rsp;
    } while (!rsp.empty() && rsp[0] != 'n');       // 结尾处要加分号

    return 0;
}

// 