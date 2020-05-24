// prog9_3_3.cpp : 顺序容器中删除元素
//

/*
都不适用于array
c.pop_back()
c.pop_front()
c.erase(p)
c.erase(b, e)
c.clear()
*/

#include <iostream>
#include <list>
#include <vector>

int main()
{
    // pop_front 和 pop_back : 删除首元素和尾元素
    // pop_front 不支持 vector 和 string
    // pop_back 不支持 forward_list
    std::list<int> ilist{ 8,9,7,2,3,6,1,0,4,5,9,8,5 };
    if (!ilist.empty())
        ilist.pop_front();
    if (!ilist.empty())
        ilist.pop_back();
    for (auto i : ilist)
        std::cout << i << " ";
    std::cout << std::endl;


    // erase(p) : 从容器中删除迭代器 p 指向的元素，并返回被删元素的下一个元素的迭代器
    auto it = ilist.begin();
    // 删除容器中的奇数
    while (it != ilist.end()) {
        if (*it % 2)                       // 如果为奇数
            it = ilist.erase(it);
        else
            ++it;
    }
    for (auto i : ilist)
        std::cout << i << " ";
    std::cout << std::endl;

    // erase(b, e) : 删除迭代器b和e所指范围内的元素，返回被删的最后一个元素的下一个元素的迭代器
    auto left = ilist.begin(), right = ilist.end();
    ilist.erase(++left, --right);
    for (auto i : ilist)
        std::cout << i << " ";
    std::cout << std::endl;

    // clear() : 删除容器所有元素
    ilist.clear();   // 等价于ilist.earse(ilist.begin(), ilist.end());

    return 0;

}

// 