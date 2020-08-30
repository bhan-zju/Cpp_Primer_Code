// prog9_2_4.cpp : 容器的定义和初始化
//

/*
顺序容器的类型：
vector
deque     双端队列
list      双向链表
forward_list   单向链表
array          固定大小数组
string
*/

/*
初始化方式：
C c

拷贝初始化
C c1(c2);
C c1 = c2;

列表初始化
C c{a,b,d};
C c = {a,b,d};

迭代器初始化
C c(b,e);             b 和 e 是迭代器，c(b,e)是对b和e指定范围中的元素的拷贝

指定容器大小
C c(n);
C c(n,t);
*/

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <deque>
#include <forward_list>
#include <array>

int main()
{
    // 列表初始化
    std::list<std::string> authors = { "Milton","Shakespeare","Austen" };
    std::vector<const char*> articles = { "a","an","the" };

    // 创建一个容器为另一个容器的拷贝时，两个 容器的类型 及其 元素的类型 都要匹配
    std::list<std::string> list2(authors);             // 正确：类型匹配
    //std::deque<std::string> authList(authors);       // 错误：容器类型不匹配
    //std::vector<std::string> words(articles);        // 错误：元素类型不匹配

    // 如果使用迭代器参数来拷贝一个范围时，则 不要求 容器类型相同，元素类型也可以不同，只要能将要拷贝的元素转换
    std::forward_list<std::string> words(articles.begin(), articles.end());
    // 可以利用迭代器拷贝一个容器的子序列
    std::list<std::string>::iterator it = ++authors.begin();
    std::deque<std::string> authList(authors.begin(), it);

    // 与顺序容器大小相关的构造函数
    std::vector<int> ivec(10, -1);                       // 10 个 -1
    std::list<std::string> svec(10, "hi");               // 10 个 hi
    std::forward_list<int> ivec2(10);                    // 10 个 0
    std::deque<std::string> svec2(10);                   // 10 个 空string

    // array 容器类型：必须同时指定 元素类型 和 大小
    std::array<int, 10> ia1;            // 10 个默认初始化的int
    std::array<int, 10> ia2 = { 0,1,2,3,4,5,6,7,8,9 };      // 列表初始化
    std::array<int, 10> ia3 = { 42 };          // ia3[0]为42，其余元素为0
    std::array<int, 10>::size_type i;       // 正确：必须同时指定元素类型和大小
    //std::array<int>::size_type j;         // 错误：array<int>不是一个类型

    // array类型可以进行拷贝或赋值
    int digs[10] = { 0,1,2,3,4,5,6,7,8,9 };
    //int cpr[10] = digs;           // 错误：内置数组不支持拷贝或赋值，见prog3_5_1
    std::array<int, 10> digits = { 0,1,2,3,4,5,6,7,8,9 };
    std::array<int, 10> copy = digits;     // 正确

}

// 
