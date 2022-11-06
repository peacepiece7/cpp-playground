/*
첫째 줄에 듣도 못한 사람의 수 N, 보도 못한 사람의 수 M이 주어진다. 이어서 둘째 줄부터 N개의 줄에 걸쳐 듣도 못한 사람의 이름과, N+2째 줄부터 보도 못한 사람의 이름이 순서대로 주어진다. 이름은 띄어쓰기 없이 알파벳 소문자로만 이루어지며, 그 길이는 20 이하이다. N, M은 500,000 이하의 자연수이다.

듣도 못한 사람의 명단에는 중복되는 이름이 없으며, 보도 못한 사람의 명단도 마찬가지이다.

출력
듣보잡의 수와 그 명단을 사전순으로 출력한다.


3 4
ohhenrie
charlie
baesangwook
obama
baesangwook
ohhenrie
clinton

2
baesangwook
ohhenrie
*/

#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
map<string, int> mp;
vector<string> v;
int n, m, cnt;
string x, y;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x;
        mp[x]++;
    }
    for (int i = 0; i < m; i++) {
        cin >> y;
        if (mp[y]) {
            v.push_back(y);
            cnt++;
        }
    }
    sort(v.begin(), v.end());
    cout << cnt << "\n";
    for (string i : v) cout << i << "\n";
    return 0;
}

