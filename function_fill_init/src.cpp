#include <bits/stdc++.h>;

using namespace std;

int main() {
	int v[10];
	for (int i = 10; i >= 1; i--) v[i - 1] = i;
	for (int i : v) cout << i << endl;

	auto an = find(v, v + 10, 100);
	if (an == v + 10) cout << "not found" << endl;

	cout << "return the memory address" << endl;
	cout << an << endl;
	cout << v + 10 << endl;
	cout << v + 9 << endl;

	cout << "access directly" << endl;
	cout << v << endl; // as same as above (literally array reference address)
	cout << *v << endl; // implicitly v[0]
	cout << v[0] << endl;

	fill(v, v + 10, 10);

	printf("%s\n", "fill");
	for (int i : v) cout << i << endl;

	// 초기화 라고하는데 vec0[10] 이 문법이 뭔지 잘 모르겠다.. 참조 주소만 찍히고 메서드 아무것도 안 먹힘..
	vector<int>vec0[10];
	vector<int>vec1(11, 0);

	vector<vector<int>> checked;
	vector<vector<int>> checked1(11 + 1, vector<int>(11 + 1, 0));

	cout << vec0 << endl; // ??

	for (auto a : checked1)
	{
		for (auto b : a)
		{
			// 주석 풀면 오지게 찍힐 듯
			// cout << b << endl;
		}
	}

	int a[5] = { 2,1 };
	printf("%s\n", "0번째를 2로 1번째를 1로 초기화");
	for (int i : a) cout << i << endl;

	int check[5];
	printf("%s\n", "6으로 memory set");
	memset(check, 6, sizeof(check));
	for (int i : check) cout << i << endl;

	/*
	예제 못 알아보겠음
	int dp[10][10];ㄴㄴ

	fill(&dp[0][0], &dp[0][0] + 10 * 10, 10);

	for (auto i : dp) {
		for (auto j : i) {
			cout << j << endl;
		}
	}
	*/

}