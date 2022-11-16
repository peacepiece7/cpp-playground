/*
https://www.acmicpc.net/problem/4153


a^2 = b^2+c^2 직각 삼각형 구하는 공식을 까먹었니..

입력
입력은 여러개의 테스트케이스로 주어지며 마지막줄에는 0 0 0이 입력된다. 
각 테스트케이스는 모두 30,000보다 작은 양의 정수로 주어지며, 
각 입력은 변의 길이를 의미한다.

출력
각 입력에 대해 직각 삼각형이 맞다면 "right", 아니라면 "wrong"을 출력한다.

예제 입력 1 
6 8 10
25 52 60
5 12 13
0 0 0
예제 출력 1 
right
wrong
right
*/
#include<iostream>
using namespace std;

int a, b, c;

int main() {
    while(true) {
        cin >> a >> b >> c;
        if(!a && !b && !c) break;
        if(b>a) swap(a,b);
        if(c>a) swap(a,c);
        if((a*a) == ((b*b) + (c*c))) cout << "right" << "\n";
        else cout << "wrong" << "\n";
    }
}