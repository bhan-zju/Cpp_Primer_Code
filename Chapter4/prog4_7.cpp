// prog4_7.cpp : 条件运算符 cond ? expr1 : expr2
//

#include <iostream>
#include <string>

int main()
{
    double grade = 60;
    std::string finalgrade = (grade < 60) ? "fail" : "pass";
    std::cout << finalgrade << std::endl;

    // 嵌套
    grade = 90;
    finalgrade = (grade >= 90) ? "high pass" : (grade < 60) ? "fail" : "pass";
    std::cout << finalgrade << std::endl;

    // 输出表达式中使用
    grade = 59;
    std::cout << ((grade < 60) ? "fail" : "pass");          // 外层括号必须加上，否则会产生意想不到的后果

    return 0;
}

//