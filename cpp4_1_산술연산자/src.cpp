#include <iostream>;
using namespace std;

int main() {
	// https://en.cppreference.com/w/c/language/operator_precedence cpp 연산자 우선순위
	cout << "두뇌 풀 가동!" << endl;
	cout << 4 - 20 / 10 << "==" << 2;

	// 왼쪽에서 오른쪽으로 계산 인간의 생각대로
	cout << 2 + 4 - 2 + 8 / 4 * 4 / 2 << endl;

	// 할당 연산자는 오른쪽에서 왼족으로 
	int a, b, c;
	// 10을 c => b => a 순으로 할당 하고 결과를 반환
	// a => return b => return c = 10 같으 느낌임
	a = b = c = 10;

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	// c 스타일 초기화
	int d = 10;
	// cpp 스타일 초기화
	int e(10);

	printf(" 단항 연산자, 이항 연산자 ");
	printf("리터럴은 1이고 1이 -부호를 가짐, 이떄 -는 단항 연산자");
	cout << -1 << endl;

	// 오른쪽에서 왼쪽으로 할당?됨
	cout << +-+-+-1 << endl;
	// --1은 안됨 ++1도 안됨 (++, --도 연산자라서, 증감연산자임 변수 앞에 붙여야함)
	int var = 0;
	cout << "증감연산자 (prefix앞, postfix뒤" << endl;
	cout << ++var << endl;
	// 변수는 증가하지만 original value를 리턴함
	cout << var++ << endl;
	cout << var << endl;

	// 아래의 경우 연산자 - 는 영쪽에 리터럴 값을 가지고, 이항 연산자라고 부름 ^^
	cout << "이항 연산자" << endl;
	cout << 1 - 1 << endl;

	// mod
	int num10 = 10;
	cout << "mod operator" << endl;
	cout << num10 % 7 << endl;
	
	// 할당 연산자
	int num20 = 20;
	cout << "할당 연산자" << endl;
	num20 += 5;
	cout << num20 << endl;
	num20 -= 5;
	cout << num20 << endl;
	num20 *= 5;
	cout << num20 << endl;
	num20 /= 5;
	cout << num20 << endl;
	num20 %= 7;
	cout << num20 << endl;

	// 복합 연산
	printf("복합 연산 ㄱㄱ");
	int mnum = 10;
	cout << ++mnum + mnum++ << endl; // 11 + 11 => 22 
	cout << mnum << endl; // 12

	printf("여기 아래가 14 14가 나오는");
	printf("한 식에서 같은 변수를 두 번 연산하는 행위는 undefined behavior라고, c++에 정의되어 있지 않은 행동임, 그래서 컴파일러마다 다른 결과를 반환 할 위험 이 있음");
	printf("sequence point => 항상 순서대로 오른쪽에서 왼쪽으로  동작하지 않기때문에 연산을 보장하는 특정 포인트, 대표적으로 세미콜론이있음");
	printf("콤마 안의 인수는 순서보장이 안 됨 (sequence point)");
	printf("%d %d\n", ++mnum, ++mnum); // 13 14
	printf("%d\n", mnum); // 14

}