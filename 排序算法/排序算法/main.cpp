#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"
//���
void print(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main() {
	int array[10] = { 4,1,8,2,3,10,5,9,7,6 };
	int array1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "����ǰ:";
	print(array, 10);
	cout << "�����:";
	//buddleSort(array, 10);
	//buddleSort(array1, 10);
	//insertSort(array, 10);
	//selectSort(array, 10);
	//insertSort(array, 10);
	//shellSort(array, 10);
	//mergeSort();
	//mergeSort(array, 10);
	print(array, 10);
	return 0;
}