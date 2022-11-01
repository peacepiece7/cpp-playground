// https://www.acmicpc.net/problem/1193
/*
1/1	1/2	1/3	1/4	1/5	・
2/1	2/2	2/3	2/4	・	・
3/1	3/2	3/3	・	・	・
4/1	4/2	・	・	・	・
5/1	・	・	・	・	・
・	・	・	・	・	・

1 => 1/1
2 => 1/2
3 => 2/1
4 => 3/1
7 => 1/4
 */
#include<iostream>;
using namespace std;
int n;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);;
	cin >> n;
	int acc = 0;
	int lt = 0;
	int rt = 0;
	int i = 1;
	for (; acc < n; i++) acc += i;
	i--;

	if (i%2 == 0) {
		rt = i;
		lt = 1;
	} else {
		rt = 1;
		lt = i;

	};

	for (int j = n; j < acc; j++) {
		if (i % 2 == 0) {
			rt--;
			lt++;
		}
		else {
			rt++;
			lt--;
		}
	}
	cout << rt << "/" << lt << '\n';
}