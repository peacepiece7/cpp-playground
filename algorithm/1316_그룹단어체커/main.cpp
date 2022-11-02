// https://www.acmicpc.net/problem/1316
/*
�׷� �ܾ�� �ܾ �����ϴ� ��� ���ڿ� ���ؼ�, �� ���ڰ� �����ؼ� ��Ÿ���� ��츸�� ���Ѵ�.
�ܾ� N���� �Է����� �޾� �׷� �ܾ��� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
ù° �ٿ� �ܾ��� ���� N�� ���´�. N�� 100���� �۰ų� ���� �ڿ����̴�. 
��° �ٺ��� N���� �ٿ� �ܾ ���´�. �ܾ�� ���ĺ� �ҹ��ڷθ� �Ǿ��ְ� �ߺ����� ������, ���̴� �ִ� 100�̴�.
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