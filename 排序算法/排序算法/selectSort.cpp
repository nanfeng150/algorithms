#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"
void selectSort(int arr[], int len) {
    for (int i = 0; i < len-1; i++) {
        int min_index = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[min_index])min_index = j;
        }
        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
        cout << "��" << i + 1 << "��:";
        for (int k = 0; k < len; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}
/*
ѡ������������δ�����������ҵ���С����Ԫ�أ���ŵ��������е���ʼλ�ã�Ȼ���ٴ�ʣ��δ����
          Ԫ���м���Ѱ����С����Ԫ�أ�Ȼ��ŵ����������е�ĩβ���Դ����ƣ�ֱ������Ԫ�ؾ�������ϡ�
ʱ�临�Ӷȣ�O(n^2)
�ȶ��ԣ����ȶ�
*/