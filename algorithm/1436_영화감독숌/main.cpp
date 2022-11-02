/*
https://www.acmicpc.net/problem/1436
종말의 숫자란 어떤 수에 6이 적어도 3개이상 연속으로 들어가는 수를 말한다.
숌은 첫 번째 영화의 제목은 세상의 종말 666, 두 번째 영화의 제목은 세상의 종말 1666 이렇게 이름을 지을 것이다.
숌이 만든 N번째 영화의 제목에 들어간 숫자를 출력하는 프로그램을 작성하시오.

2 -> 1666
3 -> 2666
187 -> 66666
500 -> 166699
*/

#include<bits/stdc++.h>
using namespace std;
int n;
string s;

int main() {
	cin >> n;
	int i = 666;
	for (;; i++) {
		if (to_string(i).find("666") != string::npos) n--;
		if (!n) break;
	}
	cout << i << "\n";
	return 0;
}