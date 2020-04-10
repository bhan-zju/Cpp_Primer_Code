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
	std::vector<Screen> screens{ Screen(24,80,' ') };     // Ĭ������£�����һ����׼�ߴ�Ŀհ�Screen����
};




// ��screens�еĵ�i��ScreenԪ������Ϊ�հ�
void Window_mgr::clear(ScreenIndex i)
{
	Screen& s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');    // Window_mgr �� Screen �� ��Ԫ�࣬��˿��Է��� Screen ���� �� private ���֣���contents,height,width��
}

// �򴰿����һ��Screen���󣬲��������ı��
Window_mgr::ScreenIndex             // �����ķ������ͳ���������֮ǰ����˱������Window_mgr::���ܱ�ʶ��
Window_mgr::addScreen(const Screen& s)
{
	screens.push_back(s);
	return screens.size() - 1;
}

#endif // !WINDOW_MGR_H

