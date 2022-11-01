/*
https://www.acmicpc.net/problem/1269

A = { 1, 2, 4 } 이고, B = { 2, 3, 4, 5, 6 } 라고 할 때,  A-B = { 1 } 이고, B-A = { 3, 5, 6 } 이므로, 대칭 차집합의 원소의 개수는 1 + 3 = 4개이다.
집합의 원소의 개수는 200,000을 넘지 않으며, 모든 원소의 값은 100,000,000을 넘지 않는다.
3 5
1 2 4
2 3 4 5 6
*/
#include<iostream>
#include<map>
#include<vector>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
using namespace std;
map<int,int> a;
map<int,int> b;
map<int,bool> mp;
vector<int> v;
int n, m,x, cnt;

/*
내가 푼 건데 느림
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++) {
        cin >> x;
        a[x]++;
        v.push_back(x);
    }
    for(int i = 0; i < m; i++) {
        cin >> x;
        if(!a[x]) cnt++;
        b[x]++;
    }
    for(auto i : v) if(!b[i]) cnt++;
    cout << cnt << "\n";
}
*/


int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n+m; i++) {
        cin >> x;
        if(mp[x] == true) {
            mp.erase(x);
        }else mp[x] = true;
    }
    cout << mp.size() << "\n";
}