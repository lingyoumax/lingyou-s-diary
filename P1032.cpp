#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#define maxn 15
using namespace std;
struct node {
	string str;
	int step;
};

string a, b;
string orginal[maxn];
string translated[maxn];
int n, ans;
map<string, int> ma;

string trans(const string &str, int i, int j) {
	string ans = "";
	if (i + orginal[j].length() > str.length())
		return ans;

	for (int k = 0; k < orginal[j].length();k++)
		if (str[i + k] != orginal[j][k])
			return ans;

	ans = str.substr(0, i);
	ans += translated[j];
	ans += str.substr(i + orginal[j].length());
	return ans;
}

void bfs() {
	queue <node> q;
	node s;
	s.str = a;
	s.step = 0;
	q.push(s);

	while (!q.empty()) {
		node u = q.front();
		q.pop();
		string temp;

		if (ma.count(u.str) == 1) 
			continue;

		if (u.str == b) {
			ans = u.step;
			break;
		}
		ma[u.str] = 1;
		for (int i = 0;i < u.str.length();i++)
			for (int j = 0; j < n; j++) {
				temp = trans(u.str, i, j);
				if (temp != "") {
					node v;
					v.str = temp;
					v.step = u.step + 1;
					q.push(v);
				}
			}
	}
	if (ans > 10 || ans == 0)
		cout << "NO ANSWER!" << endl;
	else
		cout << ans << endl;

}

int main() {
	cin >> a >> b;
	while (cin >> orginal[n] >> translated[n])
		n++;
	bfs();
	return 0;
}
