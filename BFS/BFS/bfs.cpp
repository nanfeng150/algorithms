#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
int a[10][10];
int col[10][10];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
struct point {
	int x;
	int y;
	int step;
};
queue<point> Q;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	int startx, starty, endx, endy;
	cin >> startx >> starty >> endx >> endy;
	point start;
	start.x = startx;
	start.y = starty;
	start.step = 0;
	Q.push(start);
	while (!Q.empty()) {
		int p = Q.front().x;
		int q = Q.front().y;
		if (p == endx && q == endy) {
			cout <<"���·��Ϊ:" << Q.front().step<<"��" << endl;
		}
		for (int i = 0; i < 4; i++) {
			int tempx, tempy;
			tempx = p + dx[i];
			tempy = q + dy[i];
			if (a[tempx][tempy] == 1 && col[tempx][tempy] == 0) {
				col[tempx][tempy] = 1;
				point node;
				node.x = tempx;
				node.y = tempy;
				node.step = Q.front().step + 1;
				Q.push(node);
			}
		}
		Q.pop();
	}
	return 0;
}
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