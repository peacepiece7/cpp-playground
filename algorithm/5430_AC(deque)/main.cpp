/*
출력
각 테스트 케이스에 대해서, 입력으로 주어진 정수 배열에 함수를 수행한 결과를 출력한다. 만약, 에러가 발생한 경우에는 error를 출력한다.

예제 입력 1 
4
RDD
4
[1,2,3,4]
DD
1
[42]
RRD
6
[1,1,2,3,5,8]
D
0
[]
예제 출력 1 
[2,1]
error
[1,2,3,5,8]
error
*/

#include<bits/stdc++.h>
using namespace std;
int t,n,pos;
string ops, strArr;
deque<string> dq;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--) {
        dq.clear();
        cin >> ops;
        cin >> n;
        cin >> strArr;
        string temp = ""; // 숫자가 한 자리만 온다고 착각해서 틀림 ^)^
        for(int i = 1; i < strArr.size()-1; i++) {
            if(strArr[i] == ',') {
                dq.push_back(temp);
                temp = "";
            }else {
                temp += strArr[i];
            }
        };
        if(temp.size()) dq.push_back(temp); // 이것도 빼먹어서 틀림..   
        int back = false;
        bool isError = false;
        for(int i = 0; i < ops.size(); i++) {
            if(ops[i] == 'R') {
                back = !back;
            }
            else if (ops[i] == 'D') {
                if(dq.empty()) {
                    isError = true;
                    break;
                }
                if(back) dq.pop_back();
                else dq.pop_front();
            }
        }
        if(isError) cout << "error\n";
        else {
            if (back) reverse(dq.begin(), dq.end()); // 이것도 빼먹음 ^_^
            cout << "[";
            for(int i = 0; i < dq.size();i++) {
                cout << dq[i];
                if(i != dq.size()-1) cout << ",";
            }
            cout << "]\n";
        }
    }
}