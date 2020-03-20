// prog3_5_3.cpp : 指针和数组
//

#include <iostream>
#include <string>

int main()
{
    std::string nums[] = { "one","two","three" };
    std::string *p = &nums[0];           // p 指向 nums 的第一个元素
    // 在很多情况下，编译器会将 数组名 替换为一个 指向数组首元素的指针
    std::string *p2 = nums;              // 等价于 std::string *p2 = &nums[0];

    int ia[] = { 0,1,2,3,4,5,6,7,8,9 };
    auto ia2(ia);         // 即 auto ia2 = ia; 或int *ia2 = ia; ia2是指向数组首元素的指针。但不能写成 int ia2 = ia; 因为数组不能直接拷贝
    *ia2 = 42;
    ia2[3] = 20;
    std::cout << "sizeof(ia2)  " << sizeof(ia2) << std::endl;     // sizeof(ia2)=4,说明ia2只是个指针，而不是数组
    for (auto i : ia)
        std::cout << i << " ";
    std::cout << std::endl;

    decltype(ia) ia3 = { 2,3,4,5,6,7,8,9,0,1 };          // ia3 的类型为数组，且元素数量为10
    ia3[4] = 30;
    std::cout << "sizeof(ia3)  " << sizeof(ia3) << std::endl;      //sizeof(ia3)=40，说明ia3是数组，而不是指针

    // 数组的指针也是迭代器
    std::cout << "指针也是迭代器：" << std::endl;
    int arr[]= { 0,1,2,3,4,5,6,7,8,9 };
    int *p3 = arr;           // p3 指向arr的第一个元素
    ++p3;                    // p3 将指向arr的第二个元素
    std::cout << "*p -> " << *p3 << std::endl;
    int* e = &arr[10];       // e 指向arr尾元素的下一位置
    for (int* b = arr; b != e; ++b)
        std::cout << *b << " ";
    std::cout << std::endl;

    // begin 和 end
    std::cout << "begin 和 end：" << std::endl;
    int arr1[] = { 4,3,2,1,0,-1,-2,-3,-4 };
    int *beg = std::begin(arr1);             // beg 指向arr1的首元素
    int *last = std::end(arr1);              // last 指向arr1尾元素的下一个位置
    // 寻找第一个负值元素
    while (beg != last && *beg >= 0)
        ++beg;
    std::cout << *beg << std::endl;

    // 指针运算
    std::cout << "指针运算：" << std::endl;
    constexpr size_t sz = 5;
    int arr2[sz] = { 1,2,3,4,5 };
    // 加法
    int *ip = arr2;                  // ip指向 arr2 的第一个元素
    int *ip2 = ip + 3;               // ip2 指向 arr2 的第4个元素
    std::cout << "*ip2 -> arr2[3] = " << *ip2 << std::endl;
    int* ip3 = arr2 + sz;            // 使用警告：ip3 指向 arr2 尾元素的下一个位置，不要解引用
    // 相减
    auto n = std::end(arr2) - std::begin(arr2);
    std::cout << "n = " << n << std::endl;         // 将得到arr2的数组大小，n的类型为 ptrdiff_t
    // 比较
    int *b1 = arr2, *e1 = arr2 + sz;
    while (b1 < e1) {                           // 只有指向同一数组的指针才能比较
        std::cout << *b1 << " ";
        ++b1;
    }
    std::cout << std::endl;

    // 解引用和指针运算的交互
    std::cout << "解引用和指针运算的交互：" << std::endl;
    int ia4[] = { 1,3,4,7,11,18 };    // 含有6个元素的数组
    int last1 = *(ia4 + 4);           // int型变量last1初始化为11，也就是ia4[4]的值
    int last2 = *ia4 + 4;             // 先解引用，因此last2 = ia4[0] + 4 = 5
    std::cout << "last1 = " << last1 << "\tlast2 = " << last2 << std::endl;

    // 下标和指针
    std::cout << "下标和指针：" << std::endl;
    int ia5[] = { 0,2,4,6,8 };
    int *p5 = ia5;                 // p4 指向 ia5 的首元素
    int i5 = *(p5 + 2);            // 等价于 i5 = ia5[2]
    std::cout << "i5 = " << i5 << std::endl;
    p5 = &ia5[2];     // p5 指向索引为2的元素
    int j = p5[1];    // j 将等于ia5中索引为3的元素，即j = ia5[3] = 6
    int k = p5[-2];   // k 将等于ia5中索引为0的元素，即k = ia5[0] = 0
    std::cout << "j = " << j << "\nk = " << k << std::endl;

    return 0;
}

// 