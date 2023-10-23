#include <iostream>
#include <vector>
using namespace std;
//�������򣨴�С����
void quickSort(int left, int right, vector<int>& arr)
{
	if (left >= right)
		return;
	int i, j, base, temp;
	i = left, j = right;
	base = arr[left];  //ȡ����ߵ���Ϊ��׼��
	while (i < j)
	{
		while (arr[j] >= base && i < j)
			j--;
		while (arr[i] <= base && i < j)
			i++;
		if (i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//��׼����λ
	arr[left] = arr[i];
	arr[i] = base;
	quickSort(left, i - 1, arr);//�ݹ����
	quickSort(i + 1, right, arr);//�ݹ��ұ�
}
int main(int argc, char* argv[]) {
	vector<int> nums{ 3, 1, 5, 8, 2, 9, 7, 6, 4, 0 };
	quickSort(0, nums.size() - 1, nums);
	for (int num : nums)
		cout << num << " ";
	return 0;
}