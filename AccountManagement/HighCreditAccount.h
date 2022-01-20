#define _CRT_SECURE_NO_WARNINGS
#ifndef _HIGHACCOUNT_H
#define _HIGHACCOUNT_H
#include "NormalAccount.h"
#include <cstring>
#include <iostream>
using namespace std;
class HighCreditAccount : public NormalAccount {
	char special; //A,B,C 등급 대소문자 생각

public:
	HighCreditAccount(int accountNo, char* name, int interRate, char special, int balance = 0);
	virtual ~HighCreditAccount();
	virtual int GetSpecial(void) const;
	virtual int bonusInterRate(int n);
	virtual int firstRate(int n);
	virtual void deposit(int amount); // 입금
};
inline HighCreditAccount::HighCreditAccount(int accountNo, char* name, int interRate, char special, int balance)
	:NormalAccount(accountNo, name,interRate) {
	this->special = special;
	deposit(balance);
}
inline HighCreditAccount::~HighCreditAccount() {
	cout << "NormalAccount 객체 소멸" << endl;
}
inline int HighCreditAccount::GetSpecial() const {
	if (special == 'a' || special == 'A') { // 단순 더하기
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
inline int HighCreditAccount::firstRate(int n) { // 이자 지급시 check 함수 호출
	if (special == 'a' || special == 'A') { // 단순 더하기
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
inline int HighCreditAccount::bonusInterRate(int n) { // 이자 지급시 check 함수 호출
	if (special == 'a' || special == 'A') { // 단순 더하기
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
	if (amount < 0) { // 입금액이 음수일때 MalformedData 예외처리 
		throw e;
	}
	else {
		if (count == 0) {
			// 입금액에 대해서만 이율을 적용한다
			balance = balance + amount; 
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