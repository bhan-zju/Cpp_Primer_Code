// prog9_3_6.cpp : 容器操作可能使迭代器失效
//

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vi{ 9,8,1,7,4,3,0,6,5 };
    auto iter = vi.begin();
    // 删除偶数元素，复制每个奇数元素
    while (iter != vi.end()) {                 // 不应写为：auto end = vi.end(); while(iter != end);  因为改变vi会导致迭代器end失效，而应该每个循环重新调用一次vi.end()
        if (*iter % 2) {         // 如果为奇数
            iter = vi.insert(iter, *iter);          // 复制该奇数，插入到该位置之前，iter指向新插入元素
            iter += 2;            // iter 向前移动两步
        }
        else {        // 如果为偶数
            iter = vi.erase(iter);       // 删除该元素，iter指向被删元素的下一个元素
        }
    }

    for (auto i : vi)
        std::cout << i << " ";
    std::cout << std::endl;
}

// 