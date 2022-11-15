/*
https://www.acmicpc.net/problem/2636

입력
첫째 줄에는 사각형 모양 판의 세로와 가로의 길이가 양의 정수로 주어진다. 세로와 가로의 길이는 최대 100이다. 판의 각 가로줄의 모양이 윗 줄부터 차례로 둘째 줄부터 마지막 줄까지 주어진다. 치즈가 없는 칸은 0, 치즈가 있는 칸은 1로 주어지며 각 숫자 사이에는 빈칸이 하나씩 있다.

출력
첫째 줄에는 치즈가 모두 녹아서 없어지는 데 걸리는 시간을 출력하고, 둘째 줄에는 모두 녹기 한 시간 전에 남아있는 치즈조각이 놓여 있는 칸의 개수를 출력한다.

예제 입력 1 
13 12
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 1 0 0 0
0 1 1 1 0 0 0 1 1 0 0 0
0 1 1 1 1 1 1 0 0 0 0 0
0 1 1 1 1 1 0 1 1 0 0 0
0 1 1 1 1 0 0 1 1 0 0 0
0 0 1 1 0 0 0 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
예제 출력 1 
3
5
*/
#include <bits/stdc++.h>
using namespace std;

int a[104][104], visited[104][104];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int n, m, cnt, cnt2;
vector <pair<int, int>> v;

void go(int y, int x)
{
    if (a[y][x] == 1)
    {
        v.push_back({ y,x });
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        go(ny, nx);
    }
}

int main()
{
    cnt = 0;
    cnt2 = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    while (true)
    {
        cnt2 = 0;
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        v.clear();

        // visited[0][0] = 1;
        go(0, 0);
        for (auto b : v) if (a[b.first][b.second] == 1) cnt2++;
        for (auto b : v) a[b.first][b.second] = 0;

        cnt++;
        bool flag = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] != 0) flag = 1;
            }
        }
        if (!flag) break;
    }
    cout << cnt << "\n";
    cout << cnt2 << "\n";
    return 0;
}