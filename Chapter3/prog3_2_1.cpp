// prog3_2_1.cpp : string 对象的初始化
//

#include <iostream>
#include <string>

int main()
{
    std::string s1;                 // 默认初始化为空字符串
    std::string s2 = s1;            // 有等号的属于 拷贝初始化
    std::string s3 = "hiva";
    std::string s4("hiva");         // 不带等号的属于 直接初始化
    std::string s5(10, 'c');        // s5 的内容是 cccccccccc
    std::string s6 = std::string(7, 'a');      // s5 的拷贝初始化方式，s6 的内容是aaaaaaa

    std::cout << "s1: " << s1
        << "\ns2: " << s2
        << "\ns3: " << s3
        << "\ns4: " << s4
        << "\ns5: " << s5
        << "\ns6: " << s6 << std::endl;
       
    return 0;
}

// 