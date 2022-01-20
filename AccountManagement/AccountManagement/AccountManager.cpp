#define _CRT_SECURE_NO_WARNINGS
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "AccountManager.h" 
#include "BalanceOutOfBoundsException.h"
#include "MalformedData.h"
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void AccountManager::WriteFile(Account* list[], int size) {
	ofstream fout;
	fout.open("myAccount.txt");

	if (fout.fail()) {
		cerr << "파일을 열 수 없습니다." << endl;
		exit(-1);
	}
	for (int i = 0; i < size; i++) {
		fout << list[i]->GetName() << "";
		fout << list[i]->GetAccountNo() << "";
		fout << list[i]->GetBalance() << endl;
	}
	fout.close();
}
void AccountManager::ReadFile(Account* list[], int size) {
	ifstream fin;
	fin.open("myAccount.txt");

	if (fin.fail()) {
		cerr << "파일을 열 수 없습니다." << endl;
		exit(-2);
	}

	int type, accountNo, interRate, balance;
	char* name = new char[100];
	char special;
	cout << "[파일입출력]" << endl;
	cout << "1. 보통예금 계좌" << endl;
	cout << "2. 신용신뢰 계좌" << endl;
	cout << "> 입출력할 계좌 종류는? ";
	cin >> type;

	if (type == 1) {
		int cnt = 0;
		do {
			fin >> name >> accountNo >> balance>> interRate;
			if (fin.eof()) break;
			list[cnt++]= new NormalAccount(accountNo, name, interRate, balance);

		} while (cnt < size);
	}
	if (type == 2) {
		int cnt = 0;
		do {
			fin >> name >> accountNo >> balance >> interRate >> special;
			if (fin.eof()) break;
			list[cnt++] = new HighCreditAccount(accountNo, name, interRate, special, balance);

		} while (cnt < size);
	}


	fin.close();
}

void AccountManager::CreateAccount(void) {
	int type, accountNo, interRate, balance;
	char* name = new char[100]; 
	char special;
	cout << "[계좌개설]" << endl;
	cout << "1. 보통예금 계좌" << endl;
	cout << "2. 신용신뢰 계좌" << endl;
	cout << "> 개설하고자 하는 계좌 종류는? ";
	cin >> type;

	if (type == 1) {// 보통예금 계좌 개설
		cout << "계좌번호: ";
		cin >> accountNo ;
		cout << "이름: ";
		cin >> name;
		cout << "입금액: ";
		cin >> balance;
		cout << "기본이율: ";
		cin >> interRate;
		accounts[size] = new NormalAccount(accountNo, name, interRate, balance);
	}
	else if (type == 2) {// 신용신뢰 계좌 개설
		cout << "계좌번호: ";
		cin >> accountNo;
		cout << "이름: ";
		cin >> name;
		cout << "입금액: ";
		cin >> balance;
		cout << "기본이율: ";
		cin >> interRate;
		cout << "신용등급: ";
		cin >> special;
		accounts[size] = new HighCreditAccount(accountNo, name, interRate, special, balance);
	}
	cout << "\n[계좌개설 완료]\n" << endl;
	size++;
	WriteFile(accounts, size);
}
void AccountManager::Deposit(void) {// 입금
	int accountNo, amount;
	bool b = false;
	cout << "[입금]" << endl;
	cout << "계좌번호: ";
	cin >> accountNo;
	for (int i = 0; i < size; i++) {
		if ((accounts[i]->GetAccountNo()) == accountNo) {
			b = true;
			try {
				cout << "입금액: ";
				cin >> amount;
				accounts[i]->deposit(amount);
			}
			catch (MalformedData& e) {
				cout << e.getMessage() << endl;
			}
			cout << "\n[입금 완료]\n" << endl;
		}
	}
	if (b == false) {
		cout << "일치하는 계좌가 존재하지 않습니다!" << endl;
	}
}
void AccountManager::Withdraw(void) {//출금
	int accountNo, amount;
	bool b = false;
	cout << "[출금]" << endl;
	cout << "계좌번호 : ";
	cin >> accountNo;
	for (int i = 0; i < size; i++) {
		if ((accounts[i]->GetAccountNo()) == accountNo) {
			b = true;
			try {
				cout << "출금액 : ";
				cin >> amount;
				accounts[i]->withdraw(amount);
			}
			catch (MalformedData& e) {
				cout << e.getMessage() << endl;
			}
			catch (BalanceOutOfBoundsException& e) {
				cout << e.getMessage() << endl;
			}
		}
	}

	if (b == false) {
		cout << "일치하는 계좌가 존재하지 않습니다!\n" << endl;
	}
	else {
		cout << "\n[출금 완료]\n\n" << endl;
	}
}
void AccountManager::DisplayAll(void) const {// 전체 고객 잔액조회
	cout << "[조회]\n\n" << endl;
	//int effSize = ReadFile(list, size);

	for (int i = 0; i < size; i++) {

		accounts[i]->check();

		NormalAccount* n;
		n = dynamic_cast<NormalAccount*>(accounts[i]);
		if (n != NULL) {
			cout << "기본 이율 : " << n->GetInterRate() << "%" << endl;
		}

		HighCreditAccount* h;
		h = dynamic_cast<HighCreditAccount*>(accounts[i]);
		if (h != NULL) {
			cout << "특별 이율 : " << h->GetSpecial() << "%" << endl;
		}
		cout << "=============================" << endl;
	}
	cout << "[조회 완료]\n" << endl;
}
void AccountManager::DisplayOne(void) const {// 특정 계좌 잔액조회
	int accountNo;
	cout << "\n[특정 계좌 잔액조회]"<< endl;
	cout << ">조회할 계좌의 계좌번호를 입력하시오 : ";
	cin >> accountNo;
	cout << "" << endl;

	for (int i = 0; i < size; i++) {
		if ((accounts[i]->GetAccountNo()) == accountNo) {
			accounts[i]->check();

			NormalAccount* n;
			n = dynamic_cast<NormalAccount*>(accounts[i]);
			if (n != NULL) {
				cout << "기본 이율 : " << n->GetInterRate() << "%" << endl;
			}

			HighCreditAccount* h;
			h = dynamic_cast<HighCreditAccount*>(accounts[i]);
			if (h != NULL) {
				cout << "특별 이율 : " << h->GetSpecial() << "%" << endl;
			}
			cout << "=============================" << endl;
		}
	}
	cout << "[조회 완료]\n" << endl;
}
void AccountManager::CloseAccount(void) {// 계좌 해지
	int accountNo;
	char* name = new char[100];
	cout << "[계좌해지]" << endl;
	cout << "계좌번호 : ";
	cin >> accountNo;
	cout << "소유주 : ";
	cin >> name; 

	for (int i = 0; i < size; i++) {
		if ((accounts[i]->GetAccountNo()) == accountNo && (strcmp(accounts[i]->GetName(),name) == 0)) {
			accounts[i] = accounts[i + 1];
		}
		size = size - 1;
	}
	cout << "\n[계좌해지 완료]\n" << endl;
}
int AccountManager::Search(int accountNo) const{
	for (int i = 0; i < size; i++)
	{
		if (accountNo == accounts[i]->GetAccountNo())
			return i;
	}
	return 0;
}