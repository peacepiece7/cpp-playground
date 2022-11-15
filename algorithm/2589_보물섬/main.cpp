/*

https://www.acmicpc.net/problem/2589


- L마다 bfs를 돌아서 가장 오래 걸리는 시간을 찾음

- 다른 답안?
L을 찾으면 bfs를 돌고 가장 멀리 떨어진 위치를 찾음. (멀리 떨어진 위치는 두 곳 혹은 한 곳임)
그 중 하나에서 bfs를 다시 돌아서 가장 먼 거리를 찾음, 
같은 방법으로 다른 섬을 돌아 모든 섬 중가장 먼 거리를 찾음
각 섬마다 bfs 2번으로 끝낼 수 있음

예제 입력 1 
5 7
WLLWWWL
LLLWLLL
LWLWLWW
LWLWLLL
WLLWLWW

예제 출력 1 
8
*/

#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int arr[54][54], visited[54][54], n, m, ret;
string s;
void bfs(int y, int x){
	queue<pair<int, int>> q;
	q.push({y,x});
	while (q.size()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (arr[ny][nx] == 1 || visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			ret = max(visited[ny][nx], ret);
			q.push({ ny,nx });
		}
	}
	return;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
    cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++){
			if (s[j] == 'W') arr[i][j] = 1;
			else arr[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) continue;
			memset(visited, 0, sizeof(visited));
			visited[i][j] = 1;
			bfs(i, j);
		}
	}
	cout << ret -1 << "\n";
	return 0;
}