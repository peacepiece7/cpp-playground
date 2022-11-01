/// <summary>
/// 성의 첫 글자가 같은 선수 5명을 선발
/// 선발할 수 있는 경우에는 가능한 성의 첫 글자를 사전순으로 공백없이 모두 출력
/// 선발할 수 있는 첫 글자가 같은 선수가 5명보다 적다면 "PREDAJA" (따옴표 없이)를 출력
/// 선수의 수 N (1 ≤ N ≤ 150), 성은 알파벳 소문자로만 이루어져 있고, 최대 30글자이다
/// </summary>
#include<bits/stdc++.h>;
using namespace std;
int a[26], n, ret;
string s;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		a[(int)s[0] - 97]++;
	}
	bool f = false;
	for (int i = 0; i < 26; i++) {
		if (a[i] >= 5) {
			cout << (char)(i + 97);
			f = true;
		}
	}
	if (!f) cout << "PREDAJA";
	return 0;
}