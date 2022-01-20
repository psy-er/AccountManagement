#define _CRT_SECURE_NO_WARNINGS
#ifndef _MENU_H
#define _MENU_H
#include "Account.h"
#include <iostream>
using namespace std;

class Menu {
public:
	static const int MENUITEM_CREATE = 1;
	static const int MENUITEM_DEPOSIT = 2;
	static const int MENUITEM_WITHDRAW = 3;
	static const int MENUITEM_DISPLAY_ALL = 4;
	static const int MENUITEM_DISPLAY = 5;
	static const int MENUITEM_CLOSE = 6;
	static const int MENUITEM_EXIT = 7;

	static void ShowMenu();
	static int InputMenu();
};

#endif
