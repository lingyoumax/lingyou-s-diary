#include<iostream>
#include<string>
#include <iomanip>
using namespace std;
string str;
double k = 0;
double b = 0;
bool flag = 0;
bool ysf = 0;
char name;
int main() {
	cin >> str;
	int size = str.size();
	int t = 0;
	for (int i = 0;i < size;i++) {
		char c = str[i];
		if (c == '+') {
			ysf = 0;
		}
		else {
			if (c == '-') {
				ysf = 1;
			}
			else {
				if (c == '=') {
					flag = 1;
					ysf = 0;
				}
				else {
					if (c >= 'a'&&c <= 'z') {
						name = c;
						if ((i == 0) || (str[i - 1] < '0') || (str[i - 1] > '9')) {
							k++;
						}
					}
					else {
						if (c >= '0'&&c <= '9') {
							t *= 10;
							int it = c - '0';
							t += it;
							if (((i + 1) == size) || (str[i + 1] == '+') || (str[i + 1] == '-') || (str[i + 1] == '=')) {
								if (ysf == flag) {
									b += t;
									t = 0;
								}
								else {
									b -= t;
									t = 0;
								}
							}
							else {
								if (str[i + 1] >= 'a'&&str[i + 1] <= 'z') {
									if (ysf == flag) {
										k += t;
										t = 0;
									}
									else {
										k -= t;
										t = 0;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	double ans = b / k;
	if (ans) {
		ans *= -1;
	}
	cout << name << "=" <<setprecision(3) << fixed << ans << endl;
	return 0;
}
