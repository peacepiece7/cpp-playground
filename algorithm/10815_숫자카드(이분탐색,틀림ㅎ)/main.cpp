/*
https://www.acmicpc.net/problem/10815

입력
첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다. 
숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다. 두 숫자 카드에 같은 수가 적혀있는 경우는 없다.

셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다. 넷째 줄에는 상근이가 가지고 있는 숫자 카드인지 아닌지를 구해야 할 M개의 정수가 주어지며, 
이 수는 공백으로 구분되어져 있다. 이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다

출력
첫째 줄에 입력으로 주어진 M개의 수에 대해서, 각 수가 적힌 숫자 카드를 상근이가 가지고 있으면 1을, 아니면 0을 공백으로 구분해 출력한다.

예제 입력 1 
5
6 3 2 10 -10
8
10 9 -5 2 3 4 5 -10
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, a, b;
int v[500004];
int main() {
    cin >> n;
    for(int i = 0; i < n ; i++) cin >> v[i];
    sort(v, v+n);
    cin >> m;
    for(int i = 0 ; i < m; i++) {
        cin >> b;
        int lt = 0;
        int rt = n-1;
        int mid = n/2;
        bool f = false;
        while (lt <= rt) {
			mid = (lt + rt) / 2;
			if (v[mid] == b) {
				cout << 1 << " ";
				f = true;
				break;
			}
			else if (v[mid] > b) rt = mid - 1;
			else lt = mid + 1;
		}
		if (!f) cout << 0 << " ";
    } 
}