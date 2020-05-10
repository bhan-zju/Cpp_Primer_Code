// prog8_2_1.cpp : 文件流对象
//

#include <iostream>
#include <fstream>
//#include "Sales_data.h"

int main()
{
    // 以下txt文件 均放在 本cpp文件 所在的文件夹 下
    std::string ifile = "LinDaiyu.txt";         // 
    char ca[] = "XiaoxiangFeizi.txt";           // C风格字符串
    char blank[] = "out.txt";            // 该文件当前是空文件

    std::ifstream in1(ifile);        // 构造一个ifstream对象，并打开给定文件，文件名可以是string对象，也可以是C风格字符串
    std::ifstream in2;               // 构造一个ifstream对象，暂时不关联到任何文件
    in2.open(ca);                // 将in2与文件ca绑定
    std::ofstream out;           // 输出文件流，未关联到任何文件

    if (in1) {               // 如果能打开in1指定文件
        std::string lin;     
        in1 >> lin;           // 将in1所关联的文件中的内容写入字符串lin
        std::cout << lin << std::endl;
    }
    else {
        std::cout << "couldn't open: " << ifile << std::endl;
    }

    if (in2) {               // 如果能打开in2指定文件
        std::string lin;
        in2 >> lin;
        std::cout << lin << std::endl;
    }
    else {
        std::cout << "couldn't open: " << ca << std::endl;
    }

    out.open(blank);     // 将out和blank关联
    if (out) {
        out << "Add_these_words_into_it" << std::endl;          // 这些内容将被写入out.txt文件中
    }
    else {
        std::cout << "couldn't open: " << blank << std::endl;
    }

    in1.close();       // 关闭in1关联文件
    in1.open(blank);     // 打开另一个文件
    if (in1) {               // 如果能打开in1指定文件
        std::string unknow;
        in1 >> unknow;
        std::cout << unknow << std::endl;
    }
    else {
        std::cout << "couldn't open: " << blank << std::endl;
    }

}

