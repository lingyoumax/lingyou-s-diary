#include<iostream>
#define num 10000000000000000
using namespace std;
struct big {//定义一个高精度类
	long long num1 = 0;
	long long num2 = 0;
};
void insert(big & a, int t) {//将一个int数字赋给一个高精度类
	a.num1 = t;
}
void print(big a) {//将高精度类打印输出
	if (!a.num2) {
		cout << a.num1;
	}
	else {
		cout << a.num2 << a.num1;
	}
	cout << endl;
}
big add(big a, big b) {//将两个高精度类相加
	big c;
	long long t = a.num1 + b.num1;
	c.num1 = t % num;
	t /= num;
	c.num2 = a.num2 + b.num2 + t;
	return c;
}
big mult(big a, int n) {//将一个高精度类和一个不大于10的数相乘
	big b;
	long long t = a.num1;
	t *= n;
	b.num1 = t % num;
	t /= num;
	b.num2 = (a.num2)*n + t;
	return b;
}
big max(big a, big b) {//将两个高精度进行比较
	if (a.num2 > b.num2) {
		return a;
	}
	if (b.num2 > a.num2) {
		return b;
	}
	if (a.num1 > b.num1) {
		return a;
	}
	if (b.num1 > a.num1) {
		return b;
	}
	return a;
}
int n;
int m;
big f[81];
big ans;
big deep(int m) {//对每一行进行由深到浅遍历
	big d[3300];
	int l = 0;
	while (l < m) {
		int i = 0;
		int j = i + l;
		while (j < m) {
			if (!l) {
				d[(i*(i + 1)) / 2 + i] = mult(f[i], 2);
			}
			else {
				d[(j*(j + 1)) / 2 + i] = max(add(mult(f[i], 2), mult(d[(j*(j + 1)) / 2 + i + 1], 2)), add(mult(f[j], 2), mult(d[(j*(j - 1)) / 2 + i], 2)));
			}
			i++;
			j++;
		}
		l++;
	}
	return d[((m-1)*m)/2];
}
int main() {
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			int t;
			cin >> t;
			f[j].num1 = t;
			f[j].num2 = 0;
		}
		ans = add(ans, deep(m));
	}
	print(ans);
	return 0;
}
