#include<bits/stdc++.h>
using namespace std;

int che[100];
 
bool check(int n) {
    if (n == 0) return 0;
    if (n == 1) return 0;
    if (n == 2) return 1;
    for (int i = 2; i < i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    cout << "Hello, world!" << "\n";
    return 0;
}