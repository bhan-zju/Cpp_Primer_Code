// prog2_3_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
    int ival = 1024, &refVal = ival;    // reference引用，相当于给ival起了一个另一个名字，引用变量必须初始化
    
    std::cout << "refVal = " << refVal << "; ival = " << ival << std::endl;
    refVal = 23;
    std::cout << "refVal = " << refVal << "; ival = " << ival << std::endl;
    return 0;
}

//