#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

#ifndef MAL_
#define MAL_
class MalformedData {
	string s2 = "잘못된 금액입니다!";
public:
	string getMessage() { return s2; }
};
#endif