#include<iostream>
#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

/// <summary>
/// � ���� ���� X�� �� �ڸ��� ���������� �̷�ٸ�, �� ���� �Ѽ���� �Ѵ�. 
/// ���������� ���ӵ� �� ���� ���� ���̰� ������ ������ ���Ѵ�.
/// N�� �־����� ��, 1���� ũ�ų� ����, N���� �۰ų� ���� �Ѽ��� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
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