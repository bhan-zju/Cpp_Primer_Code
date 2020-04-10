// prog7_4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Screen.h"
#include "Window_mgr.h"

int main()
{
    Screen::pos ht = 24, wd = 80;           // 使用Screen定义的pos类型
    Screen scr(ht, wd, ' ');
    Screen* p = &scr;
    char c = scr.get();
    c = p->get();
}

// 