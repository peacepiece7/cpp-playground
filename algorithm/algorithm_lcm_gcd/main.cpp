#include<iostream>
using namespace std;

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}
int main() {
	int x = 10, y = 4;
	cout << gcd(x, y) << "\n";
	cout << lcm(x, y) << "\n";
}