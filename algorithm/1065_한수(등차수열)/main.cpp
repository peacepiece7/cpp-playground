#include<iostream>
#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

/// <summary>
/// 어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다. 
/// 등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다.
/// N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오. 
/// </summary>
struct CoupleElements {
	int s;
	int lt;
	int rt;
	int sum() {
		return lt - rt;
	}
	int remainder() {
		return s / 10;
	}
};

int main() {
	fastio;
	int n, cnt = 0;
	CoupleElements ce;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i < 100) {
			cnt++;
			continue;
		}
		bool f = true;
		ce = { i, i % 10, (i / 10) % 10 };
		int prev = ce.sum();
		int tmp = ce.remainder();
		while (tmp / 10) {
			ce = { tmp, tmp % 10, (tmp / 10) % tmp };
			int cur = ce.sum();
			tmp = ce.remainder();
			if (prev != cur) {
				f = false;
				break;
			}
			prev = cur;
		}
		if (f) cnt++;
	}
	std::cout << cnt << "\n";
}