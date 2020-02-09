# stringTyper
doing LPSTR,LPCSTR,LPWSTR,LPCWSTR,char*,wchar_t*,TCHAR*,CString,CStringA,string,wstring



将以上的所有类型字符串正确输出，并且相互转换。



output correctly

and convert each other





convert way:

convert A to B

<==>

convert A to CString, then convert CString to B





more benefit of CString is comparable

CString str1 = L"「……今日」";

<CString , LPCWSTR> m1 = 

{

L"「……今日」" : L"「……Today」" 

}

and then m1[str1] != NULL

