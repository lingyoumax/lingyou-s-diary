#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string str = "";
int p, k, s;
string word[6];
int w[202][202];
int f[202][42];
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
			for (int k = 0;k < s;k++) {
				string::size_type position;
				position = st.find(word[k]);
				if (position==0) {
					flag = true;
				}
			}
			if (flag) {
				w[j][i]++;
			}
		}
	}
	for (int i = 1;i <= len;i++) {
		f[i][1] = w[1][i];
	}
	for (int j = 2;j <= k;j++) {
		for (int i = j;i <= len;i++) {
			for (int m = (j - 1);m <= (i - 1);m++) {
				f[i][j] = max(f[i][j], f[m][j - 1] + w[m + 1][i]);
			}
		}
	}
	cout << f[len][k] << endl;
	return 0;
}
