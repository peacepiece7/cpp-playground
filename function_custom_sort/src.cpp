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
	// bool operator < �� 
	// bool operator < �� ����� �� (parameter)�� �޾Ƽ� { return value }�� ��ȯ�Ѵ�. (< �����ڸ� �����ε��Ѵ�)
	bool operator < (const Point& a) const {
		printf("bool operator\n");
		cout << "x :" << x << endl;
		cout << "y :" << y << endl;
		cout << "a.x :" << a.x << endl;
		cout << "a.y :" << a.y << endl;
		// x, a.x�� ������ y�� �ٸ��� x�� 
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
		printf("a�� {i,i}�� �Ҵ�\n");
		Point a = { i, i };
		printf("v�� push back\n");
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
