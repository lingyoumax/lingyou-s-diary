#include<iostream>
#include<string>
using namespace std;
int main() {
	string s[20];
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> s[i];
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < (n - i-1);j++) {
			string s1 = s[j] + s[j + 1];
			string s2 = s[j + 1] + s[j];
			if (s1 < s2) {
				string t = s[j];
				s[j] = s[j+1];
				s[j+1] = t;
			}
		}
	}
	for (int i = 0;i < n;i++) {
		cout << s[i];
	}
	cout << endl;
	return 0;
}
