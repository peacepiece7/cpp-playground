#include<bits/stdc++.h>
using namespace std;
int a,b,n,m,mx;
int cptrs[10004], visited[10004];
vector<int> adj[10004];

int go(int here, int cnt)
{
    visited[here] = 1;
	for (int there : adj[here]) if(!visited[there])  cnt = go(there, cnt+1);
	return cnt;
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0 ; i < m; i++) {
        cin >> a >> b;
        adj[b].push_back(a); 
    }
    for(int i = 1; i <= n; i++) {
        if(adj[i].size()) {
            memset(visited, 0, sizeof(visited));
            cptrs[i] = go(i, 1);
            mx = max(cptrs[i], mx);
        }
    }
    // sort(cptrs.begin(), cptrs.end(), cmp);
    for(int i = 1; i <= n; i++) if(cptrs[i] == mx) cout << i << " "; 
    return 0;
}