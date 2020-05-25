// prog9_3_5.cpp : 改变容器大小
//

/*
resize(n)
resize(n, t)
*/

#include <iostream>
#include <list>

int main()
{
    std::list<int> ilist(10, 42);
    ilist.resize(15);            // ilist的末尾 将添加 5个 值为0 的元素
    for (auto i : ilist)
        std::cout << i << " ";
    std::cout << std::endl;

    ilist.resize(25, -1);       // ilist的末尾 将继续添加 10个 值为-1 的元素
    for (auto i : ilist)
        std::cout << i << " ";
    std::cout << std::endl;

    ilist.resize(5);        // 从ilist末尾 删除20个元素
    for (auto i : ilist)
        std::cout << i << " ";
    std::cout << std::endl;
}

// 