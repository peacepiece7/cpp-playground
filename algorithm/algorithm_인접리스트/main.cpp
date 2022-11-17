#include<bits/stdc++.h>
using namespace std;
vector<int> adj[50];

void go(int here) {
    for(auto there : adj[here]) {
        cout << "here :" << here << " there :" << there << "\n"; 
        go(there);
    }
}

int main() {
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);
    adj[3].push_back(6);
    cout << "recursion\n";
    go(1);

    cout << "for loop\n";
    for(int i = 1; i <= 3; i++) {
        for(int j = 0; j < adj[i].size();j++) {
        int there = adj[i][j];
        cout << "i :" << i << " there :" << there  << "\n";
        }
    }

}