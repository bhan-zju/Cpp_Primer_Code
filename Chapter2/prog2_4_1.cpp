// prog2_4_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
    int i = 42;
    const int &r1 = i;
    const int &r2 = 42;
    const int &r3 = r1 * 2;
    std::cout << "i = " << i << "\n"
        << "r1 = " << r1 << "\n"
        << "r2 = " << r2 << "\n"
        << "r3 = " << r3 << std::endl << std::endl;

    i = 21;
    std::cout << "i = " << i << "\n"
        << "r1 = " << r1 << "\n"            // r1的值会跟着i变成21
        << "r2 = " << r2 << "\n"
        << "r3 = " << r3 << std::endl << std::endl;

    double dval = 3.14;
    const int &ri = dval;
    std::cout << "dval = " << dval << "\n"
        << "ri = " << ri << std::endl << std::endl;
    dval = 6.28;
    std::cout << "dval = " << dval << "\n"
        << "ri = " << ri << std::endl;

    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
