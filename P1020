#include<iostream>
#include <algorithm>
using namespace std;
int n = 0;
int num[100000];
int d1[100000];
int d2[100000];
int main() {
	while (cin >> num[n]) {
		n++;
	}
	int len1 = 0;
	int len2 = 0;
	d1[0] = num[0];
	d2[0] = num[0];
	len1++;
	len2++;
	for (int i = 1;i < n;i++) {
		if (d1[len1 - 1] >= num[i]) {
			d1[len1] = num[i];
			len1++;
		}
		else {
			int p = upper_bound(d1, d1 + len1 - 1, num[i], greater<int>()) - d1;
			d1[p] = num[i];
		}
		if (d2[len2 - 1] < num[i]) {
			d2[len2] = num[i];
			len2++;
		}
		else {
			int p = lower_bound(d2, d2 + len2 - 1, num[i]) - d2;
			d2[p] = num[i];
		}
	}
	cout << len1 << endl << len2 << endl;
	return 0;
}
