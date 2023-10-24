#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
string func(string str1, string str2) {
	string result = "";
	int str1Len = str1.length();
	int str2Len = str2.length();
	int ptr1 = str1Len - 1, ptr2 = str2Len - 1;
	bool flag = false;//标记是否有进位
	while (ptr1 >= 0 || ptr2 >= 0) {
		int left = ptr1 < 0 ? 0 : str1[ptr1] - '0';
		int right = ptr2 < 0 ? 0 : str2[ptr2] - '0';
		int temp = left + right + flag;
		if (temp < 10) {
            result.insert(result.begin(), temp + '0');
			flag = false;
		}	
		else {
			result.insert(result.begin(), temp % 10 + '0');
			flag = true;
		}
		ptr1--;
		ptr2--;
	}
	if(flag)
		result.insert(result.begin(), 1 + '0');
	return result;
}
int main() {
	string str1, str2;
	cin >> str1 >> str2;
	cout << "result = " << func(str1, str2) << endl;
	return 0;
}