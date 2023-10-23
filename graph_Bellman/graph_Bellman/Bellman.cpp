#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
void Bellman(int dis[],int emp[],int G1[],int G2[],int s,int N,int M) {//s为源点，V为点数,M为边数
	dis[s - 1] = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M; j++) {
			if (dis[G1[j]] + emp[j] < dis[G2[j]])
				dis[G2[j]] = dis[G1[j]] + emp[j];
		}
	}
}
int main() {
	int N;
	cout << "Please input N number:";
	cin >> N;
	int E;
	cout << "Please input E number:";
	cin >> E;
	int* emp = new int[E];
	int* G1 = new int[E];
	int* G2 = new int[E];
	memset(emp, 0, sizeof(emp));
	memset(G1, 0, sizeof(G1));
	memset(G2, 0, sizeof(G2));//G2[K]是G1[K]的前驱节点，emp[K]存放了这两个节点的距离
	cout << "Please input V1 and V2 Distace" << endl;
	for (int i = 0; i < E; i++) {
		int V1, V2, Dis;
		cin >> V1 >> V2 >> Dis;
		V1 -= 1;
		V2 -= 1;
		G1[i] = V1;
		G2[i] = V2;
		emp[i] = Dis;
	}
	int* dis = new int[N];
	for (int i = 0; i < N; i++) {
		dis[i] = 0x3f3f3f3f;
	}
	//bellman算法
	int T;
	cout << "Please input T:";
	cin >> T;
	while (T--) {
		int s, t;
		cin >> s >> t;
		Bellman(dis, emp, G1, G2, s, N, E);
		cout << dis[t - 1] << endl;
	}
	return 0;
}
/*
测试样例;
5
5
2 3 2
1 2 -3
1 5 5
4 5 2
3 4 3
5
1 2
1 5
3 5
4 5
2 5

*/