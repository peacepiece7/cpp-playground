#include <bits/stdc++.h>

using namespace std;

vector<int> arr = { 81, 58, 42, 33, 61 };
const int maxWeight = 259;
int answer = 0;
void DFS(int L, int W){
	if (W > maxWeight) return;
	if (L == (arr.size() - 1)) {
		if (answer < W) answer = W;
		cout << "answer :" << answer << endl;
		return;
	};

	DFS(L + 1, (W += arr[L]));
	DFS(L + 1, W);
};

int main() {
	DFS(0, 0);

	cout << answer << endl;
	
	return 0;
}