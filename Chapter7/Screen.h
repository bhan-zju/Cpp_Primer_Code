#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>

class Screen {
	// 友元类Window_mgr可以访问Screen的private部分
	friend class Window_mgr;
	// 也可以单独 将Window_mgr类内的某个成员函数 定义成友元函数，例如↓
	//friend void Window_mgr::clear(ScreenIndex);         // 但是要首先声明了Window_mgr::clear函数在前（但是不能定义），要将Window_mgr类也定义在该头文件下，且要在Screen类之前

public:
	typedef std::string::size_type pos;          // 用于定义类型的成员必须先定义后使用，通常出现在类开始的地方

	Screen() = default;         // 构造函数
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht* wd, ' ') { }      // exer7_24 构造函数
	Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht*wd, c) { }    // 构造函数，其中contents被初始化成 ht*wd 个 字符c 构成的字符串；cursor被其类内初始值初始化为0
	
	char get() const                           // 读取光标处的字符
		{ return contents[cursor]; }           // 隐式内联 (定义在类内部的成员函数是自动inline的，注意是定义，不是声明)
	inline char get(pos ht, pos wd) const;     // 显式内联    // get函数重载
	Screen& move(pos r, pos c);                // 可以在之后被设为内联
	
	void some_member() const;                  // 记录成员函数被调用的次数

	Screen& set(char);                  // 设定当前光标所在位置处的新值
	Screen& set(pos, pos, char);        // 设置指定位置的新值
	
	Screen& display(std::ostream& os)           // 用于打印 非常量Screen对象，返回类型为 Screen &
	{
		do_display(os); return *this;
	}
	const Screen& display(std::ostream& os) const         // 用于打印 常量Screen对象，返回类型为 const Screen &
	{
		do_display(os); return *this;
	}
	
private:
	pos cursor = 0;                 // 光标位置
	pos height = 0, width = 0;      // 屏幕的高和宽
	std::string contents;           // 保存Screen内容
	// 可变数据成员 mutable
	mutable size_t access_ctr;      // 保存一个计数值，用于记录成员函数被调用的次数

private:
	void do_display(std::ostream& os) const
	{ os << contents; }
};




// 将光标移动到第r行第c列
inline Screen& Screen::move(pos r, pos c)      // 可以在函数的定义处指定inline(最好这样子说明inline，更容易理解)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}

// 读取第r行第c列的字符
char Screen::get(pos r, pos c) const          // 在类的内部已经声明成了inline
{
	pos row = r * width;
	return contents[row + c];
}

// 保存一个计数值，用于记录成员函数被调用的次数
void Screen::some_member() const
{
	++access_ctr;      //
}

// 设定当前光标所在位置处的新值
inline Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline Screen& Screen::set(pos r, pos col, char ch)
{
	contents[r * width + col] = ch;
	return *this;
}

#endif // !SCREEN_H
