// prog9_3_2.cpp : 访问顺序容器中的元素
//

/*
c.back()
c.front()
c[n]
c.at(n)
*/

#include <iostream>
#include <vector>

int main()
{
    // c.front() 返回首元素的引用，所有顺序容器都支持
    // c.back()  返回尾元素的引用，不支持forward_list
    std::vector<int> ivec{ 8,9,3 };
    if (!ivec.empty()) {
        auto val1 = *ivec.begin(), val2 = ivec.front();
        auto last = ivec.end();
        auto val3 = *(--last), val4 = ivec.back();

        std::cout << "val1 = " << val1 << "\n";
        std::cout << "val2 = " << val2 << "\n";
        std::cout << "val3 = " << val3 << "\n";
        std::cout << "val4 = " << val4 << std::endl;

        // .front() 和 .back() 返回的都是引用
        int& v = ivec.back();
        v = 7;
        std::cout << ivec.back() << std::endl;

    }

    // 当容器为空时
    std::vector<int> ivec2;
    //std::cout << ivec2.front() << std::endl;
    //std::cout << ivec2.back() << std::endl;

    // 下标访问，支持可以随机访问的容器，string, vector, deque, array，不支持 list 和 forward_list
    // c[n] 和 c.at(n)
    std::cout << ivec[2] << std::endl;
    std::cout << ivec.at(2) << std::endl;
    // 区别在于当下标越界时
    //std::cout << ivec[5] << std::endl;            // 运行时错误
    //std::cout << ivec.at(5) << std::endl;         // 抛出一个 out_of_range 异常（见5.6节）
    
}

//