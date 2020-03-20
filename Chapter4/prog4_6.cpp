// prog4_6.cpp : 成员访问符
//

#include <iostream>
#include <string>

int main()
{
    std::string s1 = "a string", *p = &s1;
    auto n1 = s1.size();
    auto n2 = (*p).size();              // *p 必须加括号
    auto n3 = p->size();

    std::cout << "n1 = " << n1
        << "\nn2 = " << n2
        << "\nn3 = " << n3 << std::endl;

    return 0;
}

// 