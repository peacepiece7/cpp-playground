/*
https://www.acmicpc.net/submit/2583/46581388

- bfs, 영역의 좌표를 2차원 배열로 옮기는게 포인트

입력
첫째 줄에 M과 N, 그리고 K가 빈칸을 사이에 두고 차례로 주어진다. M, N, K는 모두 100 이하의 자연수이다.
 둘째 줄부터 K개의 줄에는 한 줄에 하나씩 직사각형의 왼쪽 아래 꼭짓점의 x, y좌표값과 오른쪽 위 꼭짓점의 x, y좌표값이 빈칸을 사이에 두고 차례로 주어진다. 모눈종이의 왼쪽 아래 꼭짓점의 좌표는 (0,0)이고, 오른쪽 위 꼭짓점의 좌표는(N,M)이다. 입력되는 K개의 직사각형들이 모눈종이 전체를 채우는 경우는 없다.

출력
첫째 줄에 분리되어 나누어지는 영역의 개수를 출력한다. 둘째 줄에는 각 영역의 넓이를 오름차순으로 정렬하여 빈칸을 사이에 두고 출력한다.

예제 입력 1 
5 7 3
0 2 4 4
1 1 2 5
4 0 6 2
예제 출력 1 
3
1 7 13

*/

#include<bits/stdc++.h>
using namespace std;
int m, n, k, e[101][101], visited[101][101], ret , tmpSize;
vector<int> areaSize;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };


void BFS(int y, int x)
{
	visited[y][x] = 1;
	tmpSize++;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
		if (visited[ny][nx] || e[ny][nx] == 1) continue;
		BFS(ny, nx);
	}
	return;
}

int main()
{
	cin >> m >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int lbx, lby, rtx, rty;
		cin >> lbx >> lby >> rtx >> rty;

		for (int b = lbx; b < rtx; b++)
		{
			for (int c = lby; c < rty; c++) e[c][b] = 1;
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (e[i][j] == 0 && !visited[i][j])
			{
				BFS(i, j);
				ret++;
				areaSize.push_back(tmpSize);
				tmpSize = 0;
			}
		}
	}
	cout << ret << "\n";
	sort(areaSize.begin(), areaSize.end(), less <int>());
	for (int s : areaSize) cout << s << " ";
	return 0;
}