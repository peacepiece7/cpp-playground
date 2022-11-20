/*

https://www.acmicpc.net/problem/9996

입력
첫째 줄에 파일의 개수 N이 주어진다. (1 ≤ N ≤ 100)

둘째 줄에는 패턴이 주어진다. 패턴은 알파벳 소문자와 별표(아스키값 42) 한 개로 이루어져 있다. 문자열의 길이는 100을 넘지 않으며, 별표는 문자열의 시작과 끝에 있지 않다.

다음 N개 줄에는 파일 이름이 주어진다. 파일 이름은 알파벳 소문자로만 이루어져 있고, 길이는 100을 넘지 않는다.

출력
총 N개의 줄에 걸쳐서, 입력으로 주어진 i번째 파일 이름이 패턴과 일치하면 "DA", 일치하지 않으면 "NE"를 출력한다.

참고로, "DA"는 크로아티어어로 "YES"를, "NE"는 "NO"를 의미한다.

예제 입력 1 
3
a*d
abcd
anestonestod
facebook
예제 출력 1 
DA
DA
NE
예제 입력 2 
6
h*n
huhovdjestvarnomozedocisvastan
honijezakon
atila
je
bio
hun
예제 출력 2 
DA
DA
NE
NE
NE
DA

*/

#include<bits/stdc++.h>
using namespace std;
string s,pattern;
int n;
int main(){
    cin >> n;
    cin >> pattern;
    long long pos = pattern.find("*");
    string lt = pattern.substr(0,pos);
    string rt = pattern.substr(pos+1);
    while(n--) {
        cin >> s;
        if(lt.size()+rt.size() <= s.size()) {
            string sl = s.substr(0,lt.size());
            string sr = s.substr(s.size()-rt.size());
            if(lt == sl && rt == sr) {
                cout << "DA" << "\n";
                continue;
            }
        }
        cout << "NE" << "\n"; 
    }
}
