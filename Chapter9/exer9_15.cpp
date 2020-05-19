// exer9_15.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <list>

bool theSame(std::vector<int> v1, std::vector<int> v2)
{
    return v1 == v2;
}

bool theSame(std::list<int> l, std::vector<int> v)
{
    std::vector<int> vl;
    vl.assign(l.begin(), l.end());
    return vl == v;
}

int main()
{
    std::vector<int> v1, v2;
    std::cout << theSame(v1, v2) << std::endl;
    v1 = { 8 };
    std::cout << theSame(v1, v2) << std::endl;
    v1 = { 8,9,7 };
    v2 = { 8,9,7 };
    std::cout << theSame(v1, v2) << std::endl;
    v2 = { 8,9,6 };
    std::cout << theSame(v1, v2) << std::endl;

    std::list<int> l;
    std::vector<int> v;
    std::cout << theSame(l, v) << std::endl;
    l = { 8 };
    std::cout << theSame(l, v) << std::endl;
    l = { 8,9,7 };
    v = { 8,9,7 };
    std::cout << theSame(l, v) << std::endl;
    v = { 8,9,6 };
    std::cout << theSame(l, v) << std::endl;

    return 0;
}

