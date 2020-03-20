// prog5_3_2.cpp : switch 语句
//

#include <iostream>

int main()
{
    // 统计 5 个元音字母出现的次数
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, otherCnt = 0;
    char ch;
    while (std::cin >> ch) {
        switch (ch) {
            // case 标签，必须是整型常量表达式
            case 'a':
                ++aCnt;
                break;
            case 'e':
                ++eCnt;
                break;
            case 'i':
                ++iCnt;
                break;
            case 'o':
                ++oCnt;
                break;
            case 'u':
                ++uCnt;
                break;
            // 如果上述都不符合，则执行default标签
            default:
                ++otherCnt;
                break;
        }
        if (std::cin.get() == '\n')
            break;
    }

    // 输出结果
    std::cout << "Number of vowel a:\t" << aCnt << '\n'
        << "Number of vowel e:\t" << eCnt << '\n'
        << "Number of vowel i:\t" << iCnt << '\n'
        << "Number of vowel o:\t" << oCnt << '\n'
        << "Number of vowel u:\t" << uCnt << '\n'
        << "Number of others:\t" << otherCnt << std::endl;

    // 统计元音和非元音字母出现的总次数
    unsigned vowelCnt = 0;
    otherCnt = 0;
    char ch2;
    while (std::cin >> ch2) {
        switch (ch2) {
            case 'a': 
            case 'e': 
            case 'i': 
            case 'o': 
            case 'u':             // 直接写成一行也可以 case 'a': case 'e': case 'i': case 'o': case 'u':
                ++vowelCnt;
                break;
            default:
                ++otherCnt;
                break;
        }
        if (std::cin.get() == '\n')
            break;
    }
    std::cout << "Number of vowel:\t" << vowelCnt << '\n'
        << "Number of others:\t" << otherCnt << std::endl;

    return 0;
}

// 