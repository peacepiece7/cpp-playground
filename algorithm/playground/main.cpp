#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int arr[14];
void combi(int start, int r, vector<int>v) {
    if (v.size() == r) {
        for (auto i : v) cout << i << " ";
        cout << "\n";
        return;
    }
    for (int i = start + 1; i < n; i++) {
        v.push_back(arr[i]);
        combi(i, r, v);
        v.pop_back();
    }
}

int main() {
    while (true) {
        cin >> n;
        if (!n) break;
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; i++)  cin >> arr[i];
        sort(arr, arr + n);
        vector<int> temp;
        combi(-1, 6, temp);
    }
}
/*
const int INF = 987654321;
int arr[11][11], visited[11][11], n, ret = INF;
const int dy[4] = { 0,1,0,-1 };
const int dx[4] = { 1,0,-1,0 };

bool isTravelDone(int y, int x) {
    for (int i = 0; i < 4; i++) {
        if ((dy[i] + y) == 0 && (dx[i] + x) == n - 1) return true;
    }
    return false;
}
void go(int y, int x, int sum) {
    if (isTravelDone(y, x)) {
        ret = min(ret, sum);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (!arr[ny][nx] || visited[ny][nx]) continue;

        go(ny, nx, sum + arr[ny][nx]);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    int sx = 0;
    int sy = n - 1;
    visited[sy][sx] = 1;
    int sum = arr[sy][sx];
    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + sy;
        int nx = dx[i] + sx;
        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        go(ny, nx, sum + arr[ny][nx]);
    }
    std::cout << ret << "\n";
}
*/
