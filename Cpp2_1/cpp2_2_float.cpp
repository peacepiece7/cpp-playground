#include <iostream>
#include <cfloat>
using namespace std;
int main()
{
	// type specifier     width    exponent(지수)   mantissa(가수)
	// float				32			8				23
	// double				64			11				52
	// long double		 64 ~ 128		

	float num0 = 1.0;
	double num1 = 1.0;
	long double num2 = 1.0;

	// 플랫폼바다 타입별 비트가 4 8 8, 4 8 16등 다름
	// 접미가사 없으면 double임 형 변환되고 있음
	cout << sizeof(num0) << endl; 
	cout << sizeof(num1) << endl; 
	cout << sizeof(num2) << endl;

	// 접미가사 없으면 double임 형 변환되고 있음
	cout << sizeof(1.0F) << endl;
	cout << sizeof(1.0) << endl;
	cout << sizeof(1.0L) << endl;

	// -118.625
	// -1110110.101
	// 가수부가 앞자리 1인 자리로 맞추주기 (6번)
	// -1110110.101 * 10**6(2)
	// 매모리 나타내기
	// 1 (부호) 10000101 (지수부) 11011010100000000000000 (가수부23)

	// 0.231689453125
	// 0.001110110101
	// 가수부가 앞자리 1인 자리로 맞추주기 (-3번)
	// 1.110110101 * 10**-3(2)
	// 매모리 나타내기
	// 지수부 127 = 0
	// 127-3
	// 1111100 = 124 (앞에 0이 기본으로 붙음 그래서 01111100) 
	// 0 (부호) 01111100 (지수부) 11011010100000000000000 (가수부23)

	unsigned int fnum0;
	float fnum1 = -118.625;
	// 메모리 상 value 카피
	memcpy(&fnum0, &fnum1, sizeof(fnum1));

	// fnum1 = fnum0 => 이렇게하면 케스팅?이라서 다른 결과
	cout << fnum0 << endl; // 3270328320 (메모리 레이아웃, base 10임, base 2로 바꾸면 위 주석의 결과와 같음)
	cout << fnum1 << endl; // -118.625

	unsigned int fnum2;
	float fnum3 = 0.231689453125f;

	memcpy(&fnum2, &fnum3, sizeof(fnum3));

	cout << fnum2 << endl; 
	cout << fnum3 << endl;

	// 부동 소수점 주의 사항

	cout << "floate number caution" << endl;

	float t0 = 0.1f;
	float t1 = 0.02f * 5.0f;

	// 10진수 0,1은 2진수로 표현할 수 없다.
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
	
	// window는 double, long double 8비트지만 다른 곳은 0.1 , 0.1L도 다르게나옴
	cout << 0.1f << endl;
	cout << 0.1 << endl;
	cout << 0.1L << endl;

	// epsilon 비교 (epsilon 1보다 엄청 조금 더 큰 수) 
	// 1과 1보다 가장작은 수의 차이 1.00000000000000000000000000001 -1 = FLT_EPSLON
	if (fabsf(0.1f - 0.1) <= FLT_EPSILON)
	cout << "Equl 5" << endl;

	// 오차가 앱실론보다 작을 때 맞다고 하는 거임, for 문돌리면 오차가 커지기 때문에 결국 안쓰는게 좋음
	float n0 = 1.0f;
	float n1 = 1.0;
	for (int i = 0; i < 1000; i++)
		n0 = n0 + 0.001;
	if (n0 == n1)
		cout << "Equal 6" << endl;
	if (fabsf(n0 - n1) <= FLT_EPSILON)
		cout << "Equal 7" << endl;

	// 127 = 0이니까 001111111 = 1임, 0 * 23개 해서 완벽한 1생성하기
	// 0b, 0(부호), 01111111
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

	// 32비트 기준
	// 0011,1111,1000,0000,0000,0000,0000,0000 = 1.0(2)
	// 0011,1111,1000,0000,0000,0000,0000,0001 = 1과 가장 가깝고 작은 수 

	// 2^-23 구하기 (127 -23 = 104)
	// 0011,0100,0 000,0000,0000,0000,0000,0000 = 1.0(2) * 10^-23(2)

	int ab0 = 1.0f;
	unsigned int ab1 = 0b00110100000000000000000000000000; // 1과 가장 가깝고 작은 수 
	
	// 금융권아니면 쓸 일 없을 듯
	// 그 수가 표현할 수 있는 가장 작은 수 보다 작은 수
	// 메모리를 넘어서는 수는 무시가 됨

	float nnn0 = FLT_MAX;

	float nnn1;
	memcpy(&nnn1, &nnn0, sizeof(nnn0));
	cout << nnn1 << endl;

	// 몰라.. nan왜 안나와 가수부 23개 지수부 8개.. 
	// 가수부 전부 0이면 infinit 1이면 nan
	float nnn2 = 0b01111111100000000000000000000000;
	float nnn3;

	memcpy(&nnn3, &nnn2, sizeof(nnn2));
	cout << nnn3 << endl;

	float fltMin = FLT_MIN;
	// 0000,0000,1000,0000,0000,0000,0000,0000,0000 = 10^-126(2)
	float fltTrueMin = FLT_TRUE_MIN;
	// 0000,0000,0000,0000,0000,0000,0000,0000,0001 = 10^-126(2) * 10^-23(2) = 10^-149(2)
   
}	
