#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"
void buddleSort(int arr[], int len) {
	int temp;
	for (int i = len; i > 1; i--) {
	    bool swap = false;
		for (int j = 0; j < i-1; j++) {
			if (arr[j] > arr[j+1]) {
				swap = true;
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
		if (!swap)return;
		cout << "��" << len-i+1<< "��:";
	    for (int k = 0; k < len; k++) {
		   cout << arr[k] << " ";
	    }
	    cout << endl;
	}
}
/*
ð������˼�룺�����ڵ�Ԫ�������Ƚϣ����ݴ�С������Ԫ�ص�λ�ã�������С��Ԫ�ؾͻ���ð�ݵ����
ʱ�临�Ӷ���O(n^2)
�ȶ��ԣ��ȶ�
*/