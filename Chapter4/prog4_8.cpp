// prog4_8.cpp : 位运算符
//

#include <iostream>

int main()
{
    unsigned int result;
    // 移位运算符：左移<<，右移>>
    unsigned char bits = 0233;            // 八进制233，二进制10011011
    std::cout << (int)bits << std::endl;
    result = bits >> 3;                             // bits提升成int类型（8位变成32位），再右移3位，左侧插入0，即00000000…00010011
    std::cout << result << std::endl;
    result = bits << 8;                         // 左移8位
    std::cout << result << std::endl;

    // 位求反运算符~
    unsigned bits2 = 0277;            // 八进制277，二进制10010111
    std::cout << (int)bits2 << std::endl;
    result = ~bits2;                        // 先提升为32位的int型，00000000…10010111，再逐位取反，即11111111…01101000
    std::cout << result << std::endl;

    // 与&，或|，异或^
    unsigned char b1 = 0145;                 //01100101
    unsigned char b2 = 0257;                 //10101111
    result = b1 & b2;                 // 位求与00100101
    std::cout << result << std::endl;
    result = b1 | b2;                 // 位求或11101111
    std::cout << result << std::endl;
    result = b1 ^ b2;               // 位求异或11001010
    std::cout << result << std::endl;

    // 使用位运算符
    unsigned long quiz1 = 0;      // quiz1至少拥有32位。 // 通过考试为1，不通过为0，30位同学都初始化为0
    unsigned long lUL = 1;      // 最后一位为1，其余都置为0
    // 将第27位同学的成绩置为1
    quiz1 |= lUL << 27;       // 位或运算，等价于 quiz1 = quiz1 | (lUL << 27);
    // 测验第27位同学的情况到底怎么样
    bool status = quiz1 & lUL << 27;
    std::cout << "The 27th bit is " << status << std::endl;
    // 突然发现第27位同学并没有通过考试，将其重新置为0
    quiz1 &= ~(lUL << 27);     // 等价于 quiz1 = quiz1 & ( ~(lUL << 27) );
    status = quiz1 & lUL << 27;
    std::cout << "The 27th bit is " << status << std::endl;

    // 移位运算符的优先级
    // 低于算术运算符
    std::cout << 42 + 10;
    std::cout << std::endl;
    // 高于关系运算符，赋值运算符，条件运算符
    std::cout << (10 < 42);        // 正确
    //std::cout << 10 < 42;        // 错误：试图比较 cout 和 42
    std::cout << std::endl;

    // exercise 4.25
    std::cout << ('q' << 6) << std::endl;

    return 0;

}

// 
