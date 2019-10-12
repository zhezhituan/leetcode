#include <iostream>
#include<stdlib.h>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
string countAndSay(int n) {
	string res = res + "1";
	res = res + "x";
	cout << res;
	for (int i = 2; i <= n; i++) {
		string temp;
		int num = 1;
		for (int j = 0; j < res.size() - 1; j++) {
			if (res[j] == res[j + 1])num++;
			else {
				temp = temp + to_string(num) + res[j];
				num = 1;
			}
		}
		res = temp + "x";
		cout << res;
	}
	res.erase(res.end());
	return res;
}
int main() {
	string res = countAndSay(5);
	cout << res;
	cin >> res;

}