/*
https://www.acmicpc.net/problem/5622

- 총 소요시간을 구하는 간다한 구현 문제
- 3개씩 나눠지지 않는 부분이 있는데 문제를 잘 확인 해야 함
입력
첫째 줄에 알파벳 대문자로 이루어진 단어가 주어진다. 단어의 길이는 2보다 크거나 같고, 15보다 작거나 같다.

출력
첫째 줄에 다이얼을 걸기 위해서 필요한 최소 시간을 출력한다.

예제 입력 1 
WA
예제 출력 1 
13
예제 입력 2 
UNUCIC
예제 출력 2 
36
*/

#include<iostream>
#include<string>
using namespace std;
int ret;
int dial[27] = {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
string w;
int main() {
    cin >> w;
    for(int i = 0; i < w.size();i++) ret += dial[(w[i]-65)];
    cout << ret << '\n';
}
