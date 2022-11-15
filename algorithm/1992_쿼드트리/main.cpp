/*
첫째 줄에는 영상의 크기를 나타내는 숫자 N 이 주어진다. N 은 언제나 2의 제곱수로 주어지며, 
1 ≤ N ≤ 64의 범위를 가진다. 두 번째 줄부터는 길이 N의 문자열이 N개 들어온다.
각 문자열은 0 또는 1의 숫자로 이루어져 있으며, 영상의 각 점들을 나타낸다.

8
11110000
11110000
00011100
00011100
11110000
11110000
11110011
11110011

((110(0101))(0010)1(0001))
*/
#include<bits/stdc++.h>
using namespace std;
int n;
char arr[65][65];
string s, ret;

void print() {
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
}

string go(int sy, int sx, int ey, int ex,int size) {
	string a;
	if(size == 1) {
		return string(1, arr[sy][sx]);
	}
	for (int i = sy; i < ey; i++) {
		for (int j = sx; j < ex; j++) {
			if (arr[i][j] != arr[sy][sx]) {
				a += "(";
				a += go(sy, sx, ey/2-1, ex/2-1, size/2);
				a += go(sy, sx+size/2, ey/2-1, ex, size/2);
				a += go(sy+size/2, sx, ey, ex/2-1, size/2);
				a += go(sy+size/2, sy+size/2, ey,ex, size/2);
				a += ")";
				return a;
			}
		}
	}
	return string(1, arr[sy][sx]);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			arr[i][j] = s[j];
		}
	}
	ret = go(0,0,n,n,n);
	cout << ret << "\n";
}
 