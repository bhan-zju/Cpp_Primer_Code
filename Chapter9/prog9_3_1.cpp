// prog9_3_1.cpp : 向顺序容器添加元素
//

/*
push_back
push_front
insert
emplance
*/

// 对所有array都不支持

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <forward_list>
//#include <array>
#include "Sales_data.h"

int main()
{
    // 定义一些容器
    std::vector<std::string> vcon{ "a","an","the" };
    std::list<std::string> lcon{ "a","an","the" };
    std::deque<std::string> dcon{ "a","an","the" };
    std::forward_list<std::string> fcon{ "a","an","the" };
    std::string scon{ "toy" };



    // push_back 操作：在尾部添加元素，forward_list不支持
    std::string word{ "right" };
    vcon.push_back(word);
    lcon.push_back(word);
    dcon.push_back(word);
    //fcon.push_back(word);
    //string 也可以进行push_back操作，在末尾添加字符
    scon.push_back('s');



    // push_front 操作：在头部添加元素，vector 和 string 不支持
    word = "ctrl";
    lcon.push_front(word);
    dcon.push_front(word);
    fcon.push_front(word);



    // insert 操作：在容器任意位置插入 0个或多个 元素，forward_list提供了特殊版本的insert，见于9.3.4节
    
    // insert(p, t)  : 在迭代器 p 指向的元素 之前 插入一个值为 t 的元素，返回指向新添加的元素的迭代器
    lcon.insert(++lcon.begin(), "hello");
    vcon.insert(vcon.begin(), "hello");    // vector 虽然不支持push_front，但可以通过insert在其头部添加元素
    // insert(p, n, t)  : 在迭代器 p 指向的元素 之前 插入 n 个 值为 t 的元素，返回指向 新添加的 第一个元素 的迭代器
    dcon.insert(dcon.begin() + 2, 5, "nice");
    // insert(p, b, e)  : 在迭代器 p 指向的元素 之前 插入 迭代器b和e指定范围内 的元素，返回指向 新添加的 第一个元素 的迭代器
    lcon.insert(lcon.begin(), dcon.end() - 5, dcon.end());
    //lcon.insert(lcon.begin(), lcon.begin(), lcon.end());  // 书上说运行时错误(但实际可以运行)：传递给insert一对迭代器，不能指向添加元素的目标容器
    // insert(p, il)  : 在迭代器 p 指向的元素 之前 插入 花括号包围的元素值列表il，返回指向 新添加的 第一个元素 的迭代器
    vcon.insert(vcon.begin() + 2, { "time","flies","away" });
    // 使用insert的返回值，可以在容器中一个特定位置反复插入元素
    std::string str;
    auto iter = lcon.begin();
    std::cout << "Enter words inserted into lcon:\n";
    while (std::cin >> str)
        iter = lcon.insert(iter, str);     // 等价于调用push_front


    // 输出这些容器中的值
    std::cout << "vcon:\n";
    for (auto v : vcon)
        std::cout << v << " ";
    std::cout << std::endl;

    std::cout << "lcon:\n";
    for (auto l : lcon)
        std::cout << l << " ";
    std::cout << std::endl;

    std::cout << "dcon:\n";
    for (auto d : dcon)
        std::cout << d << " ";
    std::cout << std::endl;

    std::cout << "fcon:\n";
    for (auto f : fcon)
        std::cout << f << " ";
    std::cout << std::endl;

    std::cout << "scon:\n";
    for (auto s : scon)
        std::cout << s << " ";
    std::cout << std::endl;



    // emplace操作：将参数传递给元素类型的构造函数
    // emplace, emplace_front, emplace_back
    std::deque<Sales_data> sdeq;
    sdeq.emplace_back("ixtext", 25, 15.99);        // 使用3个参数的Sales_data构造函数
    sdeq.emplace_back();                           // 使用Sales_data的默认构造函数
    sdeq.emplace(sdeq.begin(), "ixtext");          // 使用1个参数的Sales_data构造函数
    sdeq.emplace_front("ixtext", 15, 15.99);       // 在头部添加
    //sdeq.push_back("ixtext", 10, 15.99);                 // 错误
    sdeq.push_back(Sales_data("ixtext", 10, 15.99));       // 正确

}

// 