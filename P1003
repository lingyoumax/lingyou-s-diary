#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int ** sj = new int *[n];
	for (int i = 0;i < n;i++) {
		sj[i] = new int[4];
	}
	for (int i = 0;i < n ;i++) {
		cin >> sj[i][0] >> sj[i][1] >> sj[i][2] >> sj[i][3];
	}
	int x, y;
	cin >> x >> y;
	for (int i = (n - 1);i >= 0;i--) {
		if ((x >= sj[i][0])&&(y>=sj[i][1])&&(x<=(sj[i][0]+sj[i][2]))&&(y<=(sj[i][1]+sj[i][3]))) {
			cout << i+1 << endl;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
