// https://www.acmicpc.net/problem/1068
/*
예제 입력 1 
5
-1 0 0 1 1
2
예제 출력 1 
2

예제 입력 2 
5
-1 0 0 1 1
1
예제 출력 2 
1

예제 입력 3 
5
-1 0 0 1 1
0
예제 출력 3 
0

예제 입력 4 
9
-1 0 0 2 2 4 4 6 6
4
예제 출력 4
2

- 예제 4번이 아래와 같은 느낌
    0
   1  2
     3  4
       5  6
         7  8


- 아래와 같이 작성하면 leaf node는 1개
9
-1 0 1 1 2 2 4 4 5 5
1

1

            0
         1
      2     3
    4   5
  6  7 8  9    

- 루트가 없을 경우?
*/

#include<bits/stdc++.h>
using namespace std;
int n,m,r;
vector<int> adj[54];

int go(int here) {
    int leaf = 0;
    int child = 0;
    for(auto there : adj[here]) {
        if(there == r) continue;
        leaf += go(there);
        child++;
    }
    if(child == 0) return 1;
    else return leaf;
}

int main() {
    cin >> n;
    int root=0;
    for(int i=0; i < n; i++) {
        cin >> m;
        if(m == -1) root=i;
        else adj[m].push_back(i);
    }
    cin >> r;
    // if(r == root) cout << 0 << "\n";
    // else 
    cout << go(root) << "\n";
}