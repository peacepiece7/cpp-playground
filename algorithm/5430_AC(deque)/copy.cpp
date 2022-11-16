#include<bits/stdc++.h>
using namespace std;
int t, n;
string s,ar;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> s;
		cin >> n;
		cin >> ar;
		deque<int> dq;
		string temp = "";
		for (int i = 1; i < ar.size()-1; i++) {
			if (ar[i] == ',') {
				dq.push_back(stoi(temp));
				temp = "";
			}
			else {
				temp += ar[i];
			}
		}
		if(temp.size()) dq.push_back(stoi(temp));
		bool f = false; // true == 마지막 인덱스 빼기, false == 처음인덱스 빼기
		bool error = false;
		for (int i = 0; i < s.size(); i++) 
		{
			if (s[i] == 'R') f = !f;
			else if (s[i] == 'D') {
				if (dq.empty()) {
					error = true;
					break;
				}
				if (f) dq.pop_back();
				else dq.pop_front();
			}
		}
		if (error) {
			cout << "error" << "\n";
		}
		else {
			if (f) reverse(dq.begin(), dq.end());
			cout << "[";
			for (int i = 0; i < dq.size(); i++) {
				cout << dq[i];
				if (i != dq.size() - 1) cout << ",";
			}
			cout << "]" << "\n";
		}
	}
	return 0;
}