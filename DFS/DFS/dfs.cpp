#define _CRT_SECURE_NO_WARNINGS
/*
����NxM�ľ���������յ�
�ҳ����·���ĳ���
5 4
1 1 2 1
1 1 1 1
1 1 2 1
1 2 1 1
1 1 1 2
������յ�����
1 1 4 3
*/
#include<iostream>
using namespace std;
int min_step = 0x3f3f3f3f;//������·���Ĳ�������ʼ��ʱ������������
int startx, starty, endx, endy;
int a[10][10];//������ͼ��1��ʾ���Խ��룬2��ʾ�����Խ���
int v[10][10];//�������飬��ʾ������Ƿ�������0��ʾδ�������1��ʾ�����
int dx[4] = { 0,1,0,-1 };//�������������Ǽ����һ�����λ��
int dy[4] = { 1,0,-1,0 };
void dfs(int x,int y,int step) {
	if (x == endx && y == endy) {//�����յ�
		if (step < min_step)
			min_step = step;
		return;//���ݵ���һ����������·���Ƿ����
	}
	//˳ʱ�뷽�����������ڵ����һ�����Ƿ���Խ���
	/*if (a[x][y + 1] == 1 && v[x][y + 1] == 0) {//�ұߵĵ�
		v[x][y + 1] = 1;//���������Ѿ�����
		dfs(x, y + 1, step + 1);//����Ҫ��һ
		v[x][y + 1] = 0;//���ݻ���֮��Ҫ���������Ϊ0����ʾδ�����
	}
	if (a[x+1][y] == 1 && v[x+1][y] == 0) {//�±ߵĵ�
		v[x+1][y] = 1;//���������Ѿ�����
		dfs(x+1, y, step + 1);//����Ҫ��һ
		v[x+1][y] = 0;//���ݻ���֮��Ҫ���������Ϊ0����ʾδ�����
	}
	if (a[x][y - 1] == 1 && v[x][y - 1] == 0) {//��ߵĵ�
		v[x][y - 1] = 1;//���������Ѿ�����
		dfs(x, y - 1, step + 1);//����Ҫ��һ
		v[x][y - 1] = 0;//���ݻ���֮��Ҫ���������Ϊ0����ʾδ�����
	}
	if (a[x-1][y] == 1 && v[x-1][y] == 0) {//�ϱߵĵ�ߵĵ�
		v[x-1][y] = 1;//���������Ѿ�����
		dfs(x-1, y, step + 1);//����Ҫ��һ
		v[x-1][y] = 0;//���ݻ���֮��Ҫ���������Ϊ0����ʾδ�����
	}*/ 
	//˳ʱ����
	for (int i = 0; i < 4; i++) {
		int tempx,tempy;
		tempx = x + dx[i];
		tempy = y + dy[i];
		if (a[tempx][tempy] == 1 && v[tempx][tempy] == 0) {
			v[tempx][tempy] = 1;
			dfs(tempx, tempy, step + 1);
			v[tempx][tempy] = 0;
		}
	}
	return;//һ�����֮��Ҳ��Ҫ����
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	cin >> startx >> starty >> endx >> endy;
	v[startx][starty] = 1;
	dfs(startx, starty, 0);
	cout << min_step << endl;
	return 0;
}