// prog9_4.cpp : vector对象的增长
//

/*
容器大小管理操作
c.capaity()           // 当不重新分配内存空间的话，c可以保存多少元素
c.reserve(n)          // 为c分配 至少能容纳n个元素 的内存空间
c.shrink_to_fit()     // 请求将capacity()减少为与size()相同的大小，只是一个请求，并不保证能退换内存
*/

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ivec;
    std::cout << "ivec: size: " << ivec.size() 
        << " capacity: " << ivec.capacity() << std::endl;

    // 向ivec中添加24个元素
    for (std::vector<int>::size_type ix = 0; ix != 24; ++ix)
        ivec.push_back(ix);
    std::cout << "ivec: size: " << ivec.size()
        << " capacity: " << ivec.capacity() << std::endl;

    // 使用reserve
    ivec.reserve(50);          // 将capacity设定为至少50，可能更大
    std::cout << "ivec: size: " << ivec.size()
        << " capacity: " << ivec.capacity() << std::endl;

    // 添加元素用光多余容量
    while (ivec.size() != ivec.capacity()) {
        ivec.push_back(0);
    }
    std::cout << "ivec: size: " << ivec.size()
        << " capacity: " << ivec.capacity() << std::endl;

    // 再添加一个元素
    ivec.push_back(42);
    std::cout << "ivec: size: " << ivec.size()
        << " capacity: " << ivec.capacity() << std::endl;

    // 请求归还多余内存
    ivec.shrink_to_fit();
    std::cout << "ivec: size: " << ivec.size()
        << " capacity: " << ivec.capacity() << std::endl;

    return 0;
}

// 
