/// https://www.acmicpc.net/problem/1181
#include<bits/stdc++.h>;
using namespace std;
int n;
string s;
vector<string> a;

bool cmp(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	return a.size() < b.size();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		a.push_back(s);
	}
	sort(a.begin(), a.end(), cmp);

	cout << a[0] << "\n";
	for (int i = 1; i < n; i++) {
		if (a[i - 1] == a[i]) continue;
		else cout << a[i] << "\n";
	}
	return 0;
}