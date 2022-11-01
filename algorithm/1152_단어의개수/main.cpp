/// <summary>
///  첫째 줄에 단어의 개수를 출력한다. 0 <= s <= 1,000,000
/// </summary>

#include<iostream>
#include<string>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
using namespace std;
string s;
int cnt;

int main() {
	fastio;
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cnt = 1;
    string s;
    getline(cin, s);

    for (int i = 0; i < s.size(); i++) if (s[i] == ' ') cnt++;

    if (s.front() == ' ') cnt--;
    if (s.back() == ' ') cnt--;

    cout << cnt << '\n';
    return 0;
}