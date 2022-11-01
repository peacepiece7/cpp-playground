#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, ret = 0;
vector<double> v;

int main() {
	cin >> n;
	int b = 2;
	while (n > 1) {
		v.push_back(n % b);
		n /= b;
	}
	if (n == 1) v.push_back(1);
	reverse(v.begin(), v.end());
	for (auto a : v) {
		if (a == 1) ret++;
	}
	cout << ret << '\n';
}