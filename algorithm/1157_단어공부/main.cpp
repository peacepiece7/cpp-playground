/// <summary>
/// �빮�ڿ� �ҹ��ڸ� �������� �ʴ´�.0 <= s < 1,000,000
/// ù° �ٿ� �� �ܾ�� ���� ���� ���� ���ĺ��� �빮�ڷ� ����Ѵ�. ��, ���� ���� ���� ���ĺ��� ���� �� �����ϴ� ��쿡�� ?�� ����Ѵ�.
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