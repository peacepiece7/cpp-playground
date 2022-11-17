#include<bits/stdc++.h>
using namespace std;
vector<int> adj[54];
int visited[54];


void postOrder(int here) {
    if(visited[here] == 1) return;
    visited[here] = 1;
    for(int there : adj[here]) {
        postOrder(there);
    };
    cout << here << " ";
}

void preOrder(int here) {
    if(visited[here] == 1) return;
    visited[here] = 1;
    cout << here << " ";
    for(int there : adj[here]) preOrder(there);
}

void inOrder(int here) {
    if(visited[here] == 1) return;
    visited[here] = 1; 
    if(adj[here].size()>=1) inOrder(adj[here][0]);
    cout << here << " ";
    if(adj[here].size()==2) inOrder(adj[here][1]);
}

// 정답 2
void postOrder2(int here){ 
  	if(visited[here] == 0){ 
  		if(adj[here].size() == 1)postOrder(adj[here][0]);
  		if(adj[here].size() == 2){
  			postOrder(adj[here][0]); 
  			postOrder(adj[here][1]);
		}
  		visited[here] = 1; 
  		cout << here << ' ';
	} 
} 
void preOrder2(int here){
  	if(visited[here] == 0){
  		visited[here] = 1; 
  		cout << here << ' ';
  		if(adj[here].size() == 1)preOrder(adj[here][0]);
  		if(adj[here].size() == 2){
  			preOrder(adj[here][0]); 
  			preOrder(adj[here][1]);
		}
	}
}  
void inOrder2(int here){   	
	if(visited[here] == 0){ 
  		if(adj[here].size() == 1){ 
  			inOrder(adj[here][0]); 
	  		visited[here] = 1; 
	  		cout << here << ' ';
		}else if(adj[here].size() == 2){
  			inOrder(adj[here][0]); 
	  		
			visited[here] = 1; 
	  		cout << here << ' ';
  			
			inOrder(adj[here][1]);
		}else{
	  		visited[here] = 1; 
	  		cout << here << ' '; 
		}
	}

} 

int main(){
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[2].push_back(4);
	adj[2].push_back(5); 
	int root = 1;
    cout << "\n 트리순회 : postOrder \n"; // 왼->오->위
    postOrder(root); memset(visited, 0, sizeof(visited));
    cout << "\n 트리순회 : preOrder \n"; // 위->왼->오
    preOrder(root); memset(visited, 0, sizeof(visited)); 
    cout << "\n 트리순회 : inOrder \n"; // 왼->위->오
    inOrder(root); 
    return 0;
} 