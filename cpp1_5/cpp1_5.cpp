#include <iostream>
using namespace std;
int main()
{
	int x, y, z;
	x = 1;
	y = 2;
	z = 3;

	int a = 1, b = 2, c = 3;
	// std = standard
	// :: = namespace (소속) 생략 가능하나, 작성하는 것을 권장 using namesapce std;해줘야함
	// cout = console output
	// endl = end line은 \n와 같은 동작을 함
	std::cout << x << std::endl; // 1
	std::cout << y << std::endl; // 2
	
	std::cout << x; // 1
	std::cout << y; // 12
	std::cout << endl;
	
	int num0 = 1;
	int num1 = num0 * 1.5;
	int num2 = num0 / 2;
	int num3 = 2.5;

	// integer라서 실수만 나옴
	cout << "num0 " << num0 << endl; // 1
	cout << "num1 " << num1 << endl; // 1
	cout << "num2 " << num2 << endl; // 0
	cout << "num3 " << num3 << endl; // 2


	// 변수가 아닌 값을 직접 입력함 = literal이라고 함 ("Hello, world", 1, 2 ,11, 0b11)
	int num4 = 11; // decimal 
	int num5 = 011; // 0 = octal 
	int num6 = 0b11; // 0b = binary 
	int num7 = 0x11; // 0x = hex 

	// integer라서 실수만 나옴
	cout << "num4 " << num4 << endl; // 11 
	cout << "num5 " << num5 << endl; // 9
	cout << "num6 " << num6 << endl; // 3
	cout << "num7 " << num7 << endl; // 17

	// signed (부호가 있는, minus가능)
	// unsigned (부호가 없는)
	// int, signed, signed int, unsigned int (32 bit, 4byte)
	// short = short int, signed short, signed short int, unsigned short, unsigned short int (16bit = 2byte)
	// long = long int, signed long (32bit || 64bit)
	// long long .... (64bit)

	// 32 bit system (포인터가 4) (int/long/pointer size)
		// LP32 2/4/4 (win16 api)
		// ILP32 4/4/4 (win 32api, unix & unix like systems (mac os X, linux))

	// 64bit system (포인터가 8) (int/long/pointer size)
		// LLP64 4/4/8 (win64 api)
		// LP64  4/8/8 (unix and  unix-like systems (Linux, Mac os X)

	
	// cpp online editor에 복붙해보자!
	int intNum = 0;
	long longNum = 0;
	int* intPointer = &intNum;

	cout << sizeof(intNum) << endl;
	cout << sizeof(longNum) << endl;
	cout << sizeof(intPointer) << endl;

	// 암호처럼 사이즈가 민감할 경우는 아래와 같이 사용가능
	int8_t numt1 = 0;
	int16_t numt2 = 0;
	int32_t numt3 = 0;

	cout << sizeof(numt1) << endl;
	cout << sizeof(numt2) << endl;
	cout << sizeof(numt3) << endl;

	unsigned int ua = 11u; // 리터럴로 확실하게 타입을 적어줘야 타입 변환이 일어나지 않음
	long int longIntNum = 0L; 
	long long int longLongNum = 0LL; 
	unsigned long long LLIntU = 0LLu;

	std::cout << LLIntU << endl;
}