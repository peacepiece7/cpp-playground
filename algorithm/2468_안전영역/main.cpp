/*
https://www.acmicpc.net/problem/2468
안전영역 구하기 

브루트 포스 + bfs의 간단한 문제

5
6 8 2 6 2
3 2 3 4 6
6 7 3 3 2
7 2 5 3 6
8 9 5 2 7

*/


#include<bits/stdc++.h>
using namespace std;
int arr[104][104], visited[104][104];
int top;
int n,ret;
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};

int bfs(int y, int x, int limit) {
    visited[y][x] = 1;
    queue<pair<int,int>> q;
    q.push({y,x});
    int cnt = 0;
    while(q.size()) {
        cnt++;
        tie(y,x) = q.front();
        q.pop();
        for(int i = 0 ; i < 4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if(arr[ny][nx] <= limit || visited[ny][nx]) continue;
            visited[ny][nx] = 1;
            q.push({ny,nx});
        }
    }
    return 1;
} 

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i = 0 ; i< n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cin >> arr[i][j];
            top = max(top, arr[i][j]);
        }
    }
    
    for(int t = 0; t <= top; t++) {
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        int cnt = 0;
        for(int i = 0 ; i < n; i++) {
            for(int j = 0 ; j < n; j++) {
                if(!visited[i][j] && arr[i][j] > t) {
                    cnt += bfs(i,j,t);
                }
            }
        }
        ret = max(ret, cnt);
    }
    cout << ret << "\n";
    return 0;
}