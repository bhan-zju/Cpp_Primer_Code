// prog3_6.cpp : 多维数组：实质上是数组的数组
//

#include <iostream>

int main()
{
    int ia1[3][4];             // 大小为3的数组，每个元素是含有4个整数的数组
    // 初始化
    int arr[10][20][30] = { 0 };   // 所有元素初始化为0
    int ia2[3][4] = {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };                            // 内层花括号非必须
    int ia3[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };      // ia3 和 ia2 是相等的
    int ia4[3][4] = { {0},{4},{8} };      // 显式地初始化每行的首元素，未列出的元素执行默认初始化
    int ia5[3][4] = { 0,3,6,9 };          // 只初始化了第一行的元素

    // 下标引用
    ia2[2][3] = arr[0][0][0];      // 对ia2中的元素赋值
    int (&row)[4] = ia2[1];        // row是一个含有4个整数的数组的引用
  
    // for 循环
    constexpr size_t rowCnt = 3, colCnt = 4;
    int ia6[rowCnt][colCnt];     //12 个未初始化的元素
    for (size_t i = 0; i != rowCnt; ++i) {
        for (size_t j = 0; j != colCnt; ++j) {
            ia6[i][j] = i * colCnt + j;
            std::cout << ia6[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // 范围for循环
    int ia7[3][4] = { 0 };         // 所有元素初始化为 0
    size_t cnt = 0;
    for(int (&row1)[4] : ia7)            // 或 auto &row1 : ia7
        for (int &col1 : row1) {         // 或 auto &col1 : row1          // 要改变元素的值，必须使用引用类型
            col1 = cnt;
            ++cnt;
        }
    // 显示结果
    for (auto &row1 : ia7) {
        for (auto col1 : row1)           // 任何情况下，除了内层循环外，其他所有循环的控制变量都应该是引用类型
            std::cout << col1 << " ";
        std::cout << std::endl;
    }

    // 数组的指针
    int (*p)[4] = ia7;             // (*p)[]：数组的指针类型，指向ia7的首元素，是一个4维数组
    p = &ia7[2];             // p 指向ia7的第3个元素，也是一个4维数组

    int ia8[3][4] = { 0 };
    for (int(*p)[4] = ia8; p != ia8 + 3; ++p) {                // 或 auto p = ia8，p的类型是数组的指针，指向 ia8中的每一个 数组类型的元素
        for (int *q = *p; q != *p + 4; ++q)                // 或 auto q = *p，q是整数的指针，指向 p所指向的数组 的 每一个整型元素
            std::cout << *q << " ";              // 输出q所指向的每一个元素
        std::cout << std::endl;
    }

    // std::begin 和 std::end
    for (int(*p)[4] = std::begin(ia7); p != std::end(ia7); ++p) {          // 或 auto p = std::begin(ia7)
        for (int* q = std::begin(*p); q != std::end(*p); ++q)              // 或 atuo q = std::begin(*p)
            std::cout << *q << " ";
        std::cout << std::endl;
    }

    return 0;
}

// 