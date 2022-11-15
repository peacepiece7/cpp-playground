#include<iostream>
#include<vector>
using namespace std;
int che[101];
// ����  �ִ��� 10^5���ϸ� �����佺 �׳׽��� ü ����ϰ� ������ ������ üũ
vector<int> era(int mx_n) {
	vector<int> v;
	// �Ÿ��� ����� �ڵ�
	for (int i = 2; i <= mx_n; i++) {
		if (che[i]) continue;
		for (int j = 2 * i; j <= mx_n; j += i) {
			che[j] = 1;
		}
	}
	for (int i = 2; i <= mx_n; i++) if(che[i] == 0)  v.push_back(i);
	return v;
}

bool check(int n) {
	if (n <= 1) return 0;
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	for (int i = 1; i <= 20; i ++ ) {
		if (check(i)) cout << i << "�� �Ҽ�" << '\n';
	}
	vector<int> pnums = era(100);
	for (auto i : pnums) {
		cout << i << " ";
	}
	cout  << "\n";
	for (int i : che) { cout << i << " "; } // �̰� �� �����÷ο찡 �ȳ����� �𸣰��� ��; che�迭�� ������� �׻� �Է� �ִ� + 2���� ������
}