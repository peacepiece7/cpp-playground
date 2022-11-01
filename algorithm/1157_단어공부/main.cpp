/// <summary>
/// 대문자와 소문자를 구분하지 않는다.0 <= s < 1,000,000
/// 첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.
/// </summary>
/// 
#include<iostream>
#include<string>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
using namespace std;
string s;
int arr[26];

int main() {
    fastio;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if ((s[i] - 'a') >= 0) {
            arr[s[i] - 'a']++;
            cnt = max(cnt, arr[s[i] - 'a']);
        }
        else {
            arr[s[i] - 'A']++;
            cnt = max(cnt, arr[s[i] - 'A']);
        }
    }
    int dup = 0;
    char c = '?';
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        if (dup <= 1 && cnt == arr[i]) {
            c = (char)(i + 65);
            dup++;
        }
        if(dup >= 2) c = '?';
    }
    cout << c << '\n';

    return 0;
}