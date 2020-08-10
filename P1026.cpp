#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string str = "";
int p, k, s;
string word[6];
int w[202][202];
int f[202][2];
int check(string st) {
	for (int i = 0;i < s;i++) {
		if (st.find(word[i]) == 0) {
			return 1;
		}
	}
	return 0;
}
int main() {
	cin >> p >> k;
	for (int i = 0;i < p;i++) {
		string st;
		cin >> st;
		str = str + st;
	}
	cin >> s;
	for (int i = 0;i < s;i++) {
		cin >> word[i];
	}
	int len = str.size();
	for (int i = 1;i <= len;i++) {
		for (int j = i;j > 0;j--) {
			w[j][i] = w[j + 1][i];
			bool flag = false;
			string st = str.substr(j - 1, i - j + 1);
			w[j][i] += check(st);
		}
	}
	bool b = 0;
	for (int i = 1;i <= len;i++) {
		f[i][b] = w[1][i];
	}
	for (int cs = 2;cs < k;cs++) {
		for (int i = cs;i <= len;i++) {
			f[i][!b] = 0;
			for (int j = cs - 1;j < i;j++) {
				f[i][!b] = max(f[i][!b], f[j][b] + w[j + 1][i]);
			}
		}
		b = !b;
	}
	int ans = 0;
	for (int i = (k - 1);i < len;i++) {
		ans = max(ans, f[i][b] + w[i + 1][len]);
	}
	cout << ans << endl;
	return 0;
}
