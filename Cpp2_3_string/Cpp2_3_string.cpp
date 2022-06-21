#include <iostream>
#include <limits>
using namespace std;

int main() {
	// "" 문자열
	// '' 문자

	// char 1btye = 8bit, 255가지 = charCodeAt
	char a = 'a';
	char b = 97;
	cout << "Hello, world" << endl;

	cout << a << endl;
	cout << b << endl;

	cout << int(a) << endl;
	cout << (int)b << endl;

	cout << numeric_limits<uint8_t>::max() << endl; // 255에 해당되는 아스키 코드가 없어서 빈값이 나옴 (uint8_t = char)
	cout << (int)numeric_limits<uint8_t>::max() << endl; // 255에 해당되는 아스키 코드가 없어서 빈값이 나옴, 이제 숫자나옴
}