#define _CRT_SECURE_NO_WARNINGS
#ifndef _NORMALACCOUNT_H
#define _NORMALACCOUNT_H
#include "Account.h"
#include <cstring>
#include <iostream>
using namespace std;
class NormalAccount : public Account {
protected:
	int interRate;
public:
	NormalAccount(int accountNo, char* name, int interRate , int balance = 0);
	virtual ~NormalAccount();
	virtual int GetInterRate(void) const { return interRate; }
	virtual int bonusInterRate(int n);
	virtual int firstRate(int n);
	virtual void deposit(int amount); // �Ա�
};

inline NormalAccount::NormalAccount(int accountNo, char* name, int interRate, int balance) 
	:Account(accountNo, name, balance){
	this->interRate = interRate;
}
inline NormalAccount::~NormalAccount() {
	cout << "NormalAccount ��ü �Ҹ�" << endl;
}
inline int NormalAccount::bonusInterRate(int n) {

	n = n + (int)(n * interRate * 0.01);
	return n;
}
inline int NormalAccount::firstRate(int n) {

	n = (int)(n * interRate * 0.01);
	return n;
}
inline void NormalAccount::deposit(int amount) {
	int count = 0;
	MalformedData e;
	if (amount < 0) { // �Աݾ��� �����϶� MalformedData ����ó�� 
		throw e;
	}
	else {
		if (count == 0) {
			// �Աݾ׿� ���ؼ��� ������ �����Ѵ�
			balance = balance + amount; // 11000
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
