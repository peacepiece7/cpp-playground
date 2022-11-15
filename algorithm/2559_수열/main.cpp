/*
https://www.acmicpc.net/problem/2559

입력
첫째 줄에는 두 개의 정수 N과 K가 한 개의 공백을 사이에 두고 순서대로 주어진다. 
첫 번째 정수 N은 온도를 측정한 전체 날짜의 수이다. N은 2 이상 100,000 이하이다. 
두 번째 정수 K는 합을 구하기 위한 연속적인 날짜의 수이다. K는 1과 N 사이의 정수이다. 
둘째 줄에는 매일 측정한 온도를 나타내는 N개의 정수가 빈칸을 사이에 두고 주어진다. 
이 수들은 모두 -100 이상 100 이하이다. 

출력
첫째 줄에는 입력되는 온도의 수열에서 연속적인 K일의 온도의 합이 최대가 되는 값을 출력한다.

예제 입력 1 
10 2
3 -2 -4 -9 0 3 7 13 8 -3
예제 출력 1 
21
예제 입력 2 
10 5
3 -2 -4 -9 0 3 7 13 8 -3
예제 출력 2 


*/

#include <bits/stdc++.h>
using namespace std;
int n,k,ret = -100004 ,tmp,a[100004];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = a[i-1] + a[i]; 
    }
    for(int i = k; i <= n; i++) {
        ret = max(ret, (a[i] - a[i-k]));
    }
    cout << ret << "\n";
    return 0;
}