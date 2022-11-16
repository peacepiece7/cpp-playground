/*

https://www.acmicpc.net/problem/3036


예제 입력 1 
3
8 4 2
예제 출력 1 
2/1
4/1

예제 입력 2 
4
12 3 8 4
예제 출력 2 
4/1
3/2
3/1

예제 입력 3 
4
300 1 1 300
예제 출력 3 
300/1
300/1
1/1
*/

#include<iostream>
using namespace std;
int n,x,y;

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b%a,a);
}

int main() {
    cin >> n;
    cin >> x;
    for(int i = 1; i < n ; i++) {
        cin >> y;
        int gcdn = gcd(x,y);
        cout << x/gcdn << "/" << y/gcdn << '\n';
    }

}