// prog6_2_4.cpp : 数组形参
//

#include <iostream>

// 为函数传递一个数组时，实际上传递的是指向数组的首元素指针
// 为了知道数组的确切尺寸，管理数组形参有三种常用的技术

// 1.要求数组本身包含一个结束标记，比如C风格字符串

void print(const char* cp)
{
    if (cp)                           // 如果cp不是空指针
        while (*cp)                   // 如果cp所指的字符不是空字符
            std::cout << *cp++;
    std::cout << std::endl;
}

// 2.传递指向数组 首元素 和 尾后元素 的指针
void print(const int* beg, const int* end)
{
    while (beg != end)
        std::cout << *beg++ << " ";      // 输出当前元素 并将指针向前移动一个位置
    std::cout << std::endl;
}

// 3.显式传递一个表示数组大小的形参
void print(const int ia[], size_t size)         // const int ia[] 等价于 const int *ia
{
    for (size_t i = 0; i != size; ++i)
        std::cout << ia[i] << " ";
    std::cout << std::endl;
}

// 形参也可以是数组的引用
void print(int(&arr)[10])           // 但是该函数只能作用于大小为10的数组   // (&arr)[10])括号不能去掉
{
    for (auto elem : arr)
        std::cout << elem << " ";
    std::cout << std::endl;
}

// 传递多维数组，二维数组首元素也是数组，因此 传递首元素的指针，本质上是传递了 数组的指针
void print(int(*matrix)[6], int rowSize)       // (*matrix)[6]指向6维数组的指针，括号不能省略
{
    for (int row = 0; row != rowSize; ++row) {
        for (auto i : matrix[row])
            std::cout << i << " ";
        std::cout << std::endl;
    }

}


int main()
{
    // C风格字符串：以空字符为结束的字符数组（数组本身含有结束标记）
    char ca[] = "A string example";
    print(ca);

    int j[5] = { 3,1,4,5,9 };
    print(std::begin(j), std::end(j));

    print(j, std::end(j) - std::begin(j));

    //print(j);       // 错误：j的大小不为10，不能传参
    int k[] = { 3,1,4,1,5,9,2,6,5,3 };
    print(k);         // 正确：k的大小为10

    int matrix[4][6] = { {3,1,4,1,5,9},{2,5,6,3,8,0},{8,9,7,1,3,4} };
    print(matrix, 4);

    return 0;
}

// 
