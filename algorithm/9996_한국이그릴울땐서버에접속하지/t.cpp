#include<bits/stdc++.h>
using namespace std;

int sumStr(string a, string b) {
    string result = "";
    if(b.size() > a.size()) swap(a,b);
    reverse(a.begin(), a.end());
    reverse(b.begin(),b.end());
    bool f = false;
    for(int i = 0; i < a.size(); i++) {
        if(b.size() >= i) {
            int c = (b[i]-'0' + a[i] -'0');
            if(c%10) f = true;
        }
    }
}

int main() {
    string x, result;
    for(int i = 0 ; i< 12; i++) {
        cin >> x;
        int pos = x.find(".");
        x = x.substr(pos,1);
    }
}

