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
  i:待维护节点的下标
  arr:存储堆的数组
  size:需要维护数组的长度
  时间复杂度：O(logn)
*/
void heapify_max(int arr[], int size, int i) {
	int temp = i;
	int leftson = 2 * i + 1;
	int rightson = 2 * i + 2;
	if (leftson<size&& arr[leftson]>arr[temp]) {//如果左孩子的值大于父节点，父节点等于左孩子的下标
		temp = leftson;
	}
	if (rightson<size && arr[rightson]>arr[temp]) {
		temp = rightson;
	}
	if (temp != i) {
		swap(&arr[temp], &arr[i]);
		heapify_max(arr, size, temp);//递归调用，维护大顶堆的性质
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
		heapify_min(arr, size, temp);//递归调用，维护小顶堆的性质
	}
}
//堆排序第一步：建堆(复杂度O(N,稳定性：不稳定))
void create_heap(int arr[], int size) {
	int i = size / 2 - 1;
	for (i; i >= 0; i--) {
		//heapify_max(arr,size,i);
		heapify_min(arr, size, i);
	}
}
//堆排序第二步：排序(时间复杂度：O(NlogN))
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
	std::cout << "排序前：";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	create_heap(arr, size);
	sort_heap(arr, size);
	std::cout << std::endl;
	std::cout << "排序前：";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
}