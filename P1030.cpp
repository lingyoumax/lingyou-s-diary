#include<iostream>
#include<string>
using namespace std;
string str1, str2;//str1:中序,str2：后序
int node[10][4];
int main() {
	cin >> str1 >> str2;
	int s = str1.size();
	int num = 0;
	node[num][0] = 0;
	node[num][1] = --s;
	node[num][2] = 0;
	node[num++][3] = s;
	while (num) {
		int l1 = node[--num][0];
		int r1 = node[num][1];
		int l2 = node[num][2];
		int r2 = node[num][3];
		int begin = l1;
		while (str1[begin] != str2[r2]) {
			begin++;
		}
		cout << str2[r2];
		if (r1 > begin) {
			node[num][0] = begin + 1;
			node[num][1] = r1;
			node[num][2] = l2 + begin - l1;
			node[num++][3] = --r2;
		}
		if (begin > l1) {
			node[num][0] = l1;
			node[num][1] = begin - 1;
			node[num][2] = l2;
			node[num++][3] = l2 + begin - 1 - l1;
		}
	}
	return 0;
}
