#include <iostream>
#include <string>
#include <vector>
#define ROW 10
#define COL 10
using namespace std;
struct pointNode{
	int row;
	int col;
	int cost;//代价
	pointNode(int row, int col, int cost):row(row), col(col), cost(cost){}
};
struct treeNode {
	pointNode currentPoint;
	treeNode* parentNode;//指向父亲节点，找到最短路径时输出
	std::vector<treeNode*> clidrenNode;//存储孩子节点
	treeNode(pointNode curPoint, treeNode* ptr = nullptr):currentPoint(curPoint),parentNode(ptr){}
};
//创建节点
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
//计算曼哈顿距离
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
	};//地图
	int isVisited[ROW][COL] = { 0 };//是否访问过
	//定义起点
	pointNode beginPos(2, 0, 0);
	pointNode endPos(6, 7, 0);
	treeNode* root = createNode(beginPos);
	root->parentNode = nullptr;
	vector<treeNode*> locMap;
	//当前节点
	treeNode* currentNode = root;
	isVisited[currentNode->currentPoint.row][currentNode->currentPoint.col] = 1;//表示已访问
	while (1) {//一直在图里寻找四个方向
		//判断是否到达位置
		cout << "当前位置:" << currentNode->currentPoint.row << "," << currentNode->currentPoint.col << endl;
		if (currentNode->currentPoint.row == endPos.row && currentNode->currentPoint.col == endPos.col) {
			vector<pointNode> location;
			while (currentNode->parentNode) {
				location.push_back(currentNode->currentPoint);
				currentNode = currentNode->parentNode;
			}
			cout << "到达终点(" << endPos.row << "," << endPos.col << ")" << endl;
			cout << "路径:(" << beginPos.row << "," << beginPos.col << ")->";
			for (auto it = location.rbegin(); it != location.rend(); ++it) {
				cout << "(" << it->row << "," << it->col << ")->";
			}
			break;
		}
		//向上走
		if (currentNode->currentPoint.row - 1 >= 0 && map[currentNode->currentPoint.row - 1][currentNode->currentPoint.col] == 0
			&& isVisited[currentNode->currentPoint.row - 1][currentNode->currentPoint.col] == 0) {
			//计算代价
			int cost = 1 + currentNode->currentPoint.cost + getManDis(pointNode(currentNode->currentPoint.row - 1, currentNode->currentPoint.col, 0), endPos);
			//构造孩子节点
			pointNode curPoint = pointNode(currentNode->currentPoint.row - 1, currentNode->currentPoint.col, cost);
			treeNode* clidrenNode = createNode(curPoint);
			//加入容器
			clidrenNode->parentNode = currentNode;
			currentNode->clidrenNode.push_back(clidrenNode);
			locMap.push_back(clidrenNode);
			//标记走过
			isVisited[currentNode->currentPoint.row - 1][currentNode->currentPoint.col] = 1;
		}
		//向下走
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
		//向左走
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
		//向右走
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
		//找出代价最少的那个节点
		if (locMap.empty()) {
			cout << "未找到最短路径！！！" << endl;
			break;
		}
		auto iter = locMap.begin();
		for (auto it = locMap.begin(); it != locMap.end(); ++it) {
			iter = (*iter)->currentPoint.cost > (*it)->currentPoint.cost ? it : iter;
			cout << "(" << (*it)->currentPoint.row << "," << (*it)->currentPoint.col << ") ";
		}
		cout << endl;
		currentNode = *iter;
		locMap.erase(iter);//删除代价最小的那个节点
	}
	return 0;
}