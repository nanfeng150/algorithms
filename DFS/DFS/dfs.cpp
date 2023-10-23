#define _CRT_SECURE_NO_WARNINGS
/*
给出NxM的矩阵，起点与终点
找出最短路径的长度
5 4
1 1 2 1
1 1 1 1
1 1 2 1
1 2 1 1
1 1 1 2
起点与终点坐标
1 1 4 3
*/
#include<iostream>
using namespace std;
int min_step = 0x3f3f3f3f;//存放最短路径的步数，初始化时给定是正无穷
int startx, starty, endx, endy;
int a[10][10];//给出的图，1表示可以进入，2表示不可以进入
int v[10][10];//辅助数组，表示这个点是否进入过，0表示未进入过，1表示进入过
int dx[4] = { 0,1,0,-1 };//这个数组用来标记检测下一个点的位置
int dy[4] = { 1,0,-1,0 };
void dfs(int x,int y,int step) {
	if (x == endx && y == endy) {//到达终点
		if (step < min_step)
			min_step = step;
		return;//回溯到上一步，看其他路径是否更短
	}
	//顺时针方向找现在所在点的下一个点是否可以进入
	/*if (a[x][y + 1] == 1 && v[x][y + 1] == 0) {//右边的点
		v[x][y + 1] = 1;//标记这个点已经进入
		dfs(x, y + 1, step + 1);//步数要加一
		v[x][y + 1] = 0;//回溯回来之后要将这个点标记为0，表示未进入过
	}
	if (a[x+1][y] == 1 && v[x+1][y] == 0) {//下边的点
		v[x+1][y] = 1;//标记这个点已经进入
		dfs(x+1, y, step + 1);//步数要加一
		v[x+1][y] = 0;//回溯回来之后要将这个点标记为0，表示未进入过
	}
	if (a[x][y - 1] == 1 && v[x][y - 1] == 0) {//左边的点
		v[x][y - 1] = 1;//标记这个点已经进入
		dfs(x, y - 1, step + 1);//步数要加一
		v[x][y - 1] = 0;//回溯回来之后要将这个点标记为0，表示未进入过
	}
	if (a[x-1][y] == 1 && v[x-1][y] == 0) {//上边的点边的点
		v[x-1][y] = 1;//标记这个点已经进入
		dfs(x-1, y, step + 1);//步数要加一
		v[x-1][y] = 0;//回溯回来之后要将这个点标记为0，表示未进入过
	}*/ 
	//顺时针检测
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
	return;//一步完成之后也需要回退
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