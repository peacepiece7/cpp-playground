#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void DFS(int L) {
	if (L <= 0) return;

	DFS(L - 1);
	cout << L << endl;

}

vector<int> answer;
void DFS2(int L) {
	if (L <= 0) return;
	cout << L / 2 << endl;
	DFS2(L / 2);
	answer.push_back(static_cast<int>(L % 2));
}

void DFS3(int L) {
	if (L >= 8) return;

	cout << L << endl;
	DFS3(L * 2);
	DFS3(L * 2 + 1);

}

vector<int> arr{ 1, 2, 3 };


void DFS4(vector<int> ch, int L, int input) {
	if (L == input) {
		vector<int> answer1(3);
		for (int i = 0; i < ch.size(); ++i) {
			if (ch[i]) {
				answer1[i] = arr[i];
			}
		}
		for (int i : answer1) {
			if (i) cout << i << " ";
		}
		cout << endl;
		return;
	}
	ch[L] = 1;
	DFS4(ch, L + 1, input);
	ch[L] = 0;
	DFS4(ch, L + 1, input);
}

int main() {
//	{
//		DFS(3);
//		return 0;
//	}

// {
//	DFS2(17);
//		for (int i : answer) cout << i << " ";
//		return 0;
//	}

// {
// DFS3(1);
//	return 0;
//	}

	{
		vector<int> ch{ 0,0,0 };
		DFS4(ch, 0, 3);
		return 0;
	}

}