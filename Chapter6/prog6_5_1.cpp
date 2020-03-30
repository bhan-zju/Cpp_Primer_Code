// prog6_5_1.cpp : 默认实参
//

#include <iostream>
#include <string>

typedef std::string::size_type sz;

std::string screen(sz ht = 24, sz wid = 80, char backgrnd = ' ');    // 一旦某个形参被赋予了默认值，它后面的所有形参都必须有默认值

int main()
{
    std::string window;
    window = screen();                    // 等价于 screen(24, 80, ' ')
    window = screen(66);                  // 等价于 screen(66, 80, ' ')
    window = screen(66, 256);             // 等价于 screen(66, 256, ' ')
    window = screen(66, 256, '#');               // screen(66, 256, '#')

    //window = screen(, , '?');           // 错误：只能省略尾部的实参
    window = screen('?');                 // 正确：等价于 screen('?', 80, ' ')，char 类型的 '?' 会自动转换成无符号类型的 63
}

// 