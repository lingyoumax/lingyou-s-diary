#include<iostream>
using namespace std;
int main() {
	int sum = 0;
	int n;
	int arr[101];
	int ans = 0;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sum /= n;
	for (int i = 0;i < n;i++) {
		arr[i] -= sum;
		if (arr[i] != 0) {
			ans++;
			arr[i + 1] += arr[i];
		}
	}
	cout << ans << endl;
	return 0;
}
