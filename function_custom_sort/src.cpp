#include <bits/stdc++.h>

using namespace std;

struct Point {
	int y, x;
	Point(int y, int x) : y(y), x(x) {
		printf("point1\n");
		cout << y << " : " << x << endl;
	};
	Point() {
		printf("point2\n");
		y = -1; x = -1;
		cout << y << " : " << x << endl;
	};
	// bool operator < 뜻 
	// bool operator < 가 실행될 때 (parameter)를 받아서 { return value }를 반환한다. (< 연산자를 오버로딩한다)
	bool operator < (const Point& a) const {
		printf("bool operator\n");
		cout << "x :" << x << endl;
		cout << "y :" << y << endl;
		cout << "a.x :" << a.x << endl;
		cout << "a.y :" << a.y << endl;
		// x, a.x가 같으면 y비교 다르면 x비교 
		if (x == a.x) return y < a.y;
		return x < a.x;
	}
};

struct percent {
	int x, y;
	double w, d, l;
} a[6];

vector<Point> v;

int main() {
	percent b{ 1,2,3,4,5 };
	cout << b.x << b.y << b.w << b.d << b.l << endl;

	printf("%s\n", "custom sort");
	for (int i = 10; i >= 1; i--)
	{
		printf("a에 {i,i}를 할당\n");
		Point a = { i, i };
		printf("v에 push back\n");
		v.push_back(a);
	}

	printf("@ before\n");
	for (auto it : v) cout << it.y << " : " << it.x << endl;

	printf("@ start sort\n");
	sort(v.begin(), v.end());

	printf("@ after\n");
	for (auto it : v) cout << it.y << " : " << it.x << endl;
	return 0;
}
