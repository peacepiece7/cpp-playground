#include <iostream>
using namespace std;
int main() 
{
	// unsigned 
	// 이 예제는 뭘 말하는 건지 모르겠음, 아마도 자료형에 0 또는 1로 저장되는데 진법에따라 어떻게 푠현한다~ 이런거인듯
	uint8_t num0 = 1; // base 10
	uint16_t num1 = 020; //base 8 
	uint32_t num2 = 0xff; // base 16
	uint32_t num3 = 0b0101; // base 2 
	
	std::cout << num0 << std::endl;
	std::cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;

	// 8  bit max value  = 255 (2**8 -1) (캐릭터 능력치 255 어둠의 전설)
	// 16  bit max value = 65535 (2**16 -1) (경험치 맥스 65535)
	// 32 bit max valu e = 4294967295 (2**32 -1)
	cout << "unsigned 최대값" << endl;
	cout << (int)numeric_limits<uint8_t>::max() << endl;
	cout << (int)numeric_limits<uint16_t>::max() << endl;	
	cout << numeric_limits<uint32_t>::max() << endl;	
	cout << numeric_limits<uint64_t>::max() << endl;

	// signed, 가장 마지막 비트(MSB : Most Significant Bit) 가 0 양수, 1 음수
	// MSB가 기호니까 n-1 제곱까지 표현가능
	cout << "signed 음수 최대값" << endl;
	cout << (int)numeric_limits<int8_t>::max() << endl;
	cout << (int)numeric_limits<int16_t>::max() << endl;
	cout << numeric_limits<int32_t>::max() << endl;
	cout << numeric_limits<int64_t>::max() << endl;

	cout << "signed 음수 최솟값" << endl;
	cout << (int)numeric_limits<int8_t>::min() << endl;
	cout << (int)numeric_limits<int16_t>::min() << endl;
	cout << numeric_limits<int32_t>::min() << endl;
	cout << numeric_limits<int64_t>::min() << endl;

	// 2의 보수를 취하는 이유
	// 덧샘과 뺄셈이 같은 방법으로 연산이 가능
	// 6-5=1
	// 00000110 - 0000101(보수)
	// 00000110 - 1111011
	// 결과 0000001 = 1

	// size를 초과하는 경우 = Overflow
	uint32_t num32 = (int)numeric_limits<uint32_t>::max();
	uint32_t num32_ = num32 + 1;
	uint32_t num32__ = num32_ + 1;

	cout << "over flow" << endl; // 
	cout << num32 << endl; // 
	cout << num32_ << endl; // 0
	cout << num32__ << endl; // 1

	int32_t n32 = (int)numeric_limits<int32_t>::max();
	int32_t n32_ = n32 + 1;
	int32_t n32__ = n32_ + 1;

	cout << n32 << endl;
	cout << n32_ << endl;
	cout << n32__ << endl;

	// 강남스타일 2147483647 오버플러우 -2147483646
	
	// Underflow
	// 0 - 1 => 43억어쩌고 (32비트)

	uint32_t minNum32 = numeric_limits<uint32_t>::min();

	cout << minNum32 << endl;
	cout << minNum32 - 1 << endl;
}