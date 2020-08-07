```cpp
#include<iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int m_num = 50;
const int n_num = 50;
ll f[(m_num*(m_num+1)) / 2];
ll map[m_num+1][m_num+n_num-1];
int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			cin >> map[i+1][j+1];
		}
	}
	for (int l = 3;l <(m+n);l++) {
		for (int i = m;i >= 1;i--) {
			for (int j = m;j > i;j--) {
				f[(j*(j + 1)) / 2 + i] = max(max(f[(j*(j + 1)) / 2 + i], f[(j*(j - 1)) / 2 + i - 1]), max(f[(j*(j - 1)) / 2 + i], f[(j*(j + 1)) / 2 + i - 1])) + map[i][l - i] + map[j][l - j];
			}
		}
	}
	cout << f[(m*(m + 1)) / 2 + m - 1];
	return 0;
}
```
