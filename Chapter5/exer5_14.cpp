// exer5_14.cpp : 
//

#include <iostream>
#include <string>

int main()
{
    std::string input;
    std::string last, continues;
    int Cnt = 0, maxCnt = 0;       // Cnt 是当前输入的计数
    while (std::cin >> input) {
        if (input != last) {
            Cnt = 1;
        }
        else {
            ++Cnt;
        }
        if (Cnt > maxCnt) {
            maxCnt = Cnt;
            continues = input;
        }
        last = input;
    }

    std::cout << "The word \"" << continues << "\" occurs max times: " << maxCnt << std::endl;

    return 0;
}

// 