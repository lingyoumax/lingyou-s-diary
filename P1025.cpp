#include<iostream>
using namespace std;
int n, k;
int ans = 0;
int arr[7];
int main() {
	cin >> n >> k;
	int len = 0;
	int count = 0;
	arr[++len] = 1;
	count = 1;
	while (len) {
		if (len < (k-1)) {
			arr[len + 1] = arr[len];
			len++;
			count += arr[len];
		}
		else {
			ans++;
			int flag = arr[len];
			len--;
			count -= flag;
			while (len&&(flag == ((n - count) / (k - len)))) {
				flag = arr[len];
				len--;
				count -= flag;
			}
			flag++;
			if (flag<=((n-count)/(k-len))) {
				arr[len + 1] = flag;
				len++;
				count += flag;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
