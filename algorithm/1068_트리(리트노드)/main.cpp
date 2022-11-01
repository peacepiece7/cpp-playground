#include<bits/stdc++.h>
using namespace std;
int n,m,r,root;
vector<int> adj[52];

/// <summary>
/// 트리에서 리프 노드란, 자식의 개수가 0인 노드를 말한다.
/// 트리가 주어졌을 때, 노드 하나를 지울 것이다.
/// 그 때, 남은 트리에서 리프 노드의 개수를 구하는 프로그램을 작성하시오.
/// 노드를 지우면 그 노드와 노드의 모든 자손이 트리에서 제거된다.
/// 예를 들어, 다음과 같은 트리가 있다고 하자.
/// 현재 리프 노드의 개수는 3개이다. (초록색 색칠된 노드) 이때, 1번을 지우면, 
/// 다음과 같이 변한다. 
/// 검정색으로 색칠된 노드가 트리에서 제거된 노드이다.
/// </summary>

int dfsp(int here) {
	int cnt = 0;
	int child = 0;
	for (auto there : adj[here]) {
		if (there == r) continue;
		cnt = dfsp(there);
		child++;
	}
	if (child == 0) return 1;
	return cnt;
}

int mainp() {
	cin >> n;
	for (int i = 0; i <= n; i++) {
		cin >> m;
		if (m == -1) {
			root = 1;
		}
		else adj[i].push_back(m);
	}
	cin >> r;
	dfsp(root);
}


int dfs(int here) {
	int ret = 0;
	int child = 0;
	for (int there : adj[here]) {
		if (there == r) continue;
		ret += dfs(there);
		child++;
	}
	if (child == 0) return 1;
	return ret;
}
int main() {
	cin >> n;

	for (int i = 0; i <= n; i++) {
		cin >> m;
		if (m == -1) {
			root = 1;
		} else adj[m].push_back(m);
	}
	cin >> r;
	if (r == root) cout << 0 << "\n";
	else {
		cout << dfs(root) << "\n";
	}
	return 0;
}