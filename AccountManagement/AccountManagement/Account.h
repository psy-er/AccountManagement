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
	int accountNo; // ���¹�ȣ
	char* name;  // ������ �̸�
	int balance; // �� �ܾ�

public:
	Account(int accountNo, char* name, int balance = 0);
	Account(const Account&);
	virtual ~Account(void); 

	virtual int GetAccountNo(void) const { return accountNo; }
	virtual int GetBalance(void) const { return balance; }
	virtual char* GetName(void) const { return name; }

	virtual void deposit(int amount) = 0; // �Ա�
	virtual int withdraw(int amount); // ���
	virtual void check(void) const; // �ܾ���ȸ

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
	cout << "Account ��ü �Ҹ�" << endl;
	delete[] name;
}

inline int Account::withdraw(int amount) { // ���
	MalformedData e1;
	BalanceOutOfBoundsException e2;

	if (amount < 0) { // �Աݾ��� �����϶� MalformedData ����ó�� 
		throw e1;
	}

	if (amount <= balance) { // �ܾ��� ���ڸ��� BalanceOutOfBoundsException ����
		balance = balance - amount;
		cout << amount << "�� �����Ͽ����ϴ�" << endl;
		return amount;
	}
	else {
		throw e2;
		return 0;
	}
}
inline void Account::check(void) const { // �ܾ���ȸ


	cout << "���¹�ȣ : " << accountNo << endl;
	cout << "�̸� : " << name << endl;
	cout << "�ܾ� : " << balance << endl;
	//cout << "�ܾ�: " << balance << endl;
}

inline bool Account::operator==(const Account& a) const {
	if (this->accountNo == a.accountNo && (strcmp(this->name, a.name) == 0) &&
		this->balance == a.balance) {
		return true;
	}
	else
		return false;
}
inline Account& Account::operator=(const Account& a) { // ���Կ����� �����ε�
	this->accountNo = a.accountNo;
	this->balance = a.balance;

	delete[] this->name;
	this->name = new char[strlen(a.name) + 1];
	strcpy(this->name, a.name);
	return *this;
}



#endif //_ACCOUNT_H