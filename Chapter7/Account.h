#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account
{
public:
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }         // ��̬��Ա����
	static void rate(double);                             // ��̬��Ա�������趨�µ�����
private:
	std::string owner;
	double amount;
	static double interestRate;      // ��̬��Ա           // ����             // ���� �����ڲ� ��ʼ�� ��̬��Ա(����ֵ�������ͳ���)
	static constexpr int period = 30;      // ����ֵ�������͵� ��̬��Ա ���������� ��ʼ��
	double daily_tbl[period];
	static double initRate();        // ��̬��Ա����       // ��ʼ������

	static Account mem1;     // ��̬��Ա�����ǲ���ȫ����
	Account* mem2;           // ָ���Ա�����ǲ���ȫ����
	//Account mem3;        // �������ݳ�Ա��������ȫ����
};

#endif // !ACCOUNT_H
