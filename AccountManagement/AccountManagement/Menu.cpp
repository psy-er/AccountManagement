#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include "Account.h"
#include <iostream>
using namespace std;

void Menu::ShowMenu() {
	cout << "���� ���� �ý���(1�ܰ�)" << endl;
	cout << "=======================" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. ��ü �������� ���" << endl;
	cout << "5. Ư�� ���� ��ȸ" << endl;
	cout << "6. ���� ����" << endl;
	cout << "7. ����" << endl;
	cout << "=======================" << endl;
}
int Menu::InputMenu() {	// ��ȿ���� ���� �޴����� �Է¹޾� ��ȯ
	int choice;
	cout << "����: ";
	cin >> choice;
	cout << "" << endl;

	if (choice == 1) {
		return MENUITEM_CREATE;
	}
	else if (choice == 2) {
		return MENUITEM_DEPOSIT;
	}
	else if (choice == 3) {
		return MENUITEM_WITHDRAW;
	}
	else if (choice == 4) {
		return MENUITEM_DISPLAY_ALL;
	}
	else if (choice == 5) {
		return MENUITEM_DISPLAY;
	}
	else if (choice == 6) {
		return MENUITEM_CLOSE;
	}
	else if (choice == 7) {
		return MENUITEM_EXIT;
	}
	else {	// ��ȿ������ ��� �Է°��� ���Է� ó��
		cout << "������ ��ȿ������ ������ϴ�. \n �ٽ��Է��ϼ���.\n" << endl;
	}
	return 0;
}
