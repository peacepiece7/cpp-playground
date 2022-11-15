/*
https://www.acmicpc.net/problem/2609

입력 받고 최소, 최대 공배수 구하기

예제 입력 1 
24 18
예제 출력 1 
6
72
*/

#include<iostream>
using namespace std;
int a, b;

int gcdf(int x, int y) {
    if(x == 0) return y;
    return gcdf(y%x, x);
}

int main() {
    cin >> a >> b;
    int gcd = gcdf(a, b);
    cout << gcd << "\n";
    cout << a*b/gcd << "\n";
}
