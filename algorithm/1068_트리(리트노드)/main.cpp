#include<bits/stdc++.h>
using namespace std;
int n,m,r,root;
vector<int> adj[52];

/// <summary>
/// Ʈ������ ���� ����, �ڽ��� ������ 0�� ��带 ���Ѵ�.
/// Ʈ���� �־����� ��, ��� �ϳ��� ���� ���̴�.
/// �� ��, ���� Ʈ������ ���� ����� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
/// ��带 ����� �� ���� ����� ��� �ڼ��� Ʈ������ ���ŵȴ�.
/// ���� ���, ������ ���� Ʈ���� �ִٰ� ����.
/// ���� ���� ����� ������ 3���̴�. (�ʷϻ� ��ĥ�� ���) �̶�, 1���� �����, 
/// ������ ���� ���Ѵ�. 
/// ���������� ��ĥ�� ��尡 Ʈ������ ���ŵ� ����̴�.
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