/*
https://www.acmicpc.net/submit/10757/46822339

브5의 난이도지만.. c++로 풀려면 브5는 아닌 듯한 문제

임의으 큰 수 a, b를 더하는 문제 long long 불가한 큰 수 10^10000

*/

#include <iostream>;
#include <string>;
using namespace std;
string a, b;
string n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> a >> b;
	if (b.size() > a.size()) swap(a, b);

	if (b.size() != a.size())
	{
		for (int i = 0; i < a.size(); i++) if (i > b.size() - 1) b = "0" + b;
	}

	for (int i = a.size() - 1; i >= 0; i--)
	{
		int tmp = ((int)a[i] - 48) + ((int)b[i] - 48);
		n.push_back((tmp % 10) + 48);
		if (tmp >= 10) tmp = 1;
		else tmp = 0;
		if (0 < i) {
			a[i - 1] = (char)(a[i - 1] - 48 + tmp) + 48;
		}
		else if (tmp) n = n + '1';
	}
	for (int i = n.size() - 1; i >= 0; i--) cout << n[i];

	return 0;
}