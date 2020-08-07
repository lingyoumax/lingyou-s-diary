#include<iostream>
using namespace std;
double yuce;
double dt[100010][2];
double down;
int main() {
	cin >> yuce;
	int i = 1;
	while ((dt[i-1][0]!=-1)||(dt[i-1][1]!=-1)) {
		cin >> dt[i][0] >> dt[i][1];
		i++;
	}
	i -= 2;
	cin >> down;
	double k = 0;
	while (k<=100000) {
		double max = 0;
		double temp = 0;
		for (int j = 1;j < i;j++) {
			double m = dt[j][0];
			double s = dt[j][1];
			double xh = (dt[j + 1][1] - dt[j][1]) / (dt[j + 1][0] - dt[j][0]);
			while (m < dt[j + 1][0]) {
				double zlr = (m - dt[1][0] + k)*s;
				if (zlr >= max) {
					max = zlr;
					temp = m;
				}
				m++;
				s += xh;
			}
		}
		double m = dt[i][0];
		double s = dt[i][1];
		while (s>0) {
			double zlr = (m - dt[1][0] + k)*s;
			if (zlr >= max) {
				max = zlr;
				temp = m;
			}
			m++;
			s -= down;
		}
		if (temp == yuce) {
			cout << k << endl;
			return 0;
		}
		max = 0;
		temp = 0;
		for (int j = 1;j < i;j++) {
			double m = dt[j][0];
			double s = dt[j][1];
			double xh = (dt[j + 1][1] - dt[j][1]) / (dt[j + 1][0] - dt[j][0]);
			while (m < dt[j + 1][0]) {
				double zlr = (m - dt[1][0] - k)*s;
				if (zlr >= max) {
					max = zlr;
					temp = m;
				}
				m++;
				s += xh;
			}
		}
		m = dt[i][0];
		s = dt[i][1];
		while (s > 0) {
			double zlr = (m - dt[1][0] - k)*s;
			if (zlr >= max) {
				max = zlr;
				temp = m;
			}
			m++;
			s -= down;
		}
		if (temp == yuce) {
			cout << (-1)*k << endl;
			return 0;
		}
		k++;
	}
	cout << "NO SOLUTION" << endl;
	return 0;
}
