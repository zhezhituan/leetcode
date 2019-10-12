#include <iostream>
#include<stdlib.h>
#include<string>
using namespace std;
struct sheep
{
	string name;
	int weight;
};
int comparInt(const void * a, const void * b) {
	return *(int*)a - *(int*)b;

}
int compareSheep(const void *a, const void* b) {
	cout<< (*(sheep*)a).weight<<"   "<< (*(sheep*)b).weight<<endl;
	return (*(sheep*)a).weight - (*(sheep*)b).weight;
	
}
void creatSheeps(sheep* &sheeps,int num) {
	for (int i = 0; i < num; i++) {
		int weight = 0;
		string name;
		cout << "输入羊的名字" <<endl;
		cin >> name;
		cout << "输入羊的重量"<<endl;
		cin >> weight;
		sheeps[i].name = name;
		sheeps[i].weight = weight;
	}

}
int main() {
	
	int a[5] = { 1,2,3,5,2 };
	qsort(a, sizeof(a) / sizeof(a[0]), sizeof(a[0]), comparInt);
	cout << a[0] << a[1] << a[2] << a[3] << a[4] << endl;
	int num = 0;
	cout << "输入羊的个数"<<endl;
	cin >> num;
	sheep* sheeps = new sheep[num];
	creatSheeps(sheeps, num);
	cout << sheeps[0].name << sheeps[1].name << sheeps[2].name << sheeps[3].weight << endl;
	qsort(sheeps, num, sizeof(sheeps[0]), compareSheep);
	cout << sheeps[0].weight << sheeps[1].weight << sheeps[2].weight << sheeps[3].weight<<endl;
	system("pause");
}