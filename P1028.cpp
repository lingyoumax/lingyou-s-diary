#include<iostream>
using namespace std;
int arr[501];
int sum[501];
int n;
int main() {
	cin >> n;
	int t = n / 2;
	for (int i = 1;i <= t;i++) {
		arr[i] = sum[i / 2] + 1;
		sum[i] = sum[i - 1] + arr[i];
	}
	cout << (sum[t] + 1) << endl;
	return 0;
}
