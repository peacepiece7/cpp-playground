/*
https://www.acmicpc.net/problem/9375

입력
첫째 줄에 테스트 케이스가 주어진다. 테스트 케이스는 최대 100이다.

각 테스트 케이스의 첫째 줄에는 해빈이가 가진 의상의 수 n(0 ≤ n ≤ 30)이 주어진다.
다음 n개에는 해빈이가 가진 의상의 이름과 의상의 종류가 공백으로 구분되어 주어진다. 같은 종류의 의상은 하나만 입을 수 있다.
모든 문자열은 1이상 20이하의 알파벳 소문자로 이루어져있으며 같은 이름을 가진 의상은 존재하지 않는다.

출력
각 테스트 케이스에 대해 해빈이가 알몸이 아닌 상태로 의상을 입을 수 있는 경우를 출력하시오.

예제 입력 1 
2
3
hat headgear
sunglasses eyewear
turban headgear
3
mask face
sunglasses face
makeup face
예제 출력 1 
5
3

- 해설

2가지 + 1가지 옷일 경우
1번옷    2번옷
1       1
2       2(안입음) 
3(안입음)

위와같이 안 입는 경우까지 생각해야한다. -> 총 6가지
그중 3,2을 고르는 경우는 존재하지 않기떄문에 (안입음+안입음), 1을 빼준다. -> 총 5가지

*/

#include<iostream>
#include<map>
#include<string>
using namespace std;
int t,n,ret;
map<string,int> mp;
string a,b;
int main() {
    cin >>t;
    while(t--){
        mp.clear();
        ret = 1;
        cin >> n;
        for(int i = 0 ; i < n;i++) {
            cin >> a >> b;
            mp[b]++;
        }
        for(auto item : mp) ret *=item.second+1;
        cout << ret-1 << "\n";
    }
}