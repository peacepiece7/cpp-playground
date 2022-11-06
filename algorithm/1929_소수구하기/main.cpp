/*
문제
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1, 000, 000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.

출력
한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.

3 16

3
5
7
11
13

*/

#include<iostream>
#include<vector>
using namespace std;
int n, m;
int che[1000004];
vector<int> v;

void era(int min_n, int max_n) {
	for (int i = 2; i <= max_n; i++) {
		if (che[i]) continue;
		for (int j = i*2; j <= max_n; j += i) {
			che[j] = 1;
		}
	}
	for (int i = 2; i <= max_n; i++) {
		if (che[i] == 0) v.push_back(i);
	}
}

int main() {
	cin >> n >> m;
	era(n, m);
	for (auto i : v) {
		if (i >= n) cout << i << "\n";
	}
	return 0;
}



