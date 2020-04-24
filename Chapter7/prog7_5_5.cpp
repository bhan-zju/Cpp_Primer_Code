// prog7_5_5.cpp : 聚合类
//

/*
聚合类：
1.所有成员都是public
2.没有定义构造函数
3.没有类内初值
4.没有基类，没有virtual函数
*/

#include <iostream>

struct Data {
    int ival;
    std::string s;
};

int main()
{
    // 列表初始化 聚合类对象
    // 初始值顺序必须与类成员声明顺序一致
    Data vall{ 0,"Anna" };
}

//