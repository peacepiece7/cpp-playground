/*
출력
각 테스트 케이스에 대해서, n보다 크고, 2n보다 작거나 같은 소수의 개수를 출력한다.

제한
1 ≤ n ≤ 123,456
예제 입력 1 
1
10
13
100
1000
10000
100000
0
예제 출력 1 
1
4
3
21
135
1033
8392
*/

#include<iostream>
#include<vector>
using namespace std;
int che[250004];
int n;

void era(int maxNum) {
    for(int i = 2; i <= maxNum; i++) {
        if(che[i]) continue;
        for(int j = i*2; j <= maxNum; j+=i) {
            che[j] = 1;
        }
    }
    return;
}

int main() {
    era(250000);
    while(true) {
        cin >> n;
        if(n == 0) break;
        int cnt = 0;
        for(int i = n+1; i <= 2*n; i++) {
            if(che[i] == 0) cnt++;
        }
        cout << cnt << '\n';
    }
}