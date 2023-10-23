#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"
void shellSort(int arr[], int len) {
	for (int role = 4; role > 0; role /= 2) {
		for (int i = role; i < len; i++) {
			for (int j = i; j >role-1; j-=role) {
				if (arr[j] < arr[j - role]) {
					int temp = arr[j];
					arr[j] = arr[j - role];
					arr[j - role] = temp;
				}
			}
		}
		cout << "╣з" << role/2 << "лк:";
		for (int k = 0; k < len; k++) {
			cout << arr[k] << " ";
		}
		cout << endl;
	}
}