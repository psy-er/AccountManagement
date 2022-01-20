#include "AccountManager.h"
#include "Menu.h"
#include <fstream>

int main(void) {

	AccountManager accMgr;
	int choice;
	
	do {
		Menu::ShowMenu();
		choice = Menu::InputMenu();

		switch (choice) {
			case Menu::MENUITEM_CREATE:
				accMgr.CreateAccount();
				break;
			case Menu::MENUITEM_DEPOSIT:
				accMgr.Deposit();
				break;
			case Menu::MENUITEM_WITHDRAW:
				accMgr.Withdraw();
				break;
			case Menu::MENUITEM_DISPLAY_ALL:
				accMgr.DisplayAll();
				break;
			case Menu::MENUITEM_DISPLAY:
				accMgr.DisplayOne();
				break;
			case Menu::MENUITEM_CLOSE:
				accMgr.CloseAccount();
				break;
		}
	} while (choice != Menu::MENUITEM_EXIT);

	return 0;
}