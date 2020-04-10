#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include "Screen.h"
#include <vector>

class Window_mgr {
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);
	ScreenIndex addScreen(const Screen&);

private:
	std::vector<Screen> screens{ Screen(24,80,' ') };     // 默认情况下，包含一个标准尺寸的空白Screen对象
};




// 将screens中的第i个Screen元素重置为空白
void Window_mgr::clear(ScreenIndex i)
{
	Screen& s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');    // Window_mgr 是 Screen 的 友元类，因此可以访问 Screen 对象 的 private 部分（即contents,height,width）
}

// 向窗口添加一个Screen对象，并返回它的编号
Window_mgr::ScreenIndex             // 函数的返回类型出现在类名之前，因此必须加上Window_mgr::才能被识别
Window_mgr::addScreen(const Screen& s)
{
	screens.push_back(s);
	return screens.size() - 1;
}

#endif // !WINDOW_MGR_H

