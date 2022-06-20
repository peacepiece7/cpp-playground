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
	// :: = namespace (�Ҽ�) ���� �����ϳ�, �ۼ��ϴ� ���� ���� using namesapce std;�������
	// cout = console output
	// endl = end line�� \n�� ���� ������ ��
	std::cout << x << std::endl; // 1
	std::cout << y << std::endl; // 2
	
	std::cout << x; // 1
	std::cout << y; // 12
	std::cout << endl;
	
	int num0 = 1;
	int num1 = num0 * 1.5;
	int num2 = num0 / 2;
	int num3 = 2.5;

	// integer�� �Ǽ��� ����
	cout << "num0 " << num0 << endl; // 1
	cout << "num1 " << num1 << endl; // 1
	cout << "num2 " << num2 << endl; // 0
	cout << "num3 " << num3 << endl; // 2


	// ������ �ƴ� ���� ���� �Է��� = literal�̶�� �� ("Hello, world", 1, 2 ,11, 0b11)
	int num4 = 11; // decimal 
	int num5 = 011; // 0 = octal 
	int num6 = 0b11; // 0b = binary 
	int num7 = 0x11; // 0x = hex 

	// integer�� �Ǽ��� ����
	cout << "num4 " << num4 << endl; // 11 
	cout << "num5 " << num5 << endl; // 9
	cout << "num6 " << num6 << endl; // 3
	cout << "num7 " << num7 << endl; // 17

	// signed (��ȣ�� �ִ�, minus����)
	// unsigned (��ȣ�� ����)
	// int, signed, signed int, unsigned int (32 bit, 4byte)
	// short = short int, signed short, signed short int, unsigned short, unsigned short int (16bit = 2byte)
	// long = long int, signed long (32bit || 64bit)
	// long long .... (64bit)

	// 32 bit system (�����Ͱ� 4) (int/long/pointer size)
		// LP32 2/4/4 (win16 api)
		// ILP32 4/4/4 (win 32api, unix & unix like systems (mac os X, linux))

	// 64bit system (�����Ͱ� 8) (int/long/pointer size)
		// LLP64 4/4/8 (win64 api)
		// LP64  4/8/8 (unix and  unix-like systems (Linux, Mac os X)

	
	// cpp online editor�� �����غ���!
	int intNum = 0;
	long longNum = 0;
	int* intPointer = &intNum;

	cout << sizeof(intNum) << endl;
	cout << sizeof(longNum) << endl;
	cout << sizeof(intPointer) << endl;

	// ��ȣó�� ����� �ΰ��� ���� �Ʒ��� ���� ��밡��
	int8_t numt1 = 0;
	int16_t numt2 = 0;
	int32_t numt3 = 0;

	cout << sizeof(numt1) << endl;
	cout << sizeof(numt2) << endl;
	cout << sizeof(numt3) << endl;

	unsigned int ua = 11u; // ���ͷ��� Ȯ���ϰ� Ÿ���� ������� Ÿ�� ��ȯ�� �Ͼ�� ����
	long int longIntNum = 0L; 
	long long int longLongNum = 0LL; 
	unsigned long long LLIntU = 0LLu;

	std::cout << LLIntU << endl;
}