/*
https://www.acmicpc.net/problem/9934

왼쪽 그림에 나와있는 마을이라면, 상근이는 2-1-3 순서대로 빌딩을 들어갔을 것이고, 오른쪽 그림의 경우에는 1-6-4-3-5-2-7 순서로 들어갔을 것이다. 
상근이가 종이에 적은 순서가 모두 주어졌을 때, 
각 레벨에 있는 빌딩의 번호를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 K (1 ≤ K ≤ 10)가 주어진다.

둘째 줄에는 상근이가 방문한 빌딩의 번호가 들어간 순서대로 주어진다. 모든 빌딩의 번호는 중복되지 않으며, 구간 [1,2K)에 포함된다.

출력
총 K개의 줄에 걸쳐서 정답을 출력한다. i번째 줄에는 레벨이 i인 빌딩의 번호를 출력한다. 출력은 왼쪽에서부터 오른쪽 순서대로 출력한다.

예제 입력 1 
2
2 1 3
예제 출력 1 
1
2 3
예제 입력 2 
3
1 6 4 3 5 2 7
예제 출력 2 
3
6 2
1 4 5 7
*/

#include<iostream>
#include<vector>
#include<queue>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
using namespace std;
int n,m;
vector<int> v;
vector<int> adj[12];

void go(int here) {
    for(int i = 0; i < adj[here].size(); i++) {
        if(adj[here].size() <= 1) go(adj[here][0]);
        v.push_back(adj[here][0]);
        if(adj[here].size() == 2) go(adj[here][1]);
        v.push_back(adj[here][1]);
    }
}

int main() {
    // inorder
    cin >> n;
    cin >> m;
    adj[0].push_back(m);
    int node = 1;
    for(int i = 1 ; i < n ; i++) {
        if(i%2 == 0) node++;
        cin >> m;
        adj[i].push_back(m);
    }
    go(0);

    for(int i = 0 ; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    int idx = 1;
    //    while(true) {
    //     for(int i = 1; i <= idx ; i++) {
    //         if(q.empty()) break;
    //         cout << q.front() << ' ';
    //         q.pop();
    //     }
    //     idx *= 2;
    //     if(q.empty()) break;
    // }
    return 0;
}