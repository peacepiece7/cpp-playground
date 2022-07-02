#include<bits/stdc++.h>

using namespace std;

int a[5];
int temp[5];

int main() {

	for (int i = 5; i >= 1; i--) a[i - 1] = i;

	printf("%s\n", "before copy");
	for (int i : temp) cout << i << endl;

	memcpy(temp, a, sizeof(a));

	printf("%s\n", "after copy");
	for (int i : temp) cout << i << endl;
}