/// <summary>
/// ���� ù ���ڰ� ���� ���� 5���� ����
/// ������ �� �ִ� ��쿡�� ������ ���� ù ���ڸ� ���������� ������� ��� ���
/// ������ �� �ִ� ù ���ڰ� ���� ������ 5���� ���ٸ� "PREDAJA" (����ǥ ����)�� ���
/// ������ �� N (1 �� N �� 150), ���� ���ĺ� �ҹ��ڷθ� �̷���� �ְ�, �ִ� 30�����̴�
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