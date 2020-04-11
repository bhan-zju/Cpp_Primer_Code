// prog7_4_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

typedef double Money;
std::string bal;
class Account {
public:
    Money balance() { return bal; }      // 返回的是类内的Money类型的bal
private:
    //typedef double Money;          // 错误：类型名字不能重新定义
    Money bal;
};

int height;
class Screen {
public:
    typedef std::string::size_type pos;
    void dummy_fcn(pos height) {
        cursor = width * height;     // 这里的height是该函数的输入参数，覆盖掉了类内的height
    }
    void dummy_fcn2(pos height) {
        cursor = width * this->height;        // 如果想用到类内的height
        // 或
        cursor = width * Screen::height;
    }
    void dummy_fcn3(pos height) {
        cursor = width * ::height;            // 如果想用到类外层作用域中的height
    }
    void setHeight(pos);

private:
    pos cursor;
    pos height = 0, width = 0;
};
Screen::pos verify(Screen::pos);       // 该函数位于 Screen类定义 之后，类内setHeight函数定义 之前，可以被 setHeight函数 调用
void Screen::setHeight(pos var) {
    // var: 参数
    // height: 类的成员
    // verify: 全局函数
    height = verify(var);
}


int main()
{
    std::cout << "Hello World!\n";
}

//