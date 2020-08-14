// prog3_2_2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;                         // 遇见空白处即停止，如果输入Hello World，则s为"Hello"
    std::cout << s << std::endl;

    std::string s1, s2;
    std::cin >> s1 >> s2;
    std::cout << s1 << s2 << std::endl;

//    std::string word;
//    while (std::cin >> word)
//        std::cout << word << std::endl;      // 输入ctrl+z结束循环


    // string对象的比较
    std::string str1 = "abstra", str2 = "abstract", str3 = "abstratC", str4 = "abstratc";    // 字符串的比较，按字典顺序
    std::cout << (str4 > str3) << (str3 > str2) << (str2 > str1) << std::endl;
    std::string str5 = "z", str6 = "a", str7 = "Z", str8 = "A", str9 = "9", str10 = "1", str11 = "0";  // z > a > Z > A > 9 > 1 > 0
    std::cout << (str5 > str6) << (str6 > str7) << (str7 > str8) << (str8 > str9) << (str9 > str10) << (str10 > str11) << std::endl;


    // string对象的相加
    std::string s3 = "hello, ", s4 = "world\n";
    std::string s5 = s3 + s4;             // 两个string对象相加
    s3 += s4;                        // s3 = s3 + s4
    std::cout << "s5: " << s5 << "s3: " << s3 << std::endl;

    std::string s6 = "hello", s7 = "world";
    std::string s8 = s6 + ", " + s7 + '.';          //string对象 和 字符串字面值 或 字符字面值 相加
    std::string s9 = s6 + ", ";
    //std::string s10 = "hello" + ", ";             // 错误：不能把字面值直接相加
    std::string s11 = s6 + ", " + "world";          // s11 = (s6 + ", ") + "world";
    std::string s12 = "hello, " + s7 + '!';        // s12 = ("hello, " + s7) + '!';
	//std::string s13 = "hello" + ", " + s7;       // 错误：s13 = ("hello" + ", ") + s7;
	std::cout << "s8: " << s8 << "\n" << "s9: " << s9 << "\n" << "s11: " << s11 << "\n" << "s12: " << s12 << std::endl;




    std::string line;
    while (std::getline(std::cin, line))           // std::getline(cin, s) 每次读取一行，遇见换行符才停止读取
        if (!line.empty()) {                    // .empty()判断字符串是否为空串
            std::cout << line << std::endl;     // 如果遇见空字符串（即空行），则跳过不输出
            std::cout << line.size() << std::endl;     // .size()为字符串的长度
        }
    return 0;
}

// 
