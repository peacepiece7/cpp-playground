#include<bits/stdc++.h>
using namespace std;

void print(vector<string> v) {
    cout << endl;
    for(auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}
// 4C1, 4C2 ... 전부 뽑기
void numOfCases() {
    vector<string> fruits = {"사과", "딸기", "포도", "배"};
    for(int i = 0; i < (1 << fruits.size()); i++) {
        vector<string> temp;
        for(int j = 0; j < fruits.size(); j++) {
            if(i & (1 << j)) { // 여기서 4c1만 하려면 켜져있는 비트 체크해서 1개일 경우만 출력?
                temp.push_back(fruits[j]);
            }
        }
        print(temp);
    }
}
void numOfCasesByParams(int num) {
    const int n = 4;
    string a[4] = {"사과", "딸기", "포도", "배"};
    string ret = "";
    for(int i = 0 ; i < n ; i++) {
        if(num & (1 << i)) {
            ret += a[i] + ' ';
        }
    }
    cout << ret << "\n";
}
int main() {
 // 경우의 수 비트바스킹
 // numOfCases();
 
 // 특정 단어 포함
 for(int i = 0 ; i < 4; i++) {
    numOfCasesByParams(1 | (1 << i)); // 0001, 0011, 0101, 1001
 }
}