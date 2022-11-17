#include<bits/stdc++.h>
using namespace std;
vector<int> adj[50];

void print(int here, int there) {
 cout << "here :" << here << " there :" << there << "\n"; 
}

void go(int here) {
    
}

int main() {
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);
    adj[3].push_back(6);
    cout << "recursion\n";
    // write adjection tree using recursion function

    cout << "for loop\n";
    // wrtie adjection tree using for loop
}