// prog6_5_1_2.cpp : 默认实参初始值
//

#include <iostream>
#include <string>

typedef std::string::size_type sz;

sz wd = 80;
char def = ' ';
sz ht();

std::string screen(sz = ht(), sz = wd, char = def);

std::string window = screen();            // 调用 screen(ht(), 80, ' ')

void f2()
{
    def = '*';             // 改变了全局变量 def 的值
    sz wd = 100;            // 隐藏了外层定义的 wd，因此没有改变screen的实参默认值
    window = screen();       // 调用 screen(ht(), 80, '*')
}

int main()
{
    std::cout << "Hello World!\n";
}

// 