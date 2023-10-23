#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

/*
  i:��ά���ڵ���±�
  arr:�洢�ѵ�����
  size:��Ҫά������ĳ���
  ʱ�临�Ӷȣ�O(logn)
*/
void heapify_max(int arr[], int size, int i) {
	int temp = i;
	int leftson = 2 * i + 1;
	int rightson = 2 * i + 2;
	if (leftson<size&& arr[leftson]>arr[temp]) {//������ӵ�ֵ���ڸ��ڵ㣬���ڵ�������ӵ��±�
		temp = leftson;
	}
	if (rightson<size && arr[rightson]>arr[temp]) {
		temp = rightson;
	}
	if (temp != i) {
		swap(&arr[temp], &arr[i]);
		heapify_max(arr, size, temp);//�ݹ���ã�ά���󶥶ѵ�����
	}
}

void heapify_min(int arr[], int size, int i) {
	int temp = i;
	int leftson = 2 * i + 1;
	int rightson = 2 * i + 2;
	if (leftson < size && arr[leftson] < arr[temp]) {
		temp = leftson;
	}
	if (rightson < size && arr[rightson] < arr[temp]) {
		temp = rightson;
	}
	if (temp != i) {
		swap(&arr[temp], &arr[i]);
		heapify_min(arr, size, temp);//�ݹ���ã�ά��С���ѵ�����
	}
}
//�������һ��������(���Ӷ�O(N,�ȶ��ԣ����ȶ�))
void create_heap(int arr[], int size) {
	int i = size / 2 - 1;
	for (i; i >= 0; i--) {
		//heapify_max(arr,size,i);
		heapify_min(arr, size, i);
	}
}
//������ڶ���������(ʱ�临�Ӷȣ�O(NlogN))
void sort_heap(int arr[], int size) {
	int i = size - 1;
	for (i; i > 0; i--) {
		swap(&arr[i], &arr[0]);
		//heapify_max(arr, i, 0);
		heapify_min(arr, i, 0);
	}
}

int main() {
	int arr[] = { 10,4,2,92,7,36,1,94,30,100,27,5,8,100 };
	int size = sizeof(arr) / sizeof(int);
	std::cout << "����ǰ��";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	create_heap(arr, size);
	sort_heap(arr, size);
	std::cout << std::endl;
	std::cout << "����ǰ��";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
}