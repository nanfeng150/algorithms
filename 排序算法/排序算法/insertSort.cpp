#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"
void insertSort(int arr[], int len) {
	int temp;
	int j;//记录最后一次移动位置的元素
	for (int i = 1; i < len; i++) {
		temp = arr[i];//待排序元素
		for (j = i - 1; j >= 0 ; j--) {
			if (temp < arr[j]) {
			  arr[j + 1] = arr[j];//元素向后移动一位
		    }
			else {
				break;//当不满足条件时，说明排序的位置已经有序，所以要结束循环
			}
		}
		arr[j+1] = temp;
		cout << "第" << i  << "趟:";
		for (int k = 0; k < len; k++) {
			cout << arr[k] << " ";
		}
		cout << endl;
	}
}
/*

*/