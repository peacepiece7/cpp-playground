#include <iostream>
#include <limits>
using namespace std;

int main() {
	// "" ���ڿ�
	// '' ����

	// char 1btye = 8bit, 255���� = charCodeAt
	char a = 'a';
	char b = 97;
	cout << "Hello, world" << endl;

	cout << a << endl;
	cout << b << endl;

	cout << int(a) << endl;
	cout << (int)b << endl;

	cout << numeric_limits<uint8_t>::max() << endl; // 255�� �ش�Ǵ� �ƽ�Ű �ڵ尡 ��� ���� ���� (uint8_t = char)
	cout << (int)numeric_limits<uint8_t>::max() << endl; // 255�� �ش�Ǵ� �ƽ�Ű �ڵ尡 ��� ���� ����, ���� ���ڳ���
}