#include<iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll f[11][11];
ll map[11][11];
int main() {
	int n;
	cin >> n;
	while (true) {
		ll x, y, z;
		cin >> x >> y >> z;
		if ((!x) && (!y) && (!z)) {
			break;
		}
		map[x++][y++] = z;
	}
	for (int l = 2;l <= n * 2;l++) {
		for (int i = l - 1;i >= 1;i--) {
			for (int ii = l - 1;ii >= 1;ii--){
				int j = l - i;
				int jj = l - ii;
				if ((i <= n) && (j <= n) && (ii <= n) && (jj <= n)) {
					f[i][ii] = max(max(f[i][ii], f[i - 1][ii - 1]), max(f[i - 1][ii], f[i][ii - 1])) + map[i][j];
					f[i][ii] += map[ii][jj] * (i != ii);
				}
			}
		}
	}
	cout << f[n][n] << endl;
	return 0;
}
