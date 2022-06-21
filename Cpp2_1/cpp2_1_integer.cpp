#include <iostream>
using namespace std;
int main() 
{
	// unsigned 
	// �� ������ �� ���ϴ� ���� �𸣰���, �Ƹ��� �ڷ����� 0 �Ǵ� 1�� ����Ǵµ� ���������� ��� Ǧ���Ѵ�~ �̷����ε�
	uint8_t num0 = 1; // base 10
	uint16_t num1 = 020; //base 8 
	uint32_t num2 = 0xff; // base 16
	uint32_t num3 = 0b0101; // base 2 
	
	std::cout << num0 << std::endl;
	std::cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;

	// 8  bit max value  = 255 (2**8 -1) (ĳ���� �ɷ�ġ 255 ����� ����)
	// 16  bit max value = 65535 (2**16 -1) (����ġ �ƽ� 65535)
	// 32 bit max valu e = 4294967295 (2**32 -1)
	cout << "unsigned �ִ밪" << endl;
	cout << (int)numeric_limits<uint8_t>::max() << endl;
	cout << (int)numeric_limits<uint16_t>::max() << endl;	
	cout << numeric_limits<uint32_t>::max() << endl;	
	cout << numeric_limits<uint64_t>::max() << endl;

	// signed, ���� ������ ��Ʈ(MSB : Most Significant Bit) �� 0 ���, 1 ����
	// MSB�� ��ȣ�ϱ� n-1 �������� ǥ������
	cout << "signed ���� �ִ밪" << endl;
	cout << (int)numeric_limits<int8_t>::max() << endl;
	cout << (int)numeric_limits<int16_t>::max() << endl;
	cout << numeric_limits<int32_t>::max() << endl;
	cout << numeric_limits<int64_t>::max() << endl;

	cout << "signed ���� �ּڰ�" << endl;
	cout << (int)numeric_limits<int8_t>::min() << endl;
	cout << (int)numeric_limits<int16_t>::min() << endl;
	cout << numeric_limits<int32_t>::min() << endl;
	cout << numeric_limits<int64_t>::min() << endl;

	// 2�� ������ ���ϴ� ����
	// ������ ������ ���� ������� ������ ����
	// 6-5=1
	// 00000110 - 0000101(����)
	// 00000110 - 1111011
	// ��� 0000001 = 1

	// size�� �ʰ��ϴ� ��� = Overflow
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

	// ������Ÿ�� 2147483647 �����÷��� -2147483646
	
	// Underflow
	// 0 - 1 => 43���¼�� (32��Ʈ)

	uint32_t minNum32 = numeric_limits<uint32_t>::min();

	cout << minNum32 << endl;
	cout << minNum32 - 1 << endl;
}