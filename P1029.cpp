#include<iostream>
using namespace std;
int x, y;
int main() {
	cin >> x >> y;
	if ((y%x) != 0) {
		cout << 0 << endl;
	}
	else {
		int q = y / x;
		int begin = 2;
		int ans = 0;
		while (q > 1) {
			if ((q%begin) == 0) {
				ans++;
				while ((q%begin) == 0) {
					q /= begin;
				}
			}
			begin++;
		}
		cout << (1 << ans) << endl;
	}
	return 0;
}
