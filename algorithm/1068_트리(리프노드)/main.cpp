/*
https://www.acmicpc.net/problem/1068

입력
첫째 줄에 트리의 노드의 개수 N이 주어진다. N은 50보다 작거나 같은 자연수이다. 
둘째 줄에는 0번 노드부터 N-1번 노드까지, 각 노드의 부모가 주어진다. 
만약 부모가 없다면 (루트) -1이 주어진다. 셋째 줄에는 지울 노드의 번호가 주어진다.

출력
첫째 줄에 입력으로 주어진 트리에서 입력으로 주어진 노드를 지웠을 때, 리프 노드의 개수를 출력한다.
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,r,root;
vector<int> adj[52];

// int dfsp(int here) {
// 	int cnt = 0;
// 	int child = 0;
// 	for (auto there : adj[here]) {
// 		if (there == r) continue;
// 		cnt = dfsp(there);
// 		child++;
// 	}
// 	if (child == 0) return 1;
// 	return cnt;
// }

// int mainp() {
// 	cin >> n;
// 	for (int i = 0; i <= n; i++) {
// 		cin >> m;
// 		if (m == -1) {
// 			root = 1;
// 		}
// 		else adj[i].push_back(m);
// 	}
// 	cin >> r;
// 	dfsp(root);
// }

#include<bits/stdc++.h>
using namespace std;
int n, m, r, root;
vector<int> adj[54];

int dfs(int here)
{
    int ret = 0;
    int child = 0;
    for(int there : adj[here])
    {
        if(there == r) continue;
        ret += dfs(there);
        child++;
    } 
    if(child == 0) return 1;
    return ret;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> m;
        if(m == -1) {
            root = i;
        }else adj[m].push_back(i);
    }
    cin >> r;
    if(r == root) {
        cout << 0 << "\n";
        return 0;
    }
    cout << dfs(root) << "\n";
    return 0;
}