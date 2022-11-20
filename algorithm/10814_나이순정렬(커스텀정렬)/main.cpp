/*
https://www.acmicpc.net/problem/10814

입력
첫째 줄에 온라인 저지 회원의 수 N이 주어진다. (1 ≤ N ≤ 100,000)

둘째 줄부터 N개의 줄에는 각 회원의 나이와 이름이 공백으로 구분되어 주어진다. 나이는 1보다 크거나 같으며, 200보다 작거나 같은 정수이고, 이름은 알파벳 대소문자로 이루어져 있고, 길이가 100보다 작거나 같은 문자열이다. 입력은 가입한 순서로 주어진다.

출력
첫째 줄부터 총 N개의 줄에 걸쳐 온라인 저지 회원을 나이 순, 나이가 같으면 가입한 순으로 한 줄에 한 명씩 나이와 이름을 공백으로 구분해 출력한다.

예제 입력 1 
3
21 Junkyu
21 Dohyun
20 Sunyoung
예제 출력 1 
20 Sunyoung
21 Junkyu
21 Dohyun

*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int n;
struct UserInformation {
    string name;
    int age;
    int idx;
};
vector<UserInformation> v;

bool cmp(UserInformation a, UserInformation b) {
    if(a.age == b.age) {
        return a.idx < b.idx;
    }
    return a.age < b.age;
}

int main() {
    cin >> n;
    int m;
    string s;
    for(int i = 0 ; i < n ; i++) {
        cin >> m >> s;
        v.push_back({s,m,i});
    }
    sort(v.begin(),v.end(),cmp);   
    for(auto i : v) {
        cout << i.age << " " << i.name << "\n";
    }
}