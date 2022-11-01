// https://www.acmicpc.net/problem/1189
/*
 3 4 6
 ....
 .T..
 ....
 */
#include<iostream>;
using namespace std;
int visited[6][6], n,m,k,cnt;
const int dy[4] = { 0,1,0,-1 };
const int dx[4] = { 1,0,-1,0 };
char s[6][6];
void print() {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void bfs(int y, int x,int step) {
	if (step == k) {
		if (y == 0 && x == m - 1) {
			cnt++;
		}
		return;
	}
	if (step > k) return;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (s[ny][nx] == 'T' || visited[ny][nx]) continue;
		visited[ny][nx] = 1; // visited[ny][nx] = visited[y][x]+1;·Î ÇØµµ µÊ
		bfs(ny, nx, step+1);
		visited[ny][nx] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> s[i][j];
		}
	}
	visited[n-1][0] = 1;
	bfs(n-1, 0, 1);
	cout << cnt << "\n";
	return 0;
}