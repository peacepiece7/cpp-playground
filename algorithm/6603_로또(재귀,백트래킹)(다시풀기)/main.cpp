/*
https://www.acmicpc.net/problem/6603

예제 입력 1 
7 1 2 3 4 5 6 7
8 1 2 3 5 8 13 21 34
0
예제 출력 1 
1 2 3 4 5 6
1 2 3 4 5 7
1 2 3 4 6 7
1 2 3 5 6 7
1 2 4 5 6 7
1 3 4 5 6 7
2 3 4 5 6 7

1 2 3 5 8 13
1 2 3 5 8 21
1 2 3 5 8 34
1 2 3 5 13 21
1 2 3 5 13 34
1 2 3 5 21 34
1 2 3 8 13 21
1 2 3 8 13 34
1 2 3 8 21 34
1 2 3 13 21 34
1 2 5 8 13 21
1 2 5 8 13 34
1 2 5 8 21 34
1 2 5 13 21 34
1 2 8 13 21 34
1 3 5 8 13 21
1 3 5 8 13 34
1 3 5 8 21 34
1 3 5 13 21 34
1 3 8 13 21 34
1 5 8 13 21 34
2 3 5 8 13 21
2 3 5 8 13 34
2 3 5 8 21 34
2 3 5 13 21 34
2 3 8 13 21 34
2 5 8 13 21 34
3 5 8 13 21 34

*/

#include<bits/stdc++.h>
using namespace std;
int t, n,m;
int s[15];

void go(int start, vector<int> v) {
    if(v.size() == 6) {
        for(auto i : v) cout << i << " ";
        cout << "\n";
        return;
    }
    for(int i = start; i < n; i++) {
        v.push_back(s[i]);
        go(i+1, v);
        v.pop_back();
    }
}

int main() {
    while(true) {
        cin >> n;
        if(n == 0) break;
        for(int i = 0 ; i <n; i++) cin >> s[i];
        vector<int> v;
        go(0, v);
        cout << "\n";
        fill(&s[0], &s[0]+13, 0);
    }
}