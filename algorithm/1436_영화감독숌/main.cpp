/*
https://www.acmicpc.net/problem/1436
������ ���ڶ� � ���� 6�� ��� 3���̻� �������� ���� ���� ���Ѵ�.
���� ù ��° ��ȭ�� ������ ������ ���� 666, �� ��° ��ȭ�� ������ ������ ���� 1666 �̷��� �̸��� ���� ���̴�.
���� ���� N��° ��ȭ�� ���� �� ���ڸ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

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