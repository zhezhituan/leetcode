//��С������ Prim�㷨 
//
#include <iostream>
#include<string>
#include<vector>
using namespace std;
struct Graph {
	int vexnum;  //�������
	int edge;   //�ߵ�����
	int ** arc; //�ڽӾ���
	string *information; //��¼ÿ����������
};

void creatGraph(Graph &g) {
	cout << "���붨���� ������" << endl;
	cin >> g.vexnum;
	cin >> g.edge;
	g.information = new string[g.vexnum];
	g.arc = new int*[g.vexnum];
	int i = 0;
	for (i = 0; i < g.vexnum; i++) {
		g.arc[i] = new int[g.vexnum];
		g.information[i] = "V" + to_string(i + 1);
		for (int k = 0; k < g.vexnum; k++) {
			g.arc[i][k] = INT_MAX;
		}
	}
	cout << "���붨���ź�Ȩ��" << endl;
	for (i = 0; i < g.edge; i++) {
		int start = 0;
		int end = 0;
		int weight = 0;
		cin >> start;
		cin >> end;
		cin >> weight;
		cout << "��" << start << "��" << end << "Ȩ��" << weight << endl;
		g.arc[start - 1][end - 1] = weight;
		g.arc[end - 1][start - 1] = weight;
	}
}

void printG(Graph &g) {
	cout << "��ʾ��ǰͼ" << endl;
	for (int i = 0; i < g.vexnum; i++) {
		for (int k = 0; k < g.vexnum; k++) {
			if (g.arc[i][k] == INT_MAX) {
				cout << "***";
			}
			else
			{
				cout << g.arc[i][k];
			}
		}
		cout << endl;
	}
}
struct edge
{
	int start;
	int end;
	int weight;
	bool isV = false;
};
void primG(Graph &g, int begin) {
	edge *edges = new edge[g.vexnum];
	for (int j = 0; j < g.vexnum; j++) {
		edges[j].start = begin - 1;
		edges[j].end = j;
		edges[j].weight = g.arc[begin - 1][j];

	}
	edges[begin - 1].isV = true;

	//�������µ�g.v-1����
	for (int j = 0; j < g.vexnum - 1; j++) {
		int index = 0;
		int min = INT_MAX;
		//�ҳ���Сֵ
		for (int i = 0; i < g.vexnum; i++) {
			if (!edges[i].isV) {
				if (edges[i].weight < min) {
					min = edges[i].weight;
					index = i;
					//cout << index << endl;
				}
			}
		}


		edges[index].isV = true;
		cout << edges[index].start << "   " << edges[index].end << endl;
		//��������
		for (int i = 0; i < g.vexnum; i++) {
			if (!edges[i].isV) {
				if (g.arc[index][i] < edges[i].weight) {
					edges[i].weight = g.arc[index][i];
					edges[i].start = index;

				}
			}
		}
	}
}



int main() {
	Graph g;
	creatGraph(g);
	printG(g);
	primG(g, 1);
	system("pause");
	return(0);
}