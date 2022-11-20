#include<bits/stdc++.h>
using namespace std;
int n, arr[15];

void print(vector<int> v) {
    for(auto i : v) cout << i << " ";
    cout << "\n";
}

void go(int start, vector<int> v) {
    if(v.size() == 6) {
        print(v);
        return;
    }

    for(int i = start; i < n; i++) {
        v.push_back(arr[i]);
        go(i+1, v);
        v.pop_back();
    }
}

int main() {
    while(true) {
        cin >> n;
        if(n == 0) break;
        memset(arr, 0, sizeof(arr));
        for(int i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        vector<int> temp;
        go(0, temp);
    }
}