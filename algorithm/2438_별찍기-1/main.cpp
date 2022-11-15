

#include<bits/stdc++.h>
using namespace std;


void star1() {
	int n;
	cin >> n;
	string s;
	while (n--) {
		s += "*";
		cout << s << "\n";
	}
}
void star2() {
	int n;
	cin >> n;
	string s;
	int tempn = n;
	while (tempn--) {
		s += " ";
	}
	while (n--) {
		s.erase(0, 1);
		s += "*";
		cout << s << "\n";
	}
}
int main() {
	star1();
	star2();
	return 0;
}