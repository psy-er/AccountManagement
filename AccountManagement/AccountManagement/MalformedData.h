#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

#ifndef MAL_
#define MAL_
class MalformedData {
	string s2 = "�߸��� �ݾ��Դϴ�!";
public:
	string getMessage() { return s2; }
};
#endif