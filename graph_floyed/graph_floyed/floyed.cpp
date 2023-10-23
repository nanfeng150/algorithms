#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;
void floyed(double arr[][10],int m) {//floyed�㷨
	for (int k = 0; k < m; k++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				if ((i != j )&& (i != k) && (j != k) && (arr[i][k] + arr[k][j] < arr[i][j])) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
}
int main(){
	vector<vector<double> > array;
	int m;
	cin >> m;//��ĸ���
	for (int i = 0; i < m; i++) {
		vector<double> nums;
		int x, y;
		cin >> x >> y;//��������
		nums.push_back(x);
		nums.push_back(y);
		array.push_back(nums);
	}
	int n;
	cin >> n;
	double arr[10][10];//�ڽӾ����ͼ
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			if (i == j) {
				arr[i][j] == 0;
			}
			else {
			    arr[i][j] = 1000000007;//��ʼ���ڽӾ���
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int x, y;//�������Ƿ���ͨ
		cin >> x >> y;
		x = x - 1; 
		y = y - 1;
		arr[x][y] = sqrt(pow(double(array[x][0]-array[y][0]),2)+pow(double(array[x][1]-array[y][1]),2));
		arr[y][x] = arr[x][y];
	}
	floyed(arr, m);
	int s, t;
	cin >> s >> t;
	s = s - 1;
	t = t - 1;
	cout << arr[s][t] << endl;
	return 0;
}
/*
5
0 0
2 0
2 2
0 2
3 1
5
1 2
1 3
1 4
2 5
3 5

1 5
*/