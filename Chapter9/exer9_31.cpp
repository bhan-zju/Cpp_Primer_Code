// exer9_31.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <list>
#include <forward_list>

int main()
{
    std::list<int> li{ 9,8,1,7,4,3,0,6,5 };
    auto iter = li.begin();
    // 删除偶数元素，复制每个奇数元素
    while (iter != li.end()) {
        if (*iter % 2) {
            iter = li.insert(iter, *iter);
            // 主要这里不一样
            ++iter;
            ++iter;            // iter 向前移动两步
        }
        else {
            iter = li.erase(iter);
        }
    }
    for (auto i : li)
        std::cout << i << " ";
    std::cout << std::endl;

    std::forward_list<int> fi{ 9,8,1,7,4,3,0,6,5 };
    auto prev = fi.before_begin(), fiter = fi.begin();
    // 删除偶数元素，复制每个奇数元素
    while (fiter != fi.end()) {
        if (*fiter % 2) {
            prev = fi.insert_after(prev, *fiter);    // insert_after(p, ) 返回指向 最后一个插入元素的 迭代器
            ++fiter;
            ++prev;
        }
        else {
            fiter = fi.erase_after(prev);      // erase_after() 返回 指向 被删元素 之后元素的 迭代器
        }
    }
    for (auto i : fi)
        std::cout << i << " ";
    std::cout << std::endl;
}


// 