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
        cout << "第" << i + 1 << "趟:";
        for (int k = 0; k < len; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}
/*
选择排序：首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，然后，再从剩余未排序
          元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。
时间复杂度：O(n^2)
稳定性：不稳定
*/