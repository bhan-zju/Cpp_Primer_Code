// exer5_11.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

int main()
{
    char ch;
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, otherCnt = 0;
    int spaceCnt = 0, _tCnt = 0, _nCnt = 0;
    while (std::cin >> std::noskipws >> ch) {         // std::noskipws 不忽略空白
        switch (ch) {
            case 'A':case 'a':
                ++aCnt;
                break;
            case 'E':case 'e':
                ++eCnt;
                break;
            case 'I':case 'i':
                ++iCnt;
                break;
            case 'O':case 'o':
                ++oCnt;
                break;
            case 'U':case 'u':
                ++uCnt;
                break;
            case ' ':
                ++spaceCnt;
                break;
            case '\t':
                ++_tCnt;
                break;
            case '\n':
                ++_nCnt;
                break;
            default:
                ++otherCnt;
                break;
        }
    }
    std::cout << "Number of vowel a or A:\t" << aCnt << '\n'
        << "Number of vowel e or E:\t" << eCnt << '\n'
        << "Number of vowel i or I:\t" << iCnt << '\n'
        << "Number of vowel o or O:\t" << oCnt << '\n'
        << "Number of vowel u or U:\t" << uCnt << '\n'
        << "Number of space:\t" << spaceCnt << '\n'
        << "Number of tab:\t" << _tCnt << '\n'
        << "Number of _n:\t" << _nCnt << '\n'
        << "Number of others:\t" << otherCnt << std::endl;

    return 0;
}

// 