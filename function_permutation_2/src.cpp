#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// recursion
int a[3] = { 1,2,3 };

vector<int> v;

void printV(vector<int> &v)
{
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;
}

void makePermutation(int n, int r, int depth)
{
	if (r == depth)
	{
		printV(v);
		return;
	}
	for (int i = depth; i < n; i++)
	{
		cout << depth << endl;
		swap(v[i], v[depth]);
		cout << "Point" << endl;
		for (int i : v) cout << i << " ";
		cout << endl;

		makePermutation(n, r, depth + 1);
		cout << depth << endl;
		cout << "Point" << endl;
		for (int i : v) cout << i << " ";
		cout << endl;

		swap(v[i], v[depth]);
		cout << "Point" << endl;
		for (int i : v) cout << i << " ";
		cout << endl;

	}
	return;
}

int main() {

	for (int i = 0; i < 3; i++) v.push_back(a[i]);
	makePermutation(3, 3, 0);
	return 0;
}

