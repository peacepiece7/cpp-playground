/*
5를 곱할 떄 마다 0이 하나씩 더 붙는다.
이런 문제는 5의 배수 5, 25, 125 ... 와 2의 배수 2 4 8 16만 생각하면된다.
5은 0이 1개 추가, 25는 0이 2개추가,,, 이런식임 둘 중 작은 값이 0의 개수인데 5가 당연히 작다.

N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.
첫째 줄에 N이 주어진다. (0 ≤ N ≤ 500)

10 -> 2
3  -> 0
*/

#include<iostream>
using namespace std;
int n;
int main() {
	cin >> n;
	int cnt = 0;
	for (int j = 5; j <= n; j *= 5) {
		for (int i = 1; i <= n; i++) {
			if (i % j == 0) cnt++;
		}
	} 
	/*  n >= 500, 일경우 아래와 같다.
		for (int i = 1; i <= n; i++)
	{
		if (i % 5 == 0) cnt++;
		if (i % 25 == 0) cnt++;
		if (i % 125 == 0) cnt++;
	}
	cout << cnt << "\n";
;	*/
	cout << cnt << "\n";
	return 0;
}


