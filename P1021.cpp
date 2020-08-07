#include<iostream>
#include<algorithm>
#define inf 99999999
using namespace std;
int n;//n张邮票
int k;//k种邮票
int stack[15];//dfs需要
int num = 0;
int ans[15];//输出答案
int maxx = 0;
void dp() {
	int f[50000];
	f[0] = 0;
	int begin = 1;
	while (begin<50000) {
		f[begin] = inf;
		for (int i = 1;i <= num;i++) {
			if (stack[i] == begin) {
				f[begin] = 1;
			}
		}
		if (f[begin] != 1) {
			for (int j = 1;j <= (begin / 2);j++) {
				f[begin] = min(f[begin], f[j] + f[begin - j]);
			}
		}
		if (f[begin] > n) {
			break;
		}
		else {
			begin++;
		}
	}
	begin--;
	if (begin > maxx) {
		maxx = begin;
		for (int i = 1;i <= k;i++) {
			ans[i] = stack[i];
		}
	}
}
int main() {
	cin >> n >> k;
	stack[++num] = 1;
	while (num) {
		if (num < k) {
			stack[num + 1] = stack[num] + 1;
			num++;
		}
		else {
			dp();
			int flag = stack[num];
			stack[num] = 0;
			num--;
			while (num && (flag == (stack[num] * n + 1))) {
				flag = stack[num];
				stack[num] = 0;
				num--;
			}
			if (num) {
				stack[num + 1] = flag + 1;
				num++;
			}
		}
	}
	for (int i = 1;i <= k;i++) {
		cout << ans[i] << " ";
	}
	cout << endl << "MAX=" << maxx << endl;
	return 0;
}
