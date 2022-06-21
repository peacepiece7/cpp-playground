#include <iostream>
#include <cfloat>
using namespace std;
int main()
{
	// type specifier     width    exponent(����)   mantissa(����)
	// float				32			8				23
	// double				64			11				52
	// long double		 64 ~ 128		

	float num0 = 1.0;
	double num1 = 1.0;
	long double num2 = 1.0;

	// �÷����ٴ� Ÿ�Ժ� ��Ʈ�� 4 8 8, 4 8 16�� �ٸ�
	// ���̰��� ������ double�� �� ��ȯ�ǰ� ����
	cout << sizeof(num0) << endl; 
	cout << sizeof(num1) << endl; 
	cout << sizeof(num2) << endl;

	// ���̰��� ������ double�� �� ��ȯ�ǰ� ����
	cout << sizeof(1.0F) << endl;
	cout << sizeof(1.0) << endl;
	cout << sizeof(1.0L) << endl;

	// -118.625
	// -1110110.101
	// �����ΰ� ���ڸ� 1�� �ڸ��� �����ֱ� (6��)
	// -1110110.101 * 10**6(2)
	// �Ÿ� ��Ÿ����
	// 1 (��ȣ) 10000101 (������) 11011010100000000000000 (������23)

	// 0.231689453125
	// 0.001110110101
	// �����ΰ� ���ڸ� 1�� �ڸ��� �����ֱ� (-3��)
	// 1.110110101 * 10**-3(2)
	// �Ÿ� ��Ÿ����
	// ������ 127 = 0
	// 127-3
	// 1111100 = 124 (�տ� 0�� �⺻���� ���� �׷��� 01111100) 
	// 0 (��ȣ) 01111100 (������) 11011010100000000000000 (������23)

	unsigned int fnum0;
	float fnum1 = -118.625;
	// �޸� �� value ī��
	memcpy(&fnum0, &fnum1, sizeof(fnum1));

	// fnum1 = fnum0 => �̷����ϸ� �ɽ���?�̶� �ٸ� ���
	cout << fnum0 << endl; // 3270328320 (�޸� ���̾ƿ�, base 10��, base 2�� �ٲٸ� �� �ּ��� ����� ����)
	cout << fnum1 << endl; // -118.625

	unsigned int fnum2;
	float fnum3 = 0.231689453125f;

	memcpy(&fnum2, &fnum3, sizeof(fnum3));

	cout << fnum2 << endl; 
	cout << fnum3 << endl;

	// �ε� �Ҽ��� ���� ����

	cout << "floate number caution" << endl;

	float t0 = 0.1f;
	float t1 = 0.02f * 5.0f;

	// 10���� 0,1�� 2������ ǥ���� �� ����.
	cout.precision(64);
	cout << t0 << endl;
	cout << t1 << endl;
	if (t0 == t1)
		cout << "Equal 1" << endl;
	// float
	if (t0 == 0.1f)
		cout << "Equl 2" << endl;
	// double
	if (t0 == 0.1)
		cout << "Equl 3" << endl;
	// long double
	if (t0 == 0.1L)
		cout << "Equl 4" << endl;
	
	// window�� double, long double 8��Ʈ���� �ٸ� ���� 0.1 , 0.1L�� �ٸ��Գ���
	cout << 0.1f << endl;
	cout << 0.1 << endl;
	cout << 0.1L << endl;

	// epsilon �� (epsilon 1���� ��û ���� �� ū ��) 
	// 1�� 1���� �������� ���� ���� 1.00000000000000000000000000001 -1 = FLT_EPSLON
	if (fabsf(0.1f - 0.1) <= FLT_EPSILON)
	cout << "Equl 5" << endl;

	// ������ �۽Ƿк��� ���� �� �´ٰ� �ϴ� ����, for �������� ������ Ŀ���� ������ �ᱹ �Ⱦ��°� ����
	float n0 = 1.0f;
	float n1 = 1.0;
	for (int i = 0; i < 1000; i++)
		n0 = n0 + 0.001;
	if (n0 == n1)
		cout << "Equal 6" << endl;
	if (fabsf(n0 - n1) <= FLT_EPSILON)
		cout << "Equal 7" << endl;

	// 127 = 0�̴ϱ� 001111111 = 1��, 0 * 23�� �ؼ� �Ϻ��� 1�����ϱ�
	// 0b, 0(��ȣ), 01111111
	unsigned int nnb0 = 0b00111111100000000000000000000000;
	float nnb1;
	memcpy(&nnb1, &nnb0, sizeof(nnb0));

	cout.precision(64);
	cout << "nnb1 " << nnb1 << endl;

	unsigned int nnb2 = 0b00111111100000000000000000000001;
	float nnb3;
	memcpy(&nnb3, &nnb2, sizeof(nnb2));

	cout.precision(64);
	cout << "nnb3 " << nnb3 << endl;


	cout << nnb3 - nnb1 << endl;
	cout << FLT_EPSILON << endl;

	// 32��Ʈ ����
	// 0011,1111,1000,0000,0000,0000,0000,0000 = 1.0(2)
	// 0011,1111,1000,0000,0000,0000,0000,0001 = 1�� ���� ������ ���� �� 

	// 2^-23 ���ϱ� (127 -23 = 104)
	// 0011,0100,0 000,0000,0000,0000,0000,0000 = 1.0(2) * 10^-23(2)

	int ab0 = 1.0f;
	unsigned int ab1 = 0b00110100000000000000000000000000; // 1�� ���� ������ ���� �� 
	
	// �����Ǿƴϸ� �� �� ���� ��
	// �� ���� ǥ���� �� �ִ� ���� ���� �� ���� ���� ��
	// �޸𸮸� �Ѿ�� ���� ���ð� ��

	float nnn0 = FLT_MAX;

	float nnn1;
	memcpy(&nnn1, &nnn0, sizeof(nnn0));
	cout << nnn1 << endl;

	// ����.. nan�� �ȳ��� ������ 23�� ������ 8��.. 
	// ������ ���� 0�̸� infinit 1�̸� nan
	float nnn2 = 0b01111111100000000000000000000000;
	float nnn3;

	memcpy(&nnn3, &nnn2, sizeof(nnn2));
	cout << nnn3 << endl;

	float fltMin = FLT_MIN;
	// 0000,0000,1000,0000,0000,0000,0000,0000,0000 = 10^-126(2)
	float fltTrueMin = FLT_TRUE_MIN;
	// 0000,0000,0000,0000,0000,0000,0000,0000,0001 = 10^-126(2) * 10^-23(2) = 10^-149(2)
   
}	
