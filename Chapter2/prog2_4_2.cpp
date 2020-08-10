// prog2_4_2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
    double r1 = 3.14;
    double r2 = 6.28;
    double r3 = 9.42;
    double r4 = 12.56;
    const double r5 = 15.7;
    const double r6 = 18.84;
    double r7 = 201;
    const double r8 = 202;

    double *p1 = &r1;    // 普通指针
    const double *p2 = &r5, *p3;    // 指向常量的指针，可以不初始化，但不能改变所指对象的值
    p3 = &r2;       //指向常量的指针也可以指向非常量，但不能改变所指对象的值
    double *const p4 = &r3;     //常量指针，必须初始化，且指针不能再指向其他对象，不能用于指向常量
    const double *const p5 = &r6;     //指向常量的常量指针，必须初始化，且指针不能再指向其他对象
    const double *const p6 = &r4;     //指向常量的常量指针，也可以指向非常量

    std::cout << "double *p1 -> r1 = " << *p1 << "\n"
		<< "const double *p2 -> r5 = " << *p2 << "\n"
		<< "const doubel *p3 -> r2 = " << *p3 << "\n"
		<< "double *const p4 -> r3 = " << *p4 << "\n"
		<< "const double *const p5 -> r6 = " << *p5 << "\n"
		<< "const double *const p6 -> r4 = " << *p6 << "\n" << std::endl;

	r1 = 100;
	r2 = 101;
	r3 = 102;
	r4 = 103;
	std::cout << "double *p1 -> r1 = " << *p1 << "\n"
		<< "const double *p2 -> r5 = " << *p2 << "\n"
		<< "const doubel *p3 -> r2 = " << *p3 << "\n"
		<< "double *const p4 -> r3 = " << *p4 << "\n"
		<< "const double *const p5 -> r6 = " << *p5 << "\n"
		<< "const double *const p6 -> r4 = " << *p6 << "\n" << std::endl;

	*p1 = 200;
	p2 = &r7;         // 指向常量的指针，可以改变所指的对象，但不能改变所指对象的值
	p3 = &r8;
	*p4 = 203;        // 常量指针，不能改变所指的对象，但能改变所指对象的值
	std::cout << "double *p1 -> r1 = " << r1 << "\n"      //输出变成r1而不是*p1，效果是一样的
		<< "const double *p2 -> r7 = " << *p2 << "\n"
		<< "const doubel *p3 -> r8 = " << *p3 << "\n"
		<< "double *const p4 -> r3 = " << r3 << "\n"      //输出变成r3而不是*p4，效果是一样的
		<< "const double *const p5 -> r6 = " << *p5 << "\n"
		<< "const double *const p6 -> r4 = " << *p6 << "\n" << std::endl;

    return 0;

}

