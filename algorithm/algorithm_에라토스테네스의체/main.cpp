#include<iostream>
#include<vector>
using namespace std;
int che[101];
// 보통  최댓값이 10^5이하면 에라토스 테네스의 체 사용하고 넘으면 일일이 체크
vector<int> era(int mx_n) {
	vector<int> v;
	// 거름망 만드는 코드
	for (int i = 2; i <= mx_n; i++) {
		if (che[i]) continue;
		for (int j = 2 * i; j <= mx_n; j += i) {
			che[j] = 1;
		}
	}
	for (int i = 2; i <= mx_n; i++) if(che[i] == 0)  v.push_back(i);
	return v;
}

bool check(int n) {
	if (n <= 1) return 0;
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}
int main() {
	for (int i = 1; i <= 20; i ++ ) {
		if (check(i)) cout << i << "는 소수" << '\n';
	}
	vector<int> pnums = era(100);
	for (auto i : pnums) {
		cout << i << " ";
	}
	cout  << "\n";
	for (int i : che) { cout << i << " "; } // 이게 왜 오버플로우가 안나는지 모르겠음 ㅎ; che배열의 사이즈는 항상 입력 최댓값 + 2정도 해주자
}