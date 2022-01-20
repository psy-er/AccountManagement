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
	virtual void deposit(int amount); // 입금
};

inline NormalAccount::NormalAccount(int accountNo, char* name, int interRate, int balance) 
	:Account(accountNo, name, balance){
	this->interRate = interRate;
}
inline NormalAccount::~NormalAccount() {
	cout << "NormalAccount 객체 소멸" << endl;
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
	if (amount < 0) { // 입금액이 음수일때 MalformedData 예외처리 
		throw e;
	}
	else {
		if (count == 0) {
			// 입금액에 대해서만 이율을 적용한다
			balance = balance + amount; // 11000
			balance = bonusInterRate(balance);
			balance = balance - firstRate(amount);

		}
		else {
			// 전체 잔액에 대해서 이율을 적용한다
			balance = balance + amount;
			balance = bonusInterRate(balance);

		}
		count++;
	}
}
#endif
