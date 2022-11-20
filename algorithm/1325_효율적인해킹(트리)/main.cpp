/*
https://www.acmicpc.net/problem/1325

이 회사의 컴퓨터의 신뢰하는 관계가 주어졌을 때, 
한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 출력하는 프로그램을 작성하시오.

첫째 줄에, N과 M이 들어온다. N은 10,000보다 작거나 같은 자연수, M은 100,000보다 작거나 같은 자연수이다. 
둘째 줄부터 M개의 줄에 신뢰하는 관계가 A B와 같은 형식으로 들어오며, 
"A가 B를 신뢰한다"를 의미한다. 컴퓨터는 1번부터 N번까지 번호가 하나씩 매겨져 있다.

예제 입력 1 
5 4
3 1
3 2
4 3
5 3
예제 출력 1 
1 2

A가 B를 신뢰한다 -> B에서 A로 접근할 수 있다. -> 단방향 간선
*/

#include<bits/stdc++.h>
using namespace std;
int a,b,n,m,mx;
int cptrs[10004];
vector<int> adj[10004];
// vector<int> adj[10004]; // 총 n개(최대 10,000개)줄이 들어옴

int go(int here, int cnt) {
    for(auto there : adj[here]) {
        cnt = go(there, cnt+1);
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0 ; i < m; i++) {
        cin >> a >> b;
        adj[b].push_back(a); // A가 B를 신뢰한다 -> B에서 A로 접근할 수 있다. -> 단방향 간선
    }
    for(int i = 1; i <= m; i++) {
        if(adj[i].size()) {
            cptrs[i] = go(i, 1);
            mx = max(cptrs[i], mx);
        }
    }
    // sort(cptrs.begin(), cptrs.end(), cmp);
    for(int i = 1; i <= m; i++) if(cptrs[i] == mx) cout << i << " "; 
    return 0;
}

