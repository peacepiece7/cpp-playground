/*
https://www.acmicpc.net/problem/2529

- 문제 참고

예제 입력 1 
2
< >
예제 출력 1 
897
021
예제 입력 2 
9
> < < < > > > < <
예제 출력 2 
9567843012
1023765489
*/

// 10개중 n개를 뽑는 경우 (순서 상관 있음)

#include<bits/stdc++.h>
using namespace std;
int n, check[10];
char ops[10];
string s;
vector<string> rets;

bool compareOps(char a, char b, char op) {
    if(op == '>' && a > b) return true;
    else if(op == '<' && a < b) return true;
    return false;
}

void dfs(int pos, string nums) {
    // cout << nums << "\n";
    if(nums.size() == n+1) {
        rets.push_back(nums);
        return;
    }
    for(int i = 0 ; i <= 9; i++) {
        if(check[i]) continue;
        if(nums.size()) {
            if(!compareOps(nums[pos-1], i+'0', ops[pos-1])) continue;
        } 
        check[i] = 1;
        dfs(pos+1, nums + (char)(i+'0')) ;
        check[i] = 0;
    }
}


int main() {
    cin >> n;
    for(int i = 0 ; i < n; i++) cin >> ops[i];
    dfs(0,"");
    for(auto i : rets) cout << i << "\n";
    return 0; 
}