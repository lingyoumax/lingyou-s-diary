#include<iostream>
#include<cmath>
#include<queue>
#define left -3
#define right -2
#define add -1
using namespace std;
int main() {
	queue<int> q[2];
	int n;
	cin >> n;
	bool i = 0;
	q[i].push(n);
	while (true) {
		bool cs = false;
		while (!q[i].empty()) {
			int t = q[i].front();
			q[i].pop();
			if (t <= 2) {
				q[!i].push(t);
			}
			else {
			   cs = true;
			   bool flag = false;
				while (t != 0) {
					if (flag) {
						q[!i].push(add);
					}
					int mi = log(t) / log(2);
					t -= pow(2, mi);
					q[!i].push(2);
					if (mi != 1) {
						q[!i].push(left);
						q[!i].push(mi);
						q[!i].push(right);
					}
					flag = true;
				}
			}
		}
		if (!cs) {
			break;
		}
		i = !i;
	}
	if (!q[i].empty()) {
		while (!q[i].empty()) {
			int t = q[i].empty();
			switch (t) {
			case -3:
				cout << "(";
				break;
			case -2:
				cout << ")";
				break;
			case -1:
				cout << "+";
				break;
			default:
				cout << t;
			}
			q[i].pop();
		}
		cout << endl;
	}
	else {
		while (!q[!i].empty()) {
			int t = q[!i].front();
			switch (t) {
			case -3:
				cout << "(";
				break;
			case -2:
				cout << ")";
				break;
			case -1:
				cout << "+";
				break;
			default:
				cout << t;
			}
			q[!i].pop();
		}
		cout << endl;
	}
	return 0;
}
