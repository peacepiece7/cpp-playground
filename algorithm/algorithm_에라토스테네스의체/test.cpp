#include<iostream>
#include<vector>
using namespace std;
int che[101];

void print(vector<int> v) {
    for(auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> era(int mx_n) {
 // write here!
}

bool check(int n) {
 // wrtie here!
}

int main() {
    int maxNum = 20;
    vector<int> pnums = era(maxNum);

    cout << 'eratostenes che' << "\n";
    print(pnums);

    pnums.clear();
    for(int i = 1; i <= maxNum; i++) {
        if(check(i)) pnums.push_back(i);
    }

    cout << "check the primt number using check function" << "\n";
    print(pnums);
}