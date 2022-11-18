// https://www.acmicpc.net/problem/1068
/*
9
-1 0 0 2 2 4 4 6 6
4
*/

#include<bits/stdc++.h>
using namespace std;
int n,m, r;
vector<int>adj[54];

int go(int here) {
    if(here == r) return 1;
    if(adj[here].size() == 0) return 1;
    int child = 0;
    for(auto there : adj[here]) {  
        child += go(there);
    }
    return child;
}

int main() {
    cin >> n;
    int root;
    for(int i = 0; i < n ; i++) {
        cin >> m;
        if(m==-1) root=i;
        else adj[m].push_back(i);
    }
    if(root==0) {
        cout << 1 << "\n";
        return 0;
    }
    int leafnode = go(root);
    cout << leafnode << "\n";
}