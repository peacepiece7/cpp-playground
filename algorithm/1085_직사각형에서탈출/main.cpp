


#include<bits/stdc++.h>
using namespace std;
/// <summary>
/// �Ѽ��� ���� (x, y)�� �ִ�. ���簢���� �� ���� ��ǥ�࿡ �����ϰ�, 
/// ���� �Ʒ� �������� (0, 0), ������ �� �������� (w, h)�� �ִ�. 
/// ���簢���� ��輱���� ���� �Ÿ��� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
/// </summary>

int x, y, w, h;
int main() {
	cin >> x>> y>> w>> h;
	int ret = min(x,y);
	int ret2 = min((w - x), (h - y));
	cout << min(ret, ret2) << "\n";
}