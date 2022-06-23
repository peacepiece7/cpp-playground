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

	bool b0 = 0 == 0;
	bool b1 = 0 < 1;
	bool b2 = 0 > 1;
	bool b3 = 100;
	bool b4 = -1;
	
	// cout.setf(ios_base::boolalpha)
	cout << "b0 :" << b0 << endl;
	cout << "b1 :" << b1 << endl;
	cout << "b2 :" << b2 << endl;
	cout << "b3 :" << b3 << endl;
	cout << "b4 :" << b4 << endl;


	if (b0)
		cout << "b0 :" << b0 << endl;
	if (b1)
		cout << "b1 :" << b1 << endl;
	if(b2)
		cout << "b2 :" << b2 << endl;

}