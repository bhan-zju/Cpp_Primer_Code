// porg9_3_4.cpp : forward_list 的特殊操作
//

/*
// 返回指向链表首元素之前的不存在元素的迭代器
lst.before_begin()
lst.cbefore_begin()

// 在 迭代器p所指元素 之后的位置 插入元素，并返回 指向最后一个插入元素 的 迭代器
lst.insert_after(p, t)
lst.inster_after(p, n, t)
lst.inster_after(p, b, e)
lst.inster_after(p, il)
lst.emplace_after(p, args)

// 删除 迭代器p所指位置 之后的元素，并返回 指向 被删元素之后 元素的 迭代器
lst.erase_after(p)
// 删除 从b之后直到(但不包含)e之间的元素
lst.erase_after(b, e)
*/

#include <iostream>
#include <forward_list>

int main()
{
    std::forward_list<int> flst{ 8,9,7,2,3,6,5,8,8,9,0 };
    auto prev = flst.before_begin();        // prev 指向“首前元素”
    auto curr = flst.begin();               // curr 指向 首元素
    while (curr != flst.end()) {
        if (*curr % 2)                    // 如果curr所指为奇数
            curr = flst.erase_after(prev);    // 删除并令curr指向下一个元素，prev不用变
        else {
            // prev 和 curr 都向前移
            prev = curr;
            ++curr;
        }
    }

    for (auto i : flst) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// 