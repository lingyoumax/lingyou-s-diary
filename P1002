#include <iostream>
#define ull unsigned long long
using namespace std;
ull f[23];
bool s[23][23];
int main() {
	int bx, by, mx, my;
	cin >> bx >> by >> mx >> my;
	bx+=2;
	by+=2;
	mx+=2;
	my+=2;
	int x[] = {0,1,1,-1,-1,2,2,-2,-2};
	int y[] = {0,2,-2,2,-2,1,-1,1,-1};
	for (int i = 0;i <= 8;i++) {
		s[mx + x[i]][my + y[i]] = 1;
	}
	f[2] = 1;
	for (int i = 2;i <= bx;i++) {
		for (int j = 2;j <= by;j++) {
			if (s[i][j]) {
				f[j] = 0;
			}
			else {
				f[j] +=f[j-1];
			}
		}
	}
	cout << f[by];
	return 0;
}
