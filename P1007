#include<iostream>
#include <algorithm>
using namespace std;
int army[5000];
int l;
int n;
int main() {
	cin >> l;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> army[i];
	}
	int minl = 0;
	int maxl = 0;
	for (int i = 0;i < n;i++) {
		int a = max(l + 1 - army[i], army[i]);
		int b = l + 1 - a;
		maxl = max(maxl, a);
		minl = max(minl, b);
	}
	cout << minl << " " << maxl << endl;
	return 0;
}
