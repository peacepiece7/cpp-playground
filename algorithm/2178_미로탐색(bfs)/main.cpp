/* 전형적인 bfs 기초
https://www.acmicpc.net/submit/2178/46570168

문제
N×M크기의 배열로 표현되는 미로가 있다.
1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

입력
첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

출력
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.

input
4 6
101111
101010
101011
111011

output
15


input
4 6
110110
110110
111111
111101

output
9

input
2 25
1011101110111011101110111
1110111011101110111011101

output
38


*/

#pragma warning (disable : 4996)
#include <bits/stdc++.h>
using namespace std;
long long n, m;
int arr[104][104], visited[104][104];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void DFS(int y, int x)
{
	queue<pair<int, int>> q;
	// visited[0][0] = 1;
	q.push({ y,x });
	while (q.size())
	{
		tie(y, x) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx > m || arr[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny,nx });
		}
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%1d", &arr[i][j]);

	visited[0][0] = 1; // start point (0,0)
	DFS(0, 0);
	cout << visited[n - 1][m - 1] << "\n";
	return 0;
}