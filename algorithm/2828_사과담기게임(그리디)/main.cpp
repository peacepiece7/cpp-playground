/*


입력
첫째 줄에 N과 M이 주어진다. (1 ≤ M < N ≤ 10) 둘째 줄에 떨어지는 사과의 개수 J가 주어진다. (1 ≤ J ≤ 20) 다음 J개 줄에는 사과가 떨어지는 위치가 순서대로 주어진다.

출력
모든 사과를 담기 위해서 바구니가 이동해야 하는 거리의 최솟값을 출력한다.

N => 스크린 사이즈
M => 바구니 사이즈

예제 입력 1 
5 1
3
1
5
3
예제 출력 1 
6

예제 입력 2 
5 2
3
1
5
3
예제 출력 2 
4
*/

#include<bits/stdc++.h>
using namespace std;
int n,m,k,pos,ret;

int main() {
    cin >> n >> m;
    cin >> k;

    int lt = 1;
    int rt = m;
    while(k--) {
        cin >> pos;
        int moved = 0;
        if(rt < pos) {
            moved = pos - rt;
            rt = pos;
            lt = lt+moved;
        }else if (lt > pos) {
            moved = lt - pos;
            lt = pos;
            rt = rt-moved;
        }
        ret += moved;
    }
    cout << ret << '\n';
}
