#include <bits/stdc++.h>

using namespace std;

pair<int, int> pi;
tuple<int, int, int> ti;
int a, b, c;

int main() {

	pi = make_pair(1, 2);

	// tie(a, b) = pi;
	a = pi.first;
	b = pi.second;

	cout << "pair :" << a << " : " << b << endl;

	ti = make_tuple(1, 2, 3);

	// tie(a,b,c) = ti;
	a = get<0>(ti);
	b = get<1>(ti);
	c = get<2>(ti);

	cout << "tuple :" << a << " : " << b << " : " << c << endl;


}