#define _CRT_SECURE_NO_WARNINGS
#ifndef _ACCOUNTMANAGER_H
#define _ACCOUNTMANAGER_H
#include "Account.h"
#include <iostream>
#include <fstream>
using namespace std;

class AccountManager {
	static const int MAX_ACCOUNTS = 100;

	Account* accounts[MAX_ACCOUNTS]; // ���� ������ ���� �Ҵ�
	int size; // �迭 ��ȿ ũ��(�Ҵ�)
	int Search(int accountNo) const;
public:
	AccountManager(void);
	~AccountManager(void); // ���� �Ҵ� �޸� ����

	void WriteFile(Account* list[], int size);
	void ReadFile(Account* list[], int max);

	void CreateAccount(void); // ���� ����
	void Deposit(void); // �Ա�
	void Withdraw(void); //���
	void DisplayAll(void) const; // ��ü �� �ܾ���ȸ
	void DisplayOne(void) const; // Ư�� ���� �ܾ���ȸ
	void CloseAccount(void); // ���� ����

	int GetSize(void) const { return size; };
};
inline AccountManager::AccountManager(void) {
	size = 0;
}
inline AccountManager::~AccountManager() {
	cout << "AccountManager ��ü �Ҹ�" << endl;
	for (int i = 0; i < size; i++) {
		delete accounts[i];
	}
}

#endif _ACCOUNTMANAGER_H
