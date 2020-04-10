#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>

class Screen {
	// ��Ԫ��Window_mgr���Է���Screen��private����
	friend class Window_mgr;
	// Ҳ���Ե��� ��Window_mgr���ڵ�ĳ����Ա���� �������Ԫ�����������
	//friend void Window_mgr::clear(ScreenIndex);         // ����Ҫ����������Window_mgr::clear������ǰ�����ǲ��ܶ��壩��Ҫ��Window_mgr��Ҳ�����ڸ�ͷ�ļ��£���Ҫ��Screen��֮ǰ

public:
	typedef std::string::size_type pos;          // ���ڶ������͵ĳ�Ա�����ȶ����ʹ�ã�ͨ���������࿪ʼ�ĵط�

	Screen() = default;         // ���캯��
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht* wd, ' ') { }      // exer7_24 ���캯��
	Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht*wd, c) { }    // ���캯��������contents����ʼ���� ht*wd �� �ַ�c ���ɵ��ַ�����cursor�������ڳ�ʼֵ��ʼ��Ϊ0
	
	char get() const                           // ��ȡ��괦���ַ�
		{ return contents[cursor]; }           // ��ʽ���� (���������ڲ��ĳ�Ա�������Զ�inline�ģ�ע���Ƕ��壬��������)
	inline char get(pos ht, pos wd) const;     // ��ʽ����    // get��������
	Screen& move(pos r, pos c);                // ������֮����Ϊ����
	
	void some_member() const;                  // ��¼��Ա���������õĴ���

	Screen& set(char);                  // �趨��ǰ�������λ�ô�����ֵ
	Screen& set(pos, pos, char);        // ����ָ��λ�õ���ֵ
	
	Screen& display(std::ostream& os)           // ���ڴ�ӡ �ǳ���Screen���󣬷�������Ϊ Screen &
	{
		do_display(os); return *this;
	}
	const Screen& display(std::ostream& os) const         // ���ڴ�ӡ ����Screen���󣬷�������Ϊ const Screen &
	{
		do_display(os); return *this;
	}
	
private:
	pos cursor = 0;                 // ���λ��
	pos height = 0, width = 0;      // ��Ļ�ĸߺͿ�
	std::string contents;           // ����Screen����
	// �ɱ����ݳ�Ա mutable
	mutable size_t access_ctr;      // ����һ������ֵ�����ڼ�¼��Ա���������õĴ���

private:
	void do_display(std::ostream& os) const
	{ os << contents; }
};




// ������ƶ�����r�е�c��
inline Screen& Screen::move(pos r, pos c)      // �����ں����Ķ��崦ָ��inline(���������˵��inline�����������)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}

// ��ȡ��r�е�c�е��ַ�
char Screen::get(pos r, pos c) const          // ������ڲ��Ѿ���������inline
{
	pos row = r * width;
	return contents[row + c];
}

// ����һ������ֵ�����ڼ�¼��Ա���������õĴ���
void Screen::some_member() const
{
	++access_ctr;      //
}

// �趨��ǰ�������λ�ô�����ֵ
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
