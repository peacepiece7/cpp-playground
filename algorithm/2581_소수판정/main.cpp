/*
https://www.acmicpc.net/problem/2581

문제
자연수 M과 N이 주어질 때 M이상 N이하의 자연수 중 소수인 것을 모두 골라 이들 소수의 합과 최솟값을 찾는 프로그램을 작성하시오.

예를 들어 M=60, N=100인 경우 60이상 100이하의 자연수 중 소수는 61, 67, 71, 73, 79, 83, 89, 97 총 8개가 있으므로, 이들 소수의 합은 620이고, 최솟값은 61이 된다.

입력
입력의 첫째 줄에 M이, 둘째 줄에 N이 주어진다.

M과 N은 10,000이하의 자연수이며, M은 N보다 작거나 같다.

출력
M이상 N이하의 자연수 중 소수인 것을 모두 찾아 첫째 줄에 그 합을, 둘째 줄에 그 중 최솟값을 출력한다. 

단, M이상 N이하의 자연수 중 소수가 없을 경우는 첫째 줄에 -1을 출력한다
*/

#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> pn;

bool check(int a) {
    if(a <= 1) return 0;
    if(a == 2) return 1;
    if(a % 2 == 0) return 0;
    for(int i = 2; i*i <= a; i++) {
        if(a%i == 0) return 0;
    }
    return 1;
}
int main() {
    cin >> n >> m;
    for(int i = n; i <= m; i++) {
        if(check(i)) pn.push_back(i);
    }

    if(!pn.size()) cout << -1 << "\n";
    else {
        int sum = 0;
        for(auto i : pn) sum +=i;
        cout << sum << "\n";
        cout << pn[0] << "\n";
    }
}


/* 에라토스테네스의 체 

#include<bits/stdc++.h>
using namespace std;

int minv, che[10004], mn, mx,sum;
vector<int> pnums;


bool check(int num) {
	if (num <= 1) return 0;
	if (num == 2) return 1;
	if (num % 2 == 0) return 0;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return 0;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> mn >> mx;

	for (int i = mn; i <= mx; i++) {
		if (!check(i)) continue;
		if (!minv) minv = i;
		sum += i;
	}
	if (!minv) {
		cout << -1 << "\n";
		return 0;
	}
	cout << sum << "\n";
	cout << minv << "\n";
	return 0;
}
*/