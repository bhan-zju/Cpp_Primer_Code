// prog2_3_2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
    double dval = 4.2;
    double *pd1 = &dval;    //指针*pd1，&是取地址符
    double *pd2 = pd1;
    double *pd3, *pd4;
    pd3 = pd1;
    pd4 = &dval;           //pd1, pd2, pd3, pd4都是dval的指针

    std::cout << "dval = " << dval << "; *pd1 = " << *pd1 << std::endl;        //*变成解引用符

    *pd2 = 3.4;
    std::cout << "dval = " << dval << "; *pd3 = " << *pd3 << std::endl;

    // 空指针的三种生成方法：
    int* p1 = nullptr;
    int* p2 = 0;
    int* p3 = NULL;

    return 0;

}

// 