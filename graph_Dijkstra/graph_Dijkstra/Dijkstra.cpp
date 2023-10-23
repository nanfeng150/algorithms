#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
enum Color{Blue,White};
int pre[10];
void Dijkstra(int dis[], int col[], int** graph,int s,int len) {//s为源点,len点的个数
	dis[s] = 0;//源点到源点的距离为0,
	while (true) {
		int minV = -1;//标记最短距离的下标
		int min = 0x3f3f3f3f;
		for (int i = 0; i < len; i++) {
			if (col[i] == Color::Blue && dis[i] < min) {//从蓝色点的中找最小值
				minV = i;
				min = dis[i];
			}
		}
		if (minV == -1)break;//说明所有的点都已经找到最短路径
		col[minV] = Color::White;//说明这个点已经找到最小值
		for (int i = 0; i < len; i++) {
			if (dis[i] > dis[minV] + graph[minV][i]) {
				dis[i] = dis[minV] + graph[minV][i];
				pre[i+1] = minV+1;
				cout << pre[i] << "--";
			}
		}
	}
}
void output(int z) {
	if (pre[z] == 0)return;
	output(pre[z]);
	cout << pre[z]<< "->";
}
int main() {
	int V_num;
	cout << "please input V number:";
	cin >> V_num;
	int** graph = new int*[V_num];//动态定义二维数组，先申请int*类型的一维指针
	for (int i = 0; i < V_num; i++) {
		graph[i] = new int[V_num];//再给申请的一维指针分配int类型空间
	}
	//邻接矩阵的初始化
	for (int i = 0; i < V_num; i++) {
		for (int j = 0; j < V_num; j++) {
			if (i == j) {
				graph[i][j] = 0;
			}
			else {
				graph[i][j] = 0x3f3f3f3f;//表示两点之间不可达
			}
		}
	}
	cout << "graph init success!!!" << endl;
	int E_num;
	cout << "please input E number:";
	cin >> E_num;
	cout << "please input E1andE2 and E1toE2_num:" << endl;;//点与点之间的连接关系
	for (int i= 0; i < E_num; i++) {
		int E1, E2, E1toE2_num;
		cin >> E1 >> E2 >> E1toE2_num;
		E1 -= 1;
		E2 -= 1;
		graph[E1][E2] = E1toE2_num;//邻接矩阵存放点与点之间的联通关系与距离
		graph[E2][E1] = E1toE2_num;
	}
	int* dis =new int[V_num];
	for (int i = 0; i < V_num; i++) {//源点到目标点数组的初始化
		dis[i] = 0x3f3f3f3f;
	}
	int* col = new int[V_num];
	for (int i = 0; i < V_num; i++) {
		col[i] = Color::Blue;//蓝点表示最短路径未求出
	}
	int s, t;
	cout << "please input S and T:";
	cin >> s >> t;
	Dijkstra(dis, col, graph, s - 1, V_num);
	cout << "S to T min distance:";
	cout << dis[t - 1] << endl;
	for (int i = 0; i < V_num; i++) {
		cout << dis[i] << " ";
	}
	cout << endl;
	output(t);
	cout << t;
	return 0;
}
/*
3
3
1 2 5
2 3 5
3 1 2
1 2

*/