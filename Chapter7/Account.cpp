// ����Account���ڵĳ�Ա����

#ifndef ACCOUNT_CPP
#define ACCOUNT_CPP

#include "Account.h"

// ������ⲿ���� ��̬��Ա���� ʱ�������ظ� static �ؼ���
void Account::rate(double newRate)
{
	interestRate = newRate;
}

// ������ ����ⲿ ��ʼ�� ��̬��Ա
double Account::interestRate = initRate();

constexpr int Account::period;     // �����Ѿ���ʼ����period������ֻ��Ҫ���壬����Ҫ����ʼֵ

#endif // !ACCOUNT_CPP
