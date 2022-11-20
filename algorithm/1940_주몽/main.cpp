/*

갑옷을 만드는 재료들은 각각 고유한 번호를 가지고 있다. 
갑옷은 두 개의 재료로 만드는데 두 재료의 고유한 번호를 합쳐서 M(1 ≤ M ≤ 10,000,000)이 되면 갑옷이 만들어 지게 된다.

첫째 줄에는 재료의 개수 N(1 ≤ N ≤ 15,000)이 주어진다. 
그리고 두 번째 줄에는 갑옷을 만드는데 필요한 수 M(1 ≤ M ≤ 10,000,000) 주어진다. 
그리고 마지막으로 셋째 줄에는 N개의 재료들이 가진 고유한 번호들이 공백을 사이에 두고 주어진다.
고유한 번호는 100,000보다 작거나 같은 자연수이다.

6
9
2 7 4 1 5 3
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m,a;
vector<int> v;
// 고유 번호는 최대 100,000+100,000
int main() {
	cin >> n;
	cin >> m;
	int cnt = 0;
	if (m > 200000) {
		cout << 0 << "\n";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	for (int i = 0; i < v.size()-1; i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (v[i] + v[j] == m) cnt++;
		}
	}
	cout << cnt << "\n";
}