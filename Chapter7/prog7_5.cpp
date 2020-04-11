// prog7_5.cpp : 构造函数初始值列表
//

#include <iostream>

class ConstRef {
public:
    ConstRef(int ii);    // 构造函数
private:
    int i;
    const int ci;
    int& ri;
};
// 错误：ci和ri必须被初始化,而不能被赋值
/*
ConstRef::ConstRef(int ii) {
    i = ii;
    ci = ii;      // 错误：不能给const赋值
    ri = i;       // 错误：ri没有被初始化
}
*/
// 正确的写法：显式地初始化 引用 和 const成员
ConstRef::ConstRef(int ii): i(ii), ci(ii), ri(i) { }

// 成员初始化的顺序：与它们在类定义中出现的顺序一致
class X {
    int i;
    int j;
public:
    // 构造函数
    //X(int val):j(val), i(j) { }       // i 比 j 先初始化，因此 i 将是未定义的
    X(int val) :j(val), i(val) { }      // 正确写法，或 X(int val):i(val), j(i) { }
};

int main()
{
    std::cout << "Hello World!\n";
}

// 