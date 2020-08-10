#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
double map[401][401];
int point[401][2];
int T[101];
int n;
void get_point(int j) {
	int x1 = point[j][0];
	int y1 = point[j][1];
	int x2 = point[j + 1][0];
	int y2 = point[j + 1][1];
	int x3 = point[j + 2][0];
	int y3 = point[j + 2][1];
	int len12 = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
	int len23 = (x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3);
	int len13 = (x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3);
	if (len12 == (len23 + len13)) {
		point[j + 3][0] = x1 + x2 - x3;
		point[j + 3][1] = y1 + y2 - y3;
		return;
	}
	if (len23 == (len12 + len13)) {
		point[j + 3][0] = x2 + x3 - x1;
		point[j + 3][1] = y2 + y3 - y1;
		return;
	}
	if (len13 == (len12 + len23)) {
		point[j + 3][0] = x1 + x3 - x2;
		point[j + 3][1] = y1 + y3 - y2;
		return;
	}
}
void init(int s,int t) {
	for (int j = 0;j < s;j++) {
		for (int k = 0;k < s;k++) {
			if (j < k) {
				map[k][j] = 0;
			}
			if (!(map[k][j])) {
				if (j != k) {
					double len = sqrt(pow(point[j][0] - point[k][0], 2) + pow(point[j][1] - point[k][1], 2));
					if ((j / 4) == (k / 4)) {
						len *= T[j / 4];
					}
					else {
						len *= t;
					}
					map[j][k] = len;
				}
			}
			else {
				map[j][k] = map[k][j];
			}
		}
	}
}
void floyd(int a, int b,int s) {
	for (int p = 0;p < s;p++) {
		for (int m = 0;m < s;m++) {
			for (int n = 0;n < s;n++) {
				map[m][n] = min(map[m][n], map[m][p] + map[p][n]);
			}
		}
	}
	double ans = map[4 * a][4 * b];
	for (int j = 0;j < 4;j++) {
		for (int k = 0;k < 4;k++) {
			ans = min(ans, map[4 * a + j][4 * b + k]);
		}
	}
	cout << std::fixed << std::setprecision(1) << ans << endl;
}
void test(int i) {
	int s, t, a, b;
	cin >> s >> t >> a >> b;
	a--;
	b--;
	for (int j = 0;j < 4 * s;j += 4) {
		cin >> point[j][0] >> point[j][1] >> point[j + 1][0] >> point[j + 1][1] >> point[j + 2][0] >> point[j + 2][1] >> T[j/4];
		get_point(j);
	}
	init(4 * s, t);
	floyd(a, b, 4 * s);
}
int main() {
	cin >> n;
	while (n--) {
		test(n);
	}
	return 0;
}
