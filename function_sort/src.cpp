#include <bits/stdc++.h>

using namespace std;

vector<int> a;
int b[5];
bool cmp(pair<int, int> a, pair<int, int>b) {
	// cout << "first element : " << a.first << " : " << b.first << ", compair :" << (a.first > b.first) << endl;
	return a.first > b.first;
}

int main() {

	for (int i = 5; i >= 1; i--) b[i - 1] = i;
	for (int i = 5; i >= 1; i--) a.push_back(i);

	printf("%s\n", "sort ");
	for (int el : b) cout << el << endl;
	sort(b, b + 5);
	for (int el : b) cout << el << endl;


	cout << "vector a" << endl;
	for (int el : a) cout << el << endl;
	// implicitly sort by ascent
	sort(a.begin(), a.end());
	for (int el : a) cout << el << endl;
	cout << "descent" << endl;
	sort(a.begin(), a.end(), greater<int>());
	for (int el : a) cout << el << endl;
	cout << "ascent" << endl;
	sort(a.begin(), a.end(), less<int>());
	for (int el : a) cout << el << endl;
	vector<pair<int, int>> v;
	for (int i = 10; i >= 1; i--) v.push_back({ i, 10 - i });

	cout << "sort a pair before" << endl;
	for (pair<int, int> it : v) cout << it.first << " : " << it.second << endl;
	sort(v.begin(), v.end());
	cout << "sort a pair after" << endl;
	for (auto it : v) cout << it.first << " : " << it.second << endl;


	printf("%s\n", "custom compaire");

	sort(v.begin(), v.end(), cmp);

	for (pair<int, int> pi : v) cout << pi.first << " : " << pi.second << endl;

	printf("%s\n", "array sort");
	int arr[5];

	for (int i = 5; i >= 1; i--) arr[i - 1] = i;
	printf("%s\n", "before sort");
	for (int i : arr) cout << i << endl;
	sort(arr, arr + 5, greater<int>());
	printf("%s\n", "after sort");
	for (int i : arr) cout << i << endl;

	return 0;
}