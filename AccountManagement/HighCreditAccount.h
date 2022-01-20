#define _CRT_SECURE_NO_WARNINGS
#ifndef _HIGHACCOUNT_H
#define _HIGHACCOUNT_H
#include "NormalAccount.h"
#include <cstring>
#include <iostream>
using namespace std;
class HighCreditAccount : public NormalAccount {
	char special; //A,B,C ��� ��ҹ��� ����

public:
	HighCreditAccount(int accountNo, char* name, int interRate, char special, int balance = 0);
	virtual ~HighCreditAccount();
	virtual int GetSpecial(void) const;
	virtual int bonusInterRate(int n);
	virtual int firstRate(int n);
	virtual void deposit(int amount); // �Ա�
};
inline HighCreditAccount::HighCreditAccount(int accountNo, char* name, int interRate, char special, int balance)
	:NormalAccount(accountNo, name,interRate) {
	this->special = special;
	deposit(balance);
}
inline HighCreditAccount::~HighCreditAccount() {
	cout << "NormalAccount ��ü �Ҹ�" << endl;
}
inline int HighCreditAccount::GetSpecial() const {
	if (special == 'a' || special == 'A') { // �ܼ� ���ϱ�
		return 7;
	}
	else if (special == 'b' || special == 'B') {
		return 4;
	}
	else if (special == 'c' || special == 'C') {
		return 2;
	}
	else {
		return 0;
	}
}
inline int HighCreditAccount::firstRate(int n) { // ���� ���޽� check �Լ� ȣ��
	if (special == 'a' || special == 'A') { // �ܼ� ���ϱ�
		n = (int)(n * (interRate + 7) * 0.01);
	}
	else if (special == 'b' || special == 'B') {
		n = (int)(n * (interRate + 4) * 0.01);
	}
	else if (special == 'c' || special == 'C') {
		n = (int)(n * (interRate + 2) * 0.01);
	}
	else {
		n = (int)(n * (interRate) * 0.01);
	}
	return n;
}
inline int HighCreditAccount::bonusInterRate(int n) { // ���� ���޽� check �Լ� ȣ��
	if (special == 'a' || special == 'A') { // �ܼ� ���ϱ�
		n = n + (int)(n * (interRate + 7) * 0.01);
	}
	else if (special == 'b' || special == 'B') {
		n = n + (int)(n * (interRate + 4) * 0.01);
	}
	else if (special == 'c' || special == 'C') {
		n = n + (int)(n * (interRate + 2) * 0.01);
	}
	else {
		n = n + (int)(n * (interRate) * 0.01);
	}
	return n;
}
inline void HighCreditAccount::deposit(int amount) {
	int count = 0;
	MalformedData e;
	if (amount < 0) { // �Աݾ��� �����϶� MalformedData ����ó�� 
		throw e;
	}
	else {
		if (count == 0) {
			// �Աݾ׿� ���ؼ��� ������ �����Ѵ�
			balance = balance + amount; 
			balance = bonusInterRate(balance);
			balance = balance - firstRate(amount);
		}
		else {
			// ��ü �ܾ׿� ���ؼ� ������ �����Ѵ�
			balance = balance + amount;
			balance = bonusInterRate(balance);
		}
		count++;

	}
}

#endif