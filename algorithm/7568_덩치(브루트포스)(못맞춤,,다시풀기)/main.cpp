/*
https://www.acmicpc.net/problem/7568

입력
첫 줄에는 전체 사람의 수 N이 주어진다. 그리고 이어지는 N개의 줄에는 각 사람의 몸무게와 키를 나타내는 양의 정수 x와 y가 하나의 공백을 두고 각각 나타난다.

출력
여러분은 입력에 나열된 사람의 덩치 등수를 구해서 그 순서대로 첫 줄에 출력해야 한다. 단, 각 덩치 등수는 공백문자로 분리되어야 한다.

제한
2 ≤ N ≤ 50
10 ≤ x, y ≤ 200
예제 입력 1 
5
55 185
58 183
88 186
60 175
46 155
예제 출력 1 
2 2 1 2 5
*/

#include<bits/stdc++.h>
using namespace std;
struct BodySize {
    int weight;
    int height;
    int rank;
};
int n;
int max_w, max_h;
vector<BodySize> v;


int main() {
    cin >> n;
    int w,h;
    for(int i = 0; i < n ; i++)  {
        cin >> w >> h;
        v.push_back({w,h,0});
    }

    for(int i = 0 ; i < n ; i++) {
        int rank = 1;
        for(int j = 0; j < n; j++) {
            if(i==j) continue;
            if(v[i].weight < v[j].weight && v[i].height < v[j].height) rank++;
        }
        v[i].rank = rank;
    }

    for(auto person : v) cout << person.rank << " ";
    return 0;
}
