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
	// ����� �־��� -> ���� ���� ��� * ���� ū ��� -> �ּҰ����(lcm)
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		v.push_back(x);
	}

}