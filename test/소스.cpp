#include <bits/stdc++.h>

using namespace std;

struct Point {
	int x, y;
};

bool cmp(const Point a, const Point b) {
//	cout << a.x << " " << a.y << endl;
//	cout << b.x << " " << b.y << endl << endl;
	cout << (a.x < b.x) << endl;
	return a.x > b.x;
}

vector<Point> v;

int main() {

	for (int i = 10; i >= 1; i--) v.push_back({i,i});

	sort(v.begin(), v.end(), cmp);

	for (auto i: v) cout << i.x << " " << i.y << endl;
	return 0;
}; 