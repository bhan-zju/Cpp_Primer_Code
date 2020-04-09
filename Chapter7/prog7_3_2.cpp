// prog7_3_2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Screen.h"

int main()
{
    Screen myScreen(5, 3);
    myScreen.move(4, 0).set('#');    // 等价于   myScreen.move(4, 0);   myScreen.set('#'); 

    myScreen.display(std::cout);         // 将调用 Screen& display(std::ostream& os) 
    std::cout << std::endl;
    myScreen.set('*').display(std::cout);     // 将调用 Screen& display(std::ostream& os) 
    std::cout << std::endl;

    const Screen blank(5, 3);
    blank.display(std::cout);         // 将调用 const Screen& display(std::ostream& os) const
    std::cout << std::endl;

    return 0;
}

// 