/*
예제 입력 1 
a
tv
ptoui
bontres
zoggax
wiinq
eep
houctuh
end
예제 출력 1 
<a> is acceptable.
<tv> is not acceptable.
<ptoui> is not acceptable.
<bontres> is not acceptable.
<zoggax> is not acceptable.
<wiinq> is not acceptable.
<eep> is acceptable.
<houctuh> is acceptable.

*/

#include<iostream>
#include<string>
using namespace std;

bool hasVowel(char i) {
    if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') return true;
    return false;
}
bool hasVowel(string a) {
    for(auto i : a) {
        if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') return true;
    }
    return false;
}

bool checkDupWord(string a) {
    char prevc = a[0];
    int vowelCnt = hasVowel(a[0]) ? 1 : 0;
    int consonantCnt = hasVowel(a[0]) ? 1 : 0;
    for(int i = 1; i < a.size(); i++) {
        if(hasVowel(a[i])) {
            vowelCnt++;
            consonantCnt = 0;
        }else {
            vowelCnt = 0;
            consonantCnt++;
        }
        // 3개 이상시
        if(vowelCnt == 3 || consonantCnt == 3) return false;

        // aa, bb, cc 일경우
        if(a[i] == prevc && a[i] != 'e' && a[i] != 'o') {
            return false;
        }
        prevc = a[i];
    }
    return true;
}

int main() {
    string s;
    while(true) {
        cin >> s;
        if(s == "end") break;
        bool f = true;
        if(!hasVowel(s)) f = false;
        if(!checkDupWord(s)) f = false;
        if(f) cout << "<" << s << ">" << " is acceptable." << "\n";
        else cout << "<" << s << ">" << " is not acceptable." << "\n";
    }
}