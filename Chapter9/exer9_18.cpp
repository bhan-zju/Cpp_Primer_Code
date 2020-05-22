// exer9_18.cpp : 
//

#include <iostream>
#include <deque>

int main()
{
    std::string word;
    std::deque<std::string> sde;
    while (std::cin >> word)
        sde.push_back(word);

    for (auto iter = sde.begin(); iter != sde.end(); ++iter)
        std::cout << *iter << std::endl;

    return 0;
}

// 