/*
��Ŀ �������� �� �˷��� ��� ȸ�縦 ��ŷ�Ϸ��� �Ѵ�. �� ȸ��� N���� ��ǻ�ͷ� �̷���� �ִ�. �������� ������ ������, �� ���� ��ŷ���� ���� ���� ��ǻ�͸� ��ŷ �� �� �ִ� ��ǻ�͸� ��ŷ�Ϸ��� �Ѵ�.
�� ȸ���� ��ǻ�ʹ� �ŷ��ϴ� �����, �ŷ����� �ʴ� ����� �̷���� �ִµ�, A�� B�� �ŷ��ϴ� ��쿡�� B�� ��ŷ�ϸ�, A�� ��ŷ�� �� �ִٴ� �Ҹ���.
�� ȸ���� ��ǻ���� �ŷ��ϴ� ���谡 �־����� ��, �� ���� ���� ���� ��ǻ�͸� ��ŷ�� �� �ִ� ��ǻ���� ��ȣ�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
ù° �ٿ�, N�� M�� ���´�. N�� 10,000���� �۰ų� ���� �ڿ���, M�� 100,000���� �۰ų� ���� �ڿ����̴�.
��° �ٺ��� M���� �ٿ� �ŷ��ϴ� ���谡 A B�� ���� �������� ������, "A�� B�� �ŷ��Ѵ�"�� �ǹ��Ѵ�.
��ǻ�ʹ� 1������ N������ ��ȣ�� �ϳ��� �Ű��� �ִ�.
5 4
3 1
3 2
4 3
5 3
*/
// a�� b�� �ŷ��Ѵ� -> b���� a�� �� �� �ִ�.

#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10004];
int visited[10004], ret[10004], maxVal;
int n, m, a, b;

int go(int here) {
	int cnt = 1;
	visited[here] = 1;
	for (auto there : adj[here]) {
		if (visited[there]) continue;
		cnt += go(there);
	}
	return cnt;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		// adj[x].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		ret[i] = go(i);
		maxVal = max(ret[i], maxVal);
	}

	for (int i = 1; i < sizeof(ret) / sizeof(int); i++) {
		if (ret[i] == maxVal) cout << i << " ";
	}
	return 0;
}