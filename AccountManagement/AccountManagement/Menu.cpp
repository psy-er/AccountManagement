#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include "Account.h"
#include <iostream>
using namespace std;

void Menu::ShowMenu() {
	cout << "계좌 관리 시스템(1단계)" << endl;
	cout << "=======================" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 전체 계좌정보 출력" << endl;
	cout << "5. 특정 계좌 조회" << endl;
	cout << "6. 계좌 해지" << endl;
	cout << "7. 종료" << endl;
	cout << "=======================" << endl;
}
int Menu::InputMenu() {	// 유효범위 내의 메뉴값을 입력받아 반환
	int choice;
	cout << "선택: ";
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
	else {	// 유효범위를 벗어난 입력값은 재입력 처리
		cout << "선택이 유효범위를 벗어났습니다. \n 다시입력하세요.\n" << endl;
	}
	return 0;
}
