/*
https://www.acmicpc.net/problem/2234

7 4
11 6 11 6 3 10 6
7 9 6 13 5 15 5
1 10 12 7 13 7 5
13 11 10 8 10 12 13

5
9
16
*/



/*
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
const int dy[4] = { 0,-1,0,1 }; // 서(1), 북(2), 동(4), 남(8)  
const int dx[4] = { -1,0,1,0};
int visited[54][54], arr[54][54], area[54][54], n, m, room, biggestSize;

int bfs(int y, int x) {
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ y,x });
	while (q.size()) {
		tie( y,x ) = q.front();
		visited[y][x] = room;
		cnt++;
		q.pop();
		// 1 2 4 8
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
			if (!(arr[y][x] & (1 << i))) {
				q.push({ ny,nx });
			}
		}
	}
	return cnt;
}

void print() {
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				room++;
				int size = bfs(i, j);
				biggestSize = max(size, biggestSize);
			}
		}
	}
	print();
}
*/