#include<bits/stdc++.h>
using namespace std;
vector<int> adj[54];
int visited[54];

// 정답 1 visited를 제외하고 만들어보세요
void postOrder(int here) {
}

void preOrder(int here) {
}

void inOrder(int here) {
}

// 정답 2 교안대로 visited를 포함하여 만들어보세요
void postOrder2(int here){ 
} 
void preOrder2(int here){
}  
void inOrder2(int here){   	
} 

int main(){
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[2].push_back(4);
	adj[2].push_back(5); 
	int root = 1;
    cout << "\n 트리순회 : postOrder \n"; // ?->?->?
    postOrder(root); memset(visited, 0, sizeof(visited));
    cout << "\n 트리순회 : preOrder \n"; // ?->?->?
    preOrder(root); memset(visited, 0, sizeof(visited)); 
    cout << "\n 트리순회 : inOrder \n"; // ?->?->?
    inOrder(root); 
    return 0;
} 