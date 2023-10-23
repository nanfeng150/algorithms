#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"
//合并
void merge(int arr[], int temp[], int left, int mid, int right) {
	//标记左半区第一个未排序的元素
	int l_pos = left;
	//标记右半区第一个未排序的元素
	int r_pos = mid + 1;
	//临时数组元素的下标
	int pos = left;
	//合并
	while (l_pos <= mid && r_pos <= right) {
		if (arr[l_pos] <= arr[r_pos]) {
			temp[pos++] = arr[l_pos++];
		}
		else {
			temp[pos++] = arr[r_pos++];
		}
	}
	//合并左半区剩下的元素
	while (l_pos <= mid)temp[pos++] = arr[l_pos++];
	//合并右半区剩下的元素
	while (r_pos <= right)temp[pos++] = arr[r_pos++];
	//将临时数组的元素复制到原有的数组上
	while (left <= right)
	{
		arr[left] = temp[left];
		left++;
	}
}
//划分
void m_sort(int arr[], int temp[], int left, int right) {
	if (left == right)return;
	//如果元素大于一个，那么进行划分
	int mid = (left + right) / 2;
	//划分左半区
	m_sort(arr, temp, left, mid);
	//划分右半区
	m_sort(arr, temp, mid + 1, right);
	//合并排序完成的部分
	merge(arr, temp, left, mid, right);
}
//归并排序入口
void mergeSort(int arr[],int len) {
	int* temp = new int[len];
	if (temp != NULL) {
		m_sort(arr, temp, 0, len - 1);
		delete[] temp;
	}
	else return;
}
/*
 时间复杂度：O(NlogN)
 空间复杂度：O(N)
*/