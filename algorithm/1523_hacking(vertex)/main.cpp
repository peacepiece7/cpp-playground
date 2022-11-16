/*
해커 김지민은 잘 알려진 어느 회사를 해킹하려고 한다. 이 회사는 N개의 컴퓨터로 이루어져 있다. 김지민은 귀찮기 때문에, 한 번의 해킹으로 여러 개의 컴퓨터를 해킹 할 수 있는 컴퓨터를 해킹하려고 한다.
이 회사의 컴퓨터는 신뢰하는 관계와, 신뢰하지 않는 관계로 이루어져 있는데, A가 B를 신뢰하는 경우에는 B를 해킹하면, A도 해킹할 수 있다는 소리다.
이 회사의 컴퓨터의 신뢰하는 관계가 주어졌을 때, 한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 출력하는 프로그램을 작성하시오.
첫째 줄에, N과 M이 들어온다. N은 10,000보다 작거나 같은 자연수, M은 100,000보다 작거나 같은 자연수이다.
둘째 줄부터 M개의 줄에 신뢰하는 관계가 A B와 같은 형식으로 들어오며, "A가 B를 신뢰한다"를 의미한다.
컴퓨터는 1번부터 N번까지 번호가 하나씩 매겨져 있다.
5 4
3 1
3 2
4 3
5 3
*/
// a가 b를 신뢰한다 -> b에서 a로 갈 수 있다.

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