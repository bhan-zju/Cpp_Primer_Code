// prog9_2_5.cpp : 赋值和swap
//

#include <iostream>
#include <array>
#include <vector>
#include <list>

int main()
{
    std::array<int, 10> a1 = { 0,1,2,3,4,5,6,7,8,9 };
    std::array<int, 10> a2 = { 0 };             // 所有元素值均为0
    a1 = a2;      // 替换a1中的元素
    a2 = { 0 };   // 书上说不能将一个花括号列表赋予数组
    for (auto a : a2) {
        std::cout << a << " ";
    }
    std::cout << std::endl;

    // 赋值操作必须要两容器类型相同
    std::list<std::string> names;
    std::vector<const char*> oldstyles;
    //names = oldstyles;           // 错误：容器类型不匹配
    // assign函数允许不同类型容器的赋值
    names.assign(oldstyles.cbegin(), oldstyles.cend());
    names.assign({ "a","an","the" });
    for (auto name : names) {
        std::cout << name << " ";
    }
    std::cout << std::endl;
    // assign 也接受一个整型值和一个元素值
    std::list<std::string> slist1(1);       // 1个元素，为空string
    slist1.assign(10, "Hiya!");
    for (auto s : slist1) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    // swap 交换 两个 相同类型容器 的 内容
    std::vector<std::string> svec1(10,"hello");
    std::vector<std::string> svec2(24, "hi");
    std::vector<std::string>::iterator iter1 = svec1.begin() + 3, iter2 = svec2.begin() + 4;    // 迭代器
    std::string& st1 = svec1[5], & st2 = svec2[7], * sp1 = &svec1[8], * sp2 = &svec2[12];       // 引用和指针
    swap(svec1, svec2);
    // 迭代器、引用和指针仍然指向原来的那些元素
    std::cout << *iter1 << " " << *iter2 << "\n"
        << st1 << " " << st2 << "\n"
        << *sp1 << " " << *sp2 << std::endl;

    // 但针对array的swap操作会真正交换它们的元素
    std::array<int, 5> iarr1{ 6, 6, 6, 6, 6 };
    std::array<int, 5> iarr2{ 8, 8, 8, 8, 8 };
    std::array<int, 5>::iterator it1 = iarr1.begin() + 2, it2 = iarr2.begin() + 3;     // 迭代器
    int& i1 = iarr1[1], & i2 = iarr2[2], * ip1 = &iarr1[3], * ip2 = &iarr2[4];       // 引用和指针
    swap(iarr1, iarr2);
    std::cout << *it1 << " " << *it2 << "\n"
        << i1 << " " << i2 << "\n"
        << *ip1 << " " << *ip2 << std::endl;

    return 0;
}

