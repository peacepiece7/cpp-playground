/*
https://www.acmicpc.net/problem/2108
조건이 까다로움.. 다시 집중해서 풀어보기

*/

#include<bits/stdc++.h>;
using namespace std;
map<int, int> pmp;
map<int, int> mmp;
vector<int> v;
int n,x,sum, freq, mid, freqVal;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x < 0) {
			mmp[abs(x)]++;
			freq = max(mmp[abs(x)], freq);
		}
		else {
			pmp[abs(x)]++;
			freq = max(pmp[abs(x)], freq);
		}
		sum += x;
		v.push_back(x);
	}

	if (sum < 0) cout << -ceil((double)(abs(sum) / v.size())) << "\n";
	else cout << sum / v.size() << "\n";
	sort(v.begin(), v.end());
	cout << v[v.size() / 2] << "\n"; // mid

	vector<int> freqs;
	for (pair<int, int> el : mmp) {
		if (el.second == freq) freqs.push_back(-el.first);
	}
	for (pair<int, int> el : pmp) {
		if (el.second == freq) freqs.push_back(el.first);
	}
	sort(freqs.begin(), freqs.end());
	if (freqs.size() >= 2) {
		cout << freqs[1] << "\n";
	}
	else cout << freqs[0] << "\n";

	cout << v[0] - v[v.size() - 1] << "\n";
}
