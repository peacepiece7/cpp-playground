#include<bits/stdc++.h>
using namespace std;
int t, m, n, k, ret, arr[51][51], visited[51][51];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1,0,-1,0 };

void go(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{	
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (arr[ny][nx] == 1 && !visited[ny][nx]) {
			go(ny, nx);
		}

	} 
}
int main() {
	cin >> t;
	while (t--) {
		ret = 0;
		fill(&arr[0][0], &arr[0][0] + 51 * 51, 0);
		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			int px, py;
			cin >> px >> py;
			arr[py][px] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] && !visited[i][j]) {
					go(i, j);
					ret++;
				}
			}
		}
		cout << ret << "\n";
	}
}