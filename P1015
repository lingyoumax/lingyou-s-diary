#include<iostream>
#include<string>
using namespace std;
int num[130];
int main() {
	int N;
	cin >> N;
	string M;
	cin >> M;
	int size = M.size();
	for (int i = 0;i < size;i++) {
		string str = M.substr(i, 1);
		char cc = str[0];
		if ((cc >= '0') && (cc <= '9')) {
			num[i] = cc - '0';
		}
		else {
			num[i] = cc - 'A' + 10;
		}
	}
	int step = 0;
	int i = 0;
	int j = size - 1;
	while (j > i) {
		swap(num[i], num[j]);
		i++;
		j--;
	}
	for (int ii = 0;ii < 30;ii++) {
		bool flag = true;
		int begin = 0;
		int end = size - 1;
		while (end > begin) {
			if (num[begin] != num[end]) {
				flag = false;
			}
			begin++;
			end--;
		}
		if (flag) {
			cout << "STEP=" << step << endl;
			return 0;
		}
		step++;
		int mun[130];
		for (int ij = 0;ij < size;ij++) {
			mun[ij] = num[size - 1 - ij];
		}
		int t = 0;
		for (int k = 0;k < size;k++) {
			t += num[k] + mun[k];
			num[k] = t % N;
			t /= N;
		}
		if (t) {
			num[size] = t;
			size++;
		}
	}
	cout << "Impossible!";
	return 0;
}
