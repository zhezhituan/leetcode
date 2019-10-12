//最小生成树Kruskal算法
#include <iostream>
using namespace std;
struct edge
{
	bool isV=false;
	int start;
	int end;
	int weight;

};
void creatEdges(edge * &edges, int v, int e) {

	edges = new edge[e];
	int start = 0;
	int end = 0;
	int weight = 0;
	cout << "输入边起点，终点，权重"<<endl;
	for (int i = 0; i < e; i++) {
		{
			cin >> start;
			cin >> end;
			cin >> weight;
			edges[i].start = start;
			edges[i].end = end;
			edges[i].weight = weight;
		}
	}
}
	int cmp(const void* a, const void* b) {
		return (*((edge*)a)).weight - (*((edge*)b)).weight;
	}
	
	int findRoot(int child,int* parent) {
		if (parent[child] == child) {
			return child;
		}
		parent[child] = findRoot(parent[child], parent);
		return parent[child];
	}
	
	bool unionTree(edge e, int* parent, int* child) {
		int root1;
		int root2;
		root1 = findRoot(e.start, parent);
		root2 = findRoot(e.end, parent);
		if (root1 != root2) {
			if (child[root1] > child[root2]) {
				parent[root2] = root1;
				child[root1] = child[root2] + child[root1] + 1;
			}
			else {
				parent[root1] = root2;
				child[root2] = child[root1] + child[root2] + 1;
			}
			return true;
		}
		return false;
	}

	void kruskal() {
		int v = 0;
		int e = 0;
		cout << "输入定点数，边数"<<endl;
		cin >> v;
		cin >> e;
		edge* edges = new edge[e];
		creatEdges(edges, v, e);
		int* parent = new int[v];
		int* child = new int[v];
		for (int i = 0; i < v; i++) {
			parent[i] = i;
			child[i] = 0;
		}
		qsort(edges, e, sizeof(edge), cmp);

		int countE = 0;
		for (int i = 0; i < e; i++) {
			if (unionTree(edges[i], parent, child)) {
				cout << edges[i].start << "到" << edges[i].end << endl;
				countE++;
			}
			if (countE == v - 1) {
				break;
			}
		}
	}
	int main(){
		kruskal();
		system("pause");
		return 0;
	}