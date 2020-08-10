#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
double map[401][401][11];
int point[401][2][11];
int T[101][11];
int n;
void get_point(int i, int j) {
	int x1 = point[j][0][i];
	int y1 = point[j][1][i];
	int x2 = point[j + 1][0][i];
	int y2 = point[j + 1][1][i];
	int x3 = point[j + 2][0][i];
	int y3 = point[j + 2][1][i];
	int len12 = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
	int len23 = (x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3);
	int len13 = (x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3);
	if (len12 == (len23 + len13)) {
		point[j + 3][0][i] = x1 + x2 - x3;
		point[j + 3][1][i] = y1 + y2 - y3;
		return;
	}
	if (len23 == (len12 + len13)) {
		point[j + 3][0][i] = x2 + x3 - x1;
		point[j + 3][1][i] = y2 + y3 - y1;
		return;
	}
	if (len13 == (len12 + len23)) {
		point[j + 3][0][i] = x1 + x3 - x2;
		point[j + 3][1][i] = y1 + y3 - y2;
		return;
	}
}
void init(int i,int s,int t) {
	for (int j = 0;j < s;j++) {
		for (int k = 0;k < s;k++) {
			if (!(map[k][j][i])) {
				if (j != k) {
					double len = sqrt(pow(point[j][0][i] - point[k][0][i], 2) + pow(point[j][1][i] - point[k][1][i], 2));
					if ((j / 4) == (k / 4)) {
						len *= T[j / 4][i];
					}
					else {
						len *= t;
					}
					map[j][k][i] = len;
				}
			}
			else {
				map[j][k][i] = map[k][j][i];
			}
		}
	}
}
void floyd(int i, int a, int b,int s) {
	for (int p = 0;p < s;p++) {
		for (int m = 0;m < s;m++) {
			for (int n = 0;n < s;n++) {
				map[m][n][i] = min(map[m][n][i], map[m][p][i] + map[p][n][i]);
			}
		}
	}
	double ans = map[4 * a][4 * b][i];
	for (int j = 0;j < 4;j++) {
		for (int k = 0;k < 4;k++) {
			ans = min(ans, map[4 * a + j][4 * b + k][i]);
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
		cin >> point[j][0][i] >> point[j][1][i] >> point[j + 1][0][i] >> point[j + 1][1][i] >> point[j + 2][0][i] >> point[j + 2][1][i] >> T[j/4][i];
		get_point(i, j);
	}
	init(i, 4 * s, t);
	floyd(i, a, b, 4 * s);
}
int main() {
	cin >> n;
	while (n--) {
		test(n);
	}
	return 0;
}
