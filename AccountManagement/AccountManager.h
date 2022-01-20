#define _CRT_SECURE_NO_WARNINGS
#ifndef _ACCOUNTMANAGER_H
#define _ACCOUNTMANAGER_H
#include "Account.h"
#include <iostream>
#include <fstream>
using namespace std;

class AccountManager {
	static const int MAX_ACCOUNTS = 100;

	Account* accounts[MAX_ACCOUNTS]; // 계좌 생성시 동적 할당
	int size; // 배열 유효 크기(할당)
	int Search(int accountNo) const;
public:
	AccountManager(void);
	~AccountManager(void); // 동적 할당 메모리 해제

	void WriteFile(Account* list[], int size);
	void ReadFile(Account* list[], int max);

	void CreateAccount(void); // 계좌 개설
	void Deposit(void); // 입금
	void Withdraw(void); //출금
	void DisplayAll(void) const; // 전체 고객 잔액조회
	void DisplayOne(void) const; // 특정 계좌 잔액조회
	void CloseAccount(void); // 계좌 해지

	int GetSize(void) const { return size; };
};
inline AccountManager::AccountManager(void) {
	size = 0;
}
inline AccountManager::~AccountManager() {
	cout << "AccountManager 객체 소멸" << endl;
	for (int i = 0; i < size; i++) {
		delete accounts[i];
	}
}

#endif _ACCOUNTMANAGER_H
