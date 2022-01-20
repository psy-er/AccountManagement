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
		cerr << "������ �� �� �����ϴ�." << endl;
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
		cerr << "������ �� �� �����ϴ�." << endl;
		exit(-2);
	}

	int type, accountNo, interRate, balance;
	char* name = new char[100];
	char special;
	cout << "[���������]" << endl;
	cout << "1. ���뿹�� ����" << endl;
	cout << "2. �ſ�ŷ� ����" << endl;
	cout << "> ������� ���� ������? ";
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
	cout << "[���°���]" << endl;
	cout << "1. ���뿹�� ����" << endl;
	cout << "2. �ſ�ŷ� ����" << endl;
	cout << "> �����ϰ��� �ϴ� ���� ������? ";
	cin >> type;

	if (type == 1) {// ���뿹�� ���� ����
		cout << "���¹�ȣ: ";
		cin >> accountNo ;
		cout << "�̸�: ";
		cin >> name;
		cout << "�Աݾ�: ";
		cin >> balance;
		cout << "�⺻����: ";
		cin >> interRate;
		accounts[size] = new NormalAccount(accountNo, name, interRate, balance);
	}
	else if (type == 2) {// �ſ�ŷ� ���� ����
		cout << "���¹�ȣ: ";
		cin >> accountNo;
		cout << "�̸�: ";
		cin >> name;
		cout << "�Աݾ�: ";
		cin >> balance;
		cout << "�⺻����: ";
		cin >> interRate;
		cout << "�ſ���: ";
		cin >> special;
		accounts[size] = new HighCreditAccount(accountNo, name, interRate, special, balance);
	}
	cout << "\n[���°��� �Ϸ�]\n" << endl;
	size++;
	WriteFile(accounts, size);
}
void AccountManager::Deposit(void) {// �Ա�
	int accountNo, amount;
	bool b = false;
	cout << "[�Ա�]" << endl;
	cout << "���¹�ȣ: ";
	cin >> accountNo;
	for (int i = 0; i < size; i++) {
		if ((accounts[i]->GetAccountNo()) == accountNo) {
			b = true;
			try {
				cout << "�Աݾ�: ";
				cin >> amount;
				accounts[i]->deposit(amount);
			}
			catch (MalformedData& e) {
				cout << e.getMessage() << endl;
			}
			cout << "\n[�Ա� �Ϸ�]\n" << endl;
		}
	}
	if (b == false) {
		cout << "��ġ�ϴ� ���°� �������� �ʽ��ϴ�!" << endl;
	}
}
void AccountManager::Withdraw(void) {//���
	int accountNo, amount;
	bool b = false;
	cout << "[���]" << endl;
	cout << "���¹�ȣ : ";
	cin >> accountNo;
	for (int i = 0; i < size; i++) {
		if ((accounts[i]->GetAccountNo()) == accountNo) {
			b = true;
			try {
				cout << "��ݾ� : ";
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
		cout << "��ġ�ϴ� ���°� �������� �ʽ��ϴ�!\n" << endl;
	}
	else {
		cout << "\n[��� �Ϸ�]\n\n" << endl;
	}
}
void AccountManager::DisplayAll(void) const {// ��ü �� �ܾ���ȸ
	cout << "[��ȸ]\n\n" << endl;
	//int effSize = ReadFile(list, size);

	for (int i = 0; i < size; i++) {

		accounts[i]->check();

		NormalAccount* n;
		n = dynamic_cast<NormalAccount*>(accounts[i]);
		if (n != NULL) {
			cout << "�⺻ ���� : " << n->GetInterRate() << "%" << endl;
		}

		HighCreditAccount* h;
		h = dynamic_cast<HighCreditAccount*>(accounts[i]);
		if (h != NULL) {
			cout << "Ư�� ���� : " << h->GetSpecial() << "%" << endl;
		}
		cout << "=============================" << endl;
	}
	cout << "[��ȸ �Ϸ�]\n" << endl;
}
void AccountManager::DisplayOne(void) const {// Ư�� ���� �ܾ���ȸ
	int accountNo;
	cout << "\n[Ư�� ���� �ܾ���ȸ]"<< endl;
	cout << ">��ȸ�� ������ ���¹�ȣ�� �Է��Ͻÿ� : ";
	cin >> accountNo;
	cout << "" << endl;

	for (int i = 0; i < size; i++) {
		if ((accounts[i]->GetAccountNo()) == accountNo) {
			accounts[i]->check();

			NormalAccount* n;
			n = dynamic_cast<NormalAccount*>(accounts[i]);
			if (n != NULL) {
				cout << "�⺻ ���� : " << n->GetInterRate() << "%" << endl;
			}

			HighCreditAccount* h;
			h = dynamic_cast<HighCreditAccount*>(accounts[i]);
			if (h != NULL) {
				cout << "Ư�� ���� : " << h->GetSpecial() << "%" << endl;
			}
			cout << "=============================" << endl;
		}
	}
	cout << "[��ȸ �Ϸ�]\n" << endl;
}
void AccountManager::CloseAccount(void) {// ���� ����
	int accountNo;
	char* name = new char[100];
	cout << "[��������]" << endl;
	cout << "���¹�ȣ : ";
	cin >> accountNo;
	cout << "������ : ";
	cin >> name; 

	for (int i = 0; i < size; i++) {
		if ((accounts[i]->GetAccountNo()) == accountNo && (strcmp(accounts[i]->GetName(),name) == 0)) {
			accounts[i] = accounts[i + 1];
		}
		size = size - 1;
	}
	cout << "\n[�������� �Ϸ�]\n" << endl;
}
int AccountManager::Search(int accountNo) const{
	for (int i = 0; i < size; i++)
	{
		if (accountNo == accounts[i]->GetAccountNo())
			return i;
	}
	return 0;
}