#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main() {
	int N, M;
	cout << "Please input N and M:";
	cin >> N >> M;
	int** array = new int* [N];
	for (int i = 0; i < N; i++) {
		array[i] = new int[M];
	}
	int count = 1;
	int left = 0, right = M-1;
	int top = 0, under = N-1;
	while (true) {
		for (int i=left; i <= right; i++) {//向右走
			array[top][i] = count++;
		}
		if (++top > under)break;
		for (int i=top; i <= under; i++) {//向下走
			array[i][right] = count++;
		}
		if (--right < left) break;
		for (int i = right; i >= left; i--) {//向左走
			array[under][i] = count++;
		}
		if (--under < top)break;
		for (int i = under; i >= top; i--) {//向上走
			array[i][left] = count++;
		}
		if (++left > right)break;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}