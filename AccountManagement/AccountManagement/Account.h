#define _CRT_SECURE_NO_WARNINGS
#ifndef _ACCOUNT_H
#define _ACCOUNT_H
#include <cstring>
#include <iostream>
#include "BalanceOutOfBoundsException.h"
#include "MalformedData.h"
using namespace std;

class Account {
protected:
	int accountNo; // 계좌번호
	char* name;  // 소유자 이름
	int balance; // 현 잔액

public:
	Account(int accountNo, char* name, int balance = 0);
	Account(const Account&);
	virtual ~Account(void); 

	virtual int GetAccountNo(void) const { return accountNo; }
	virtual int GetBalance(void) const { return balance; }
	virtual char* GetName(void) const { return name; }

	virtual void deposit(int amount) = 0; // 입금
	virtual int withdraw(int amount); // 출금
	virtual void check(void) const; // 잔액조회

	bool operator==(const Account & a) const;
	Account& operator=(const Account& a);
};

inline Account::Account(int accountNo, char* name, int balance) {
	this->accountNo = accountNo;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->balance = balance;
}
inline Account::Account(const Account& a) {
	this->accountNo = a.accountNo;
	this->name = new char[strlen(a.name) + 1];
	strcpy(this->name, a.name);
	this->balance = a.balance;
}
inline Account::~Account() {
	cout << "Account 객체 소멸" << endl;
	delete[] name;
}

inline int Account::withdraw(int amount) { // 출금
	MalformedData e1;
	BalanceOutOfBoundsException e2;

	if (amount < 0) { // 입금액이 음수일때 MalformedData 예외처리 
		throw e1;
	}

	if (amount <= balance) { // 잔액이 모자를때 BalanceOutOfBoundsException 예외
		balance = balance - amount;
		cout << amount << "원 인출하였습니다" << endl;
		return amount;
	}
	else {
		throw e2;
		return 0;
	}
}
inline void Account::check(void) const { // 잔액조회


	cout << "계좌번호 : " << accountNo << endl;
	cout << "이름 : " << name << endl;
	cout << "잔액 : " << balance << endl;
	//cout << "잔액: " << balance << endl;
}

inline bool Account::operator==(const Account& a) const {
	if (this->accountNo == a.accountNo && (strcmp(this->name, a.name) == 0) &&
		this->balance == a.balance) {
		return true;
	}
	else
		return false;
}
inline Account& Account::operator=(const Account& a) { // 대입연산자 오버로딩
	this->accountNo = a.accountNo;
	this->balance = a.balance;

	delete[] this->name;
	this->name = new char[strlen(a.name) + 1];
	strcpy(this->name, a.name);
	return *this;
}



#endif //_ACCOUNT_H