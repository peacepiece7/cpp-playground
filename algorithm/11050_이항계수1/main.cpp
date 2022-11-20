/*
https://www.acmicpc.net/problem/11050

이항 계수의 뜻을 아는지 물어보는 문제
이항 계수 r을 구하는 공식은 아래와 같음
r = n!/(n-k)!k!
*/
#include<iostream>
using namespace std;

int fac(int a) {
    if(a == 0) return 1;
    return fac(a-1) * a;
}

int main() {
    int n,k;
    cin >> n >> k;
    cout << (fac(n) / (fac(n-k)*fac(k))) << "\n";
    return 0;
}