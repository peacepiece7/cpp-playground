#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;


int gcd(int a, int b) {
	if (a == 0) return b;
	else return gcd(b % a, a);
}
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}



int main() {
	// 약수가 주어짐 -> 가장 작은 약수 * 가장 큰 약수 -> 최소공배수(lcm)
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		v.push_back(x);
	}

}