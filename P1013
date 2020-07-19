#include<iostream>
#include<string>
#include<map>
using namespace std;
string s[9][9];
int num[9];
map<string, int> mymap;
int main() {
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> s[i][j];
		}
	}
	for (int i = 1;i < n;i++) {
		mymap.insert(pair<string,int>(s[0][i],-1));
	}
	for (int i = 1;i < n;i++) {
		for (int j = 1;j < n;j++) {
			if (s[i][j].size() == 1) {
				mymap[s[i][j]] += 1;
			}
		}
	}
	for (int i = 1;i < n;i++) {
		for (int j = 1;j < n;j++) {
			int t = 0;
			for (int ii = 0;ii < s[i][j].size();ii++) {
				t *= (n - 1);
				t += mymap[s[i][j].substr(ii, 1)];
			}
			int tt = mymap[s[i][0]] + mymap[s[0][j]];
			if (t != tt) {
				cout << "ERROR!" << endl;
				return 0;
			}
		}
	}
	for (int i = 1;i < n;i++) {
		cout << s[0][i] << "=" << mymap[s[0][i]] << " ";
	}
	cout << endl;
	cout << (n - 1) << endl;
	return 0;
}
