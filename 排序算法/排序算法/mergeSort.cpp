#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"
//�ϲ�
void merge(int arr[], int temp[], int left, int mid, int right) {
	//����������һ��δ�����Ԫ��
	int l_pos = left;
	//����Ұ�����һ��δ�����Ԫ��
	int r_pos = mid + 1;
	//��ʱ����Ԫ�ص��±�
	int pos = left;
	//�ϲ�
	while (l_pos <= mid && r_pos <= right) {
		if (arr[l_pos] <= arr[r_pos]) {
			temp[pos++] = arr[l_pos++];
		}
		else {
			temp[pos++] = arr[r_pos++];
		}
	}
	//�ϲ������ʣ�µ�Ԫ��
	while (l_pos <= mid)temp[pos++] = arr[l_pos++];
	//�ϲ��Ұ���ʣ�µ�Ԫ��
	while (r_pos <= right)temp[pos++] = arr[r_pos++];
	//����ʱ�����Ԫ�ظ��Ƶ�ԭ�е�������
	while (left <= right)
	{
		arr[left] = temp[left];
		left++;
	}
}
//����
void m_sort(int arr[], int temp[], int left, int right) {
	if (left == right)return;
	//���Ԫ�ش���һ������ô���л���
	int mid = (left + right) / 2;
	//���������
	m_sort(arr, temp, left, mid);
	//�����Ұ���
	m_sort(arr, temp, mid + 1, right);
	//�ϲ�������ɵĲ���
	merge(arr, temp, left, mid, right);
}
//�鲢�������
void mergeSort(int arr[],int len) {
	int* temp = new int[len];
	if (temp != NULL) {
		m_sort(arr, temp, 0, len - 1);
		delete[] temp;
	}
	else return;
}
/*
 ʱ�临�Ӷȣ�O(NlogN)
 �ռ临�Ӷȣ�O(N)
*/