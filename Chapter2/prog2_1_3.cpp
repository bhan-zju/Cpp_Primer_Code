// prog2_1_3.cpp : 字面值常量
//

#include <iostream>

int main()
{
    std::cout << "\n";                 // 换行 
	std::cout << "\tHi\n";             // 制表符
	std::cout << '\a';                 // 响铃，或 '\7'
	std::cout << "Hi \x4dO\115!\n";    // Hi MOM!   // “\”后面跟8进制数 或 “\x”后面跟16进制数    // \x4d 和 \115 都是 M
	std::cout << "\\n\n";              // 输出 \n 然后换行
	std::cout << 0x33 << "\n";         // 输出51，即十六进制的33
	std::cout << 033 << "\n";          // 输出27，即八进制的33
    
    //exer2_6
    std::cout << "Who goes with F\145rgus?\012";        // \145是e，\012是换行

    //exer2_8
    std::cout << "2\155\n" << "2\t\155\n";
}


