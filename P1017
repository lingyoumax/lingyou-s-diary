#include<iostream>
#include<stack>
using namespace std;
int main() {
	int n;
	int m;
	int R;
	stack<int> s;
	cin >> n >> R;
	m = n;
	do {
		int t = n % R;
		n /= R;
		if (t < 0) {
			t -= R;
			n += 1;
		}
		s.push(t);
	} while (n != 0);
	cout << m << "=";
	while (!s.empty()) {
		int i = s.top();
		if ((0 <= i) && (i <= 9)) {
			cout << i;
		}
		else {
			char c = ('A' + i - 10);
			cout << c;
		}
		s.pop();
	}
	cout << "(base" << R << ")" << endl;
	return 0;
}
