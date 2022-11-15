#include<iostream>
using namespace std;
int ret;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int j = i;
		int temp = i;
		while (j) {
			temp += j % 10;
			j = j / 10;
		}
		if (temp == n) {
			ret = i;
			break;
		}
	}
	cout << ret << "\n";
}