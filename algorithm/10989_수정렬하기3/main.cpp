/*

https://www.acmicpc.net/problem/10989

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다. 이 수는 10,000보다 작거나 같은 자연수이다.

출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.

예제 입력 1 
10
5
2
3
1
4
2
3
5
1
7
예제 출력 1 
1
1
2
2
3
3
4
5
5
7
*/

#include<iostream>
#include<map>
using namespace std;
int n,m;
map<int,int> mp;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		mp[m]++;
	}
	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < mp[i]; j++) {
			cout << i << '\n';
		}
	}
	return 0;
}