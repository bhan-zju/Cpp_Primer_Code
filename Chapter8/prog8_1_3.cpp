// prog8_1_3.cpp : 管理输出缓冲
//

#include <iostream>

int main()
{
    // 刷新输出缓冲区
    std::cout << "hi!" << std::endl;       // endl：完成换行 并 刷新缓冲区
    std::cout << "hi!" << std::flush;       // flush：刷新缓冲区，不输出其他额外字符
    std::cout << "hi!" << std::ends;        // ends：插入一个空字符，然后刷新缓冲区
    std::cout << "hi!" << std::endl;

    // unitbuf操作符
    std::cout << std::unitbuf;     // 所有输出操作后都会立即刷新缓冲区
    std::cout << std::nounitbuf;   // 回到正常的缓冲方式

    // 关联输入和输出流
    std::cin.tie(&std::cout);     // cin 和 cout关联在一起
    std::ostream* old_tie = std::cin.tie();            // .tie()返回 cin关联的对象 的指针
    std::cin.tie(nullptr);      // cin不再与其他流关联
    std::cin.tie(&std::cerr);      // cin 和 cerr 关联，读取cin会刷新cerr而不是cout
    std::cin.tie(old_tie);         // cin 重新和 cout 关联
}

// 
