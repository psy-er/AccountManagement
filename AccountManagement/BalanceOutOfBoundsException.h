#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

#ifndef BAL_
#define BAL_
class BalanceOutOfBoundsException {
	string s1 = "�ܾ��� �����մϴ�!";
public:
	string getMessage() { return s1; }
};
#endif 
