/* �������� bfs ����
https://www.acmicpc.net/submit/2178/46570168

����
N��Mũ���� �迭�� ǥ���Ǵ� �̷ΰ� �ִ�.
1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
�̷ο��� 1�� �̵��� �� �ִ� ĭ�� ��Ÿ����, 0�� �̵��� �� ���� ĭ�� ��Ÿ����. �̷��� �̷ΰ� �־����� ��, (1, 1)���� ����Ͽ� (N, M)�� ��ġ�� �̵��� �� ������ �ϴ� �ּ��� ĭ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. �� ĭ���� �ٸ� ĭ���� �̵��� ��, ���� ������ ĭ���θ� �̵��� �� �ִ�.

���� �������� 15ĭ�� ������ (N, M)�� ��ġ�� �̵��� �� �ִ�. ĭ�� �� ������ ���� ��ġ�� ���� ��ġ�� �����Ѵ�.

�Է�
ù° �ٿ� �� ���� N, M(2 �� N, M �� 100)�� �־�����. ���� N���� �ٿ��� M���� ������ �̷ΰ� �־�����. ������ ������ �پ �Է����� �־�����.

���
ù° �ٿ� ������ �ϴ� �ּ��� ĭ ���� ����Ѵ�. �׻� ������ġ�� �̵��� �� �ִ� ��츸 �Է����� �־�����.

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