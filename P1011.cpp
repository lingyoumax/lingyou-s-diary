#include<iostream>
using namespace std;
int a_num[19];
int b_num[19];
int main() {
	int a, n, m, x;
	cin >> a >> n >> m >> x;
	
	a_num[0] = 1;
	a_num[1] = 1;
	a_num[2] = 2;
	for (int i = 3;i < 19;i++) {
		a_num[i] = a_num[i - 1] + a_num[i - 2] - 1;
		b_num[i] = b_num[i - 1] + b_num[i - 2] + 1;
	}
	int b = (m - a_num[n - 2] * a) / b_num[n - 2];
	cout << (a_num[x - 1] * a + b_num[x - 1] * b) << endl;
	return 0;
}
