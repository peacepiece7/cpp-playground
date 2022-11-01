// https://www.acmicpc.net/problem/1213
/*
	
 */
#include<iostream>
#include<string>
using namespace std;
int n;
string s;
int arr[27];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> s;
	for(int i = 0 ; i < s.size() ; i++ ) arr[s[i]-65]++;
	int odd = 0;
	int oddchar = 0;
	for(int i = 0; i < 26; i++) {
		if(arr[i] % 2 != 0) odd++;
	}
	if(odd >= 2) {
		cout << "I'm Sorry Hansoo" << "\n";
		return 0;
	}
	string answer;
	// a-z순으로 절반 + 기운데 채우기
	for(int i = 0; i < 26; i++) {
		if(arr[i]%2) oddchar = i;
		for(int j = 0 ; j < (int)arr[i]/2; j++) {
			answer+=char(i+65);
		}
	}
	if(odd == 1) answer +=(char)(oddchar + 65);
    // z부터 a순으로 나머지 채우기
	for(int i = 26; i >= 0; i--) {
		for(int j = 0; j < (int)arr[i]/2;j++) {
			answer+=char(i+65);
		}
	}
	cout << answer << "\n";
}