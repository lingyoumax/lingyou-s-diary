#include<iostream>
const long long num = 100000000000000000;
using namespace std;
struct big {
	long long num1 = 0;
	long long num2 = 0;
	long long num3 = 0;
	long long num4 = 0;
};
big add(big a, big b) {//将两个高精度类相加
	big c;
	long long t = a.num1 + b.num1;
	c.num1 = t % num;
	t /= num;
	t += a.num2 + b.num2;
	c.num2 = t % num;
	t /= num;
	t += a.num3 + b.num3;
	c.num3 = t % num;
	t /= num;
	c.num4 = t + a.num4 + b.num4;
	return c;
}
big mult(big a, int n) {
	big b;
	long long t = a.num1;
	t *= n;
	b.num1 = t % num;
	t /= num;
	t += a.num2*n;
	b.num2 = t % num;
	t /= num;
	t += a.num3*n;
	b.num3 = t % num;
	t /= num;
	b.num4 = a.num4*n + t;
	return b;
}
void print(big a) {//将高精度类打印输出
	if (a.num4) {
		cout << a.num4 << a.num3 << a.num2 << a.num1 << endl;
	}
	else {
		if (a.num3) {
			cout << a.num3 << a.num2 << a.num1 << endl;
		}
		else {
			if (a.num2) {
				cout << a.num2 << a.num1 << endl;
			}
			else {
				cout << a.num1 << endl;
			}
		}
	}
}
int main() {
	int n;
	cin >> n;
	big ans;
	big t;
	t.num1 = 1;
	for (int i = 1;i <= n;i++) {
		t = mult(t, i);
		ans = add(ans, t);
	}
	print(ans);
	return 0;
}
