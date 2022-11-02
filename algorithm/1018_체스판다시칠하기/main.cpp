#pragma warning(disable:4996)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
const int INF = 987654321;
int n, m, che[54][54], ret = INF;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };

// 1. wbwb, bwb 배열 미리 만들어서 브루트 포스해보기
// 2. wbwb, bwbw를 두 가지 경우의 수를 생각해서 풀어야 함

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		char s[54];
		scanf("%s", s);
		for (int j = 0; j < strlen(s); j++) {
			if (s[j] == 'B') che[i][j] = 0;
			else che[i][j] = 1;
		}
	}
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 7 < n && j + 7 < m) v.push_back({ i,j });
		}
	}
	for (pair<int, int> p : v) {
		int cnt = 0;
		int temp[54][54];
		copy(&che[0][0], &che[0][0] + 54 * 54, &temp[0][0]);
		if (temp[p.first][p.second] == 1) {
			temp[p.first][p.second] = 0;
			cnt++;
		}
		for (int i = p.first; i < p.first + 8; i++)
		{
			for (int j = p.second; j < p.second + 8; j++) {
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny < p.first || nx < p.second || ny >= p.first + 8 || nx >= p.second + 8) continue;
					if (temp[i][j] == temp[ny][nx]) {
						temp[ny][nx] = abs(temp[ny][nx] - 1);
						cnt++;

					}
					if (cnt > ret) break;
				}
				if (cnt > ret) break;
			}
		}
		ret = min(ret, cnt);

		cnt = 0;
		copy(&che[0][0], &che[0][0] + 54 * 54, &temp[0][0]);
		if (temp[p.first][p.second] == 0) {
			temp[p.first][p.second] = 1;
			cnt++;
		}
		for (int i = p.first; i < p.first + 8; i++) {
			for (int j = p.second; j < p.second + 8; j++) {
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny < p.first || nx < p.second || ny >= p.first + 8 || nx >= p.second + 8) continue;
					if (temp[i][j] == temp[ny][nx]) {
						temp[ny][nx] = abs(temp[ny][nx] - 1);
						cnt++;
					}
					if (cnt > ret) break;
				}
				if (cnt > ret) break;
			}
		}
		ret = min(ret, cnt);
	}
	printf("%d", ret);
	return 0;
}