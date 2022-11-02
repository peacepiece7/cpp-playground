// https://www.acmicpc.net/problem/1316
/*
그룹 단어란 단어에 존재하는 모든 문자에 대해서, 각 문자가 연속해서 나타나는 경우만을 말한다.
단어 N개를 입력으로 받아 그룹 단어의 개수를 출력하는 프로그램을 작성하시오.
첫째 줄에 단어의 개수 N이 들어온다. N은 100보다 작거나 같은 자연수이다. 
둘째 줄부터 N개의 줄에 단어가 들어온다. 단어는 알파벳 소문자로만 되어있고 중복되지 않으며, 길이는 최대 100이다.
*/

#include<bits/stdc++.h>
using namespace std;
int arr[26], cnt, n;
string s;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		char prev = s[0];
		bool f = true;
		memset(arr, 0, sizeof(arr));
		for (int j = 0; j < s.size(); j++) {
			if (prev == s[j]) arr[s[j]-97]++;
			else {
				if (arr[s[j]-97] != 0) {
					f = false;
					break;
				}
				arr[s[j] - 97]++;
			}
			prev = s[j];
		}
		if (f) cnt++;
	}
	cout << cnt << "\n";
}