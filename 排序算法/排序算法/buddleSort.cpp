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
		cout << "第" << len-i+1<< "趟:";
	    for (int k = 0; k < len; k++) {
		   cout << arr[k] << " ";
	    }
	    cout << endl;
	}
}
/*
冒泡排序思想：把相邻的元素两两比较，根据大小来交换元素的位置，最大或最小的元素就会逐渐冒泡到最后
时间复杂度是O(n^2)
稳定性：稳定
*/