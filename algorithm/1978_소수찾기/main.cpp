/*
문제
주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.

입력
첫 줄에 수의 개수 N이 주어진다.N은 100이하이다.다음으로 N개의 수가 주어지는데 수는 1, 000 이하의 자연수이다.

출력
주어진 수들 중 소수의 개수를 출력한다.

4
1 3 5 7

3
*/
#include<iostream>
using namespace std;
int che[10004], n, m, cnt;

int main() {
	for (int i = 2; i <= 10000; i++) {
		if (che[i]) continue;
		for (int j = i * 2; j <= 1004; j += i) {
			che[j] = 1;
		}
	}
	cin >> n;
	che[2] = 1;
	che[3] = 1;
	for (int i = 0; i < n; i++) {
		cin >> m;
		if (che[m] == 0) cnt++;
	}
	cout << cnt;
	return 0;
}