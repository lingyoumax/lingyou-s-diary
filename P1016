#include<iostream>
#include <iomanip>
using namespace std;
double d1;
double c;
double d2;
double p;
int n;
double pi[8];
double di[8];
double cost;
int main() {
	cin >> d1 >> c >> d2 >> p >> n;
	double h = 0;//汽车油量
	for (int i = 1;i <= n;i++) {
		cin >> di[i] >> pi[i];
	}
	pi[0] = p;
	di[n + 1] = d1;
	for (int i = (n+1) ;i > 0;i--) {
		di[i] -= di[i - 1];
		if (di[i] > (c * d2)) {
			cout << "No Solution" << endl;
			return 0;
		}
	}
	int flag = 0;//汽车到的位置
	while (flag != (n + 1)) {
		int i = flag + 1;
		double len = 0;
		double minp = 500;
		int pmin = i;
		while ((len+di[i]) <= (c*d2)) {
			len += di[i];
			if (pi[i] < minp) {
				minp = pi[i];
				pmin = i;
				if (pi[i] <= pi[flag]) {
					break;
				}
			}
			i++;
		}
		if (minp <= pi[flag]) {
			cost += ((len / d2) - h)*pi[flag];
			h = 0;
		}
		else {
			cost += (c - h)*pi[flag];
			h = c - len / d2;
		}
		flag = pmin;
	}
	cout << setprecision(2) << fixed << cost << endl;
	return 0;
}
