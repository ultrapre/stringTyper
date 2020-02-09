// getstring.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <stdio.h>
#include <stdlib.h>
#include <fstream>

#include <iostream>
#include <mutex>
#include "tchar.h"
#include <Windows.h>
#include <string>
#include <map>
#include <vector>
#include <atlstr.h>


#ifdef _UNICODE //这个宏 与工程字符集有关   
#define COUT wcout
#else
#define COUT cout
#endif

using namespace std;

map <CString, LPCWSTR> m1;


int cmpflag = 0;

int output(wchar_t* str) {
	//setlocale(LC_ALL, "chs");
	wprintf(L"wprintf\twchar_t* : %ls\r\n", str);
	wcout << L"wcout\twchar_t* : " << str << endl;
	printf("\n\n");
	return 0;
}

int output(LPCWSTR str) {
	//setlocale(LC_ALL, "chs");
	printf("LPCWSTR to wchar_t*\n");
	return output((wchar_t*)str);
}

int output(const char* str) {
	printf("printf\tconst char * : %s\r\n", str);
	cout << "cout\tconst char * : " << str << endl;

	//wprintf(L"wprintf\tchar_t* : %s\r\n", str);
	//wprintf(L"wprintf\tchar_t* : %ls\r\n", str);
	//wcout << L"wcout\tchar_t* : " << str << endl;

	printf("\n\n");
	return 0;
}

int output(char* str) {
	printf("printf\tchar * : %s\r\n", str);
	cout << "cout\tchar * : " << str << endl;
	printf("\n\n");
	return 0;
}

int output(string str) {
	//setlocale(LC_ALL, "chs");
	printf("string to const char*\n");
	return output(str.c_str());
}

int output(wstring str) {
	//setlocale(LC_ALL, "chs");
	printf("wstring to const wchar_t *\n");
	return output(str.c_str());
}

//int output(LPWSTR str) {
//	return output((const char*)str);
//}

enum cvttype {
	_p_char,
	_l_char,
	_p_wchar_t,
	_l_wchar_t,

	_p_TCHAR,
	_l_TCHAR,

	_CString,
	_CStringA,
	_string,
	_wstring,

	_LPSTR,
	_LPCSTR,
	_LPWSTR,
	_LPCWSTR
};
#define MAXLEN 256
char* str_p_char;
char str_l_char[MAXLEN];
wchar_t* str_p_wchar_t;
wchar_t str_l_wchar_t[MAXLEN];
TCHAR* str_p_TCHAR;
TCHAR str_l_TCHAR[MAXLEN];
CString str_CString;
CStringA str_CStringA;
string str_string;
wstring str_wstring;
LPSTR str_LPSTR;
LPCSTR str_LPCSTR;
LPWSTR str_LPWSTR;
LPCWSTR str_LPCWSTR;

auto convert(LPCWSTR str1, cvttype typea) {
	printf(" === locate at LPCWSTR\n");
	switch (typea)
	{
	case _p_char:
		str_p_char = (LPSTR)(LPCSTR)(CStringA)str1;
		break;
	case _l_char:
		strcpy(str_l_char, (LPSTR)(LPCSTR)(CStringA)str1);
		break;
	case _p_wchar_t:
		str_p_wchar_t = (wchar_t*)str1;
		break;
	case _l_wchar_t:
		wcscpy(str_l_wchar_t, str1);
		break;


	case _p_TCHAR:
		str_p_TCHAR = (TCHAR*)str1;
		break;
	case _l_TCHAR:
		wcscpy((wchar_t*)str_l_TCHAR, (wchar_t*)str1);
		break;


	case _CString:
		str_CString = str1;
		break;
	case _CStringA:
		str_CStringA = (CStringA)str1;
		break;
	case _string:
		str_string = (LPCSTR)(CStringA)str1;
		break;
	case _wstring:
		str_wstring = str1;
		break;


	case _LPSTR:
		str_LPSTR = (LPSTR)(LPCSTR)(CStringA)str1;
		break;
	case _LPCSTR:
		str_LPCSTR = (LPCSTR)(CStringA)str1;
		break;
	case _LPWSTR:
		str_LPWSTR = (LPWSTR)str1;
		break;
	case _LPCWSTR:
		str_LPCWSTR = str1;
		break;
	default:
		break;
	}
	return typea;
}

auto convert(CString str1, cvttype typea) {
	printf(" === locate at CString\n");
	switch (typea)
	{
	case _p_char:
		str_p_char = (LPSTR)(LPCSTR)(CStringA)str1;
		break;
	case _l_char:
		strcpy(str_l_char, (LPSTR)(LPCSTR)(CStringA)str1);
		break;
	case _p_wchar_t:
		str_p_wchar_t = (wchar_t*)(LPCWSTR)str1;
		break;
	case _l_wchar_t:
		wcscpy(str_l_wchar_t, str1);
		break;


	case _p_TCHAR:
		str_p_TCHAR = (TCHAR*)(LPCWSTR)str1;
		break;
	case _l_TCHAR:
		wcscpy((wchar_t*)str_l_TCHAR, (wchar_t*)(LPCWSTR)str1);
		break;


	case _CString:
		str_CString = str1;
		break;
	case _CStringA:
		str_CStringA = (CStringA)str1;
		break;
	case _string:
		str_string = (LPCSTR)(CStringA)str1;
		break;
	case _wstring:
		str_wstring = str1;
		break;


	case _LPSTR:
		str_LPSTR = (LPSTR)(LPCSTR)(CStringA)str1;
		break;
	case _LPCSTR:
		str_LPCSTR = (LPCSTR)(CStringA)str1;
		break;
	case _LPWSTR:
		str_LPWSTR = (LPWSTR)(LPCWSTR)str1;
		break;
	case _LPCWSTR:
		str_LPCWSTR = str1;
		break;
	default:
		break;
	}
	return typea;
}


auto convert(char * str1, cvttype typea) {
	printf(" === locate at char_t*\n");
	str_CString = str1;
	return convert(str_CString, typea);
}

auto convert(wchar_t* str1, cvttype typea) {
	printf(" === locate at wchar_t*\n");
	//str_CString = str1;
	CString str_CString(str1);
	//output(str_CString);
	return convert(str_CString, typea);
}

//auto convert(TCHAR* str1, cvttype typea) {
//	str_CString = str1;
//	return convert(str_CString, typea);
//}

//auto convert(CString str1, cvttype typea) {
//	str_CString = str1;
//	return typea;
//}


auto convert(CStringA str1, cvttype typea) {
	printf(" === locate at CStringA\n");
	str_CString = str1;
	return convert(str_CString, typea);
}

auto convert(string str1, cvttype typea) {
	printf(" === locate at string\n");
	str_CString = str1.c_str();
	return convert(str_CString, typea);
}

auto convert(wstring str1, cvttype typea) {
	printf(" === locate at wstring\n");
	str_CString = str1.c_str();
	return convert(str_CString, typea);
}

//auto convert(LPSTR str1, cvttype typea) {
//	str_CString = str1;
//	return convert(str_CString, typea);
//}

auto convert(LPCSTR str1, cvttype typea) {
	printf(" === locate at LPCSTR\n");
	str_CString = str1;
	return convert(str_CString, typea);
}

//auto convert(LPWSTR str1, cvttype typea) {
//	str_CString = str1;
//	return convert(str_CString, typea);
//}

//auto convert(LPCWSTR str1, cvttype typea) {
//	str_CString = str1;
//	return convert(str_CString, typea);
//}

int main()
{
	setlocale(LC_ALL, "chs");
	char* str1 = (char*)"「……今日」";
	//char str1[MAXLEN] = "「……今日」";
	//wchar_t* str1 = (wchar_t*)L"「……今日」";
	//wchar_t str1[MAXLEN] = L"「……今日」";
	//TCHAR* str1 = (TCHAR*)L"「……今日」";
	//TCHAR str1[MAXLEN] = L"「……今日」";
	//CString str1 = L"「……今日」";
	//CStringA str1 = L"「……今日」";
	//string str1 = "「……今日」";
	//wstring str1 = L"「……今日」";
	//LPSTR str1 = (LPSTR)"「……今日」";
	//LPCSTR str1 = "「……今日」";
	//LPWSTR str1 = (LPWSTR)L"「……今日」";
	//LPCWSTR str1 = L"「……今日」";

	output(str1);

	printf("_p_char	\n");
	convert(str1, _p_char);
	output(str_p_char);

	printf("_l_char	\n");
	convert(str1, _l_char);
	output(str_l_char);

	printf("_p_wchar_t	\n");
	convert(str1, _p_wchar_t);
	output(str_p_wchar_t);

	printf("_l_wchar_t	\n");
	convert(str1, _l_wchar_t);
	output(str_l_wchar_t);

	printf("_p_TCHAR	\n");
	convert(str1, _p_TCHAR);
	output(str_p_TCHAR);

	printf("_l_TCHAR	\n");
	convert(str1, _l_TCHAR);
	output(str_l_TCHAR);

	printf("_CString	\n");
	convert(str1, _CString);
	output(str_CString);

	printf("_CStringA	\n");
	convert(str1, _CStringA);
	output(str_CStringA);

	printf("_string	\n");
	convert(str1, _string);
	output(str_string);

	printf("_wstring	\n");
	convert(str1, _wstring);
	output(str_wstring);

	printf("_LPSTR	\n");
	convert(str1, _LPSTR);
	output(str_LPSTR);

	printf("_LPCSTR	\n");
	convert(str1, _LPCSTR);
	output(str_LPCSTR);

	printf("_LPWSTR	\n");
	convert(str1, _LPWSTR);
	output(str_LPWSTR);

	printf("_LPCWSTR	\n");
	convert(str1, _LPCWSTR);
	output(str_LPCWSTR);

}

