#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"
void insertSort(int arr[], int len) {
	int temp;
	int j;//��¼���һ���ƶ�λ�õ�Ԫ��
	for (int i = 1; i < len; i++) {
		temp = arr[i];//������Ԫ��
		for (j = i - 1; j >= 0 ; j--) {
			if (temp < arr[j]) {
			  arr[j + 1] = arr[j];//Ԫ������ƶ�һλ
		    }
			else {
				break;//������������ʱ��˵�������λ���Ѿ���������Ҫ����ѭ��
			}
		}
		arr[j+1] = temp;
		cout << "��" << i  << "��:";
		for (int k = 0; k < len; k++) {
			cout << arr[k] << " ";
		}
		cout << endl;
	}
}
/*

*/