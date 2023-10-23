#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
enum Color{Blue,White};
int pre[10];
void Dijkstra(int dis[], int col[], int** graph,int s,int len) {//sΪԴ��,len��ĸ���
	dis[s] = 0;//Դ�㵽Դ��ľ���Ϊ0,
	while (true) {
		int minV = -1;//�����̾�����±�
		int min = 0x3f3f3f3f;
		for (int i = 0; i < len; i++) {
			if (col[i] == Color::Blue && dis[i] < min) {//����ɫ���������Сֵ
				minV = i;
				min = dis[i];
			}
		}
		if (minV == -1)break;//˵�����еĵ㶼�Ѿ��ҵ����·��
		col[minV] = Color::White;//˵��������Ѿ��ҵ���Сֵ
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
	int** graph = new int*[V_num];//��̬�����ά���飬������int*���͵�һάָ��
	for (int i = 0; i < V_num; i++) {
		graph[i] = new int[V_num];//�ٸ������һάָ�����int���Ϳռ�
	}
	//�ڽӾ���ĳ�ʼ��
	for (int i = 0; i < V_num; i++) {
		for (int j = 0; j < V_num; j++) {
			if (i == j) {
				graph[i][j] = 0;
			}
			else {
				graph[i][j] = 0x3f3f3f3f;//��ʾ����֮�䲻�ɴ�
			}
		}
	}
	cout << "graph init success!!!" << endl;
	int E_num;
	cout << "please input E number:";
	cin >> E_num;
	cout << "please input E1andE2 and E1toE2_num:" << endl;;//�����֮������ӹ�ϵ
	for (int i= 0; i < E_num; i++) {
		int E1, E2, E1toE2_num;
		cin >> E1 >> E2 >> E1toE2_num;
		E1 -= 1;
		E2 -= 1;
		graph[E1][E2] = E1toE2_num;//�ڽӾ����ŵ����֮�����ͨ��ϵ�����
		graph[E2][E1] = E1toE2_num;
	}
	int* dis =new int[V_num];
	for (int i = 0; i < V_num; i++) {//Դ�㵽Ŀ�������ĳ�ʼ��
		dis[i] = 0x3f3f3f3f;
	}
	int* col = new int[V_num];
	for (int i = 0; i < V_num; i++) {
		col[i] = Color::Blue;//�����ʾ���·��δ���
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