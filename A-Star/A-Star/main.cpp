#include <iostream>
#include <string>
#include <vector>
#define ROW 10
#define COL 10
using namespace std;
struct pointNode{
	int row;
	int col;
	int cost;//����
	pointNode(int row, int col, int cost):row(row), col(col), cost(cost){}
};
struct treeNode {
	pointNode currentPoint;
	treeNode* parentNode;//ָ���׽ڵ㣬�ҵ����·��ʱ���
	std::vector<treeNode*> clidrenNode;//�洢���ӽڵ�
	treeNode(pointNode curPoint, treeNode* ptr = nullptr):currentPoint(curPoint),parentNode(ptr){}
};
//�����ڵ�
treeNode* createNode(pointNode curPoint) {
	/*treeNode* node = (treeNode*)malloc(sizeof(treeNode));
	cout << sizeof(node) << endl;
	if (node == NULL)
		cout << "NULL" << endl;
	node->currentPoint = curPoint;
	node->parentNode = nullptr;*/
	treeNode* node = new treeNode(curPoint);
	return node;
}
//���������پ���
int  getManDis(const pointNode node1, const pointNode node2) {
	return abs(node1.row - node2.row) + abs(node1.col - node2.col);
}
int main(int argc, char *argv[]) {
	int map[ROW][COL] = {
		{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 1, 1, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }
	};//��ͼ
	int isVisited[ROW][COL] = { 0 };//�Ƿ���ʹ�
	//�������
	pointNode beginPos(2, 0, 0);
	pointNode endPos(6, 7, 0);
	treeNode* root = createNode(beginPos);
	root->parentNode = nullptr;
	vector<treeNode*> locMap;
	//��ǰ�ڵ�
	treeNode* currentNode = root;
	isVisited[currentNode->currentPoint.row][currentNode->currentPoint.col] = 1;//��ʾ�ѷ���
	while (1) {//һֱ��ͼ��Ѱ���ĸ�����
		//�ж��Ƿ񵽴�λ��
		cout << "��ǰλ��:" << currentNode->currentPoint.row << "," << currentNode->currentPoint.col << endl;
		if (currentNode->currentPoint.row == endPos.row && currentNode->currentPoint.col == endPos.col) {
			vector<pointNode> location;
			while (currentNode->parentNode) {
				location.push_back(currentNode->currentPoint);
				currentNode = currentNode->parentNode;
			}
			cout << "�����յ�(" << endPos.row << "," << endPos.col << ")" << endl;
			cout << "·��:(" << beginPos.row << "," << beginPos.col << ")->";
			for (auto it = location.rbegin(); it != location.rend(); ++it) {
				cout << "(" << it->row << "," << it->col << ")->";
			}
			break;
		}
		//������
		if (currentNode->currentPoint.row - 1 >= 0 && map[currentNode->currentPoint.row - 1][currentNode->currentPoint.col] == 0
			&& isVisited[currentNode->currentPoint.row - 1][currentNode->currentPoint.col] == 0) {
			//�������
			int cost = 1 + currentNode->currentPoint.cost + getManDis(pointNode(currentNode->currentPoint.row - 1, currentNode->currentPoint.col, 0), endPos);
			//���캢�ӽڵ�
			pointNode curPoint = pointNode(currentNode->currentPoint.row - 1, currentNode->currentPoint.col, cost);
			treeNode* clidrenNode = createNode(curPoint);
			//��������
			clidrenNode->parentNode = currentNode;
			currentNode->clidrenNode.push_back(clidrenNode);
			locMap.push_back(clidrenNode);
			//����߹�
			isVisited[currentNode->currentPoint.row - 1][currentNode->currentPoint.col] = 1;
		}
		//������
		if (currentNode->currentPoint.row + 1 <  ROW && map[currentNode->currentPoint.row + 1][currentNode->currentPoint.col] == 0
			&& isVisited[currentNode->currentPoint.row + 1][currentNode->currentPoint.col] == 0) {
			int cost = 1 + currentNode->currentPoint.cost + getManDis(pointNode(currentNode->currentPoint.row + 1, currentNode->currentPoint.col, 0), endPos);
			pointNode curPoint = pointNode(currentNode->currentPoint.row + 1, currentNode->currentPoint.col, cost);
			treeNode* clidrenNode = createNode(curPoint);
			clidrenNode->parentNode = currentNode;
			currentNode->clidrenNode.push_back(clidrenNode);
			locMap.push_back(clidrenNode);
			isVisited[currentNode->currentPoint.row + 1][currentNode->currentPoint.col] = 1;
		}
		//������
		if ((currentNode->currentPoint.col - 1) >= 0 && map[currentNode->currentPoint.row][currentNode->currentPoint.col - 1] == 0
			&& isVisited[currentNode->currentPoint.row][currentNode->currentPoint.col - 1] == 0) {
			int cost = 1 + currentNode->currentPoint.cost + getManDis(pointNode(currentNode->currentPoint.row, currentNode->currentPoint.col - 1, 0), endPos);
			pointNode curPoint = pointNode(currentNode->currentPoint.row, currentNode->currentPoint.col - 1, cost);
			treeNode* clidrenNode = createNode(curPoint);
			clidrenNode->parentNode = currentNode;
			currentNode->clidrenNode.push_back(clidrenNode);
			locMap.push_back(clidrenNode);
			isVisited[currentNode->currentPoint.row][currentNode->currentPoint.col - 1] = 1;
		}
		//������
		if ((currentNode->currentPoint.col + 1) < COL && map[currentNode->currentPoint.row][currentNode->currentPoint.col + 1] == 0
			&& isVisited[currentNode->currentPoint.row][currentNode->currentPoint.col + 1] == 0) {
			int cost = 1 + currentNode->currentPoint.cost + getManDis(pointNode(currentNode->currentPoint.row, currentNode->currentPoint.col + 1, 0), endPos);
			pointNode curPoint = pointNode(currentNode->currentPoint.row, currentNode->currentPoint.col + 1, cost);
			treeNode* clidrenNode = createNode(curPoint);
			clidrenNode->parentNode = currentNode;
			currentNode->clidrenNode.push_back(clidrenNode);
			locMap.push_back(clidrenNode);
			isVisited[currentNode->currentPoint.row][currentNode->currentPoint.col + 1] = 1;
		}
		//�ҳ��������ٵ��Ǹ��ڵ�
		if (locMap.empty()) {
			cout << "δ�ҵ����·��������" << endl;
			break;
		}
		auto iter = locMap.begin();
		for (auto it = locMap.begin(); it != locMap.end(); ++it) {
			iter = (*iter)->currentPoint.cost > (*it)->currentPoint.cost ? it : iter;
			cout << "(" << (*it)->currentPoint.row << "," << (*it)->currentPoint.col << ") ";
		}
		cout << endl;
		currentNode = *iter;
		locMap.erase(iter);//ɾ��������С���Ǹ��ڵ�
	}
	return 0;
}