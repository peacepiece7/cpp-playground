#pragma warning(disable : 4996)
#include <iostream>
#include <limits>

using namespace std;

int main() {




	char bb = 'c';


	int a;
	std::cout << "숫자 하나만 입력 ㄱㄱ (스킵시 문자하나 ㄱㄱ) " << std::endl;
	std::cin >> a; // cpp에서는 주소 참조를 통해서 cin함수에 a의 주소를 보내준다
	// scanf("%d", &a); // 함수 밖에서 주소값을 붙여줘야 scanf내부에서 사용할 수 있다(&가 변수의 주소값을 보낸다는 기호)
	std::cout << a;

	// cin => 실패시 default 0
	// scanf => 실패시 쓰래기값 -912309214 이런 거 나옴 
	std::cout << "문자열 ab, a, b입력 ㄱㄱ" << std::endl;
	// 실패시 버퍼에 남는 문제
	// ab입력시 ab\n이 입력되고 \n이 버퍼에 남아서 다음 명령에서 실행되는 문제가 있음
	char ch;
	std::cin >> ch;
	std::cout << ch << std::endl;

	std::cin >> ch;
	std::cout << ch << std::endl;

	std::cin >> ch;
	std::cout << ch << std::endl;

	std::cin >> ch;
	std::cout << ch << std::endl;

	// cin ignore
	std::cout << "문자열 ab, b입력 ㄱㄱ cin.ignore는 한 글자 무시" << std::endl;

	std::cin >> ch;
	std::cout << ch << std::endl;

	std::cin.ignore();
	
	std::cin >> ch;
	std::cout << ch << std::endl;

	// cin도 길이 지정가능
	std::cout << "문자열 abc입력 ㄱㄱ, cin.ignore가 한글자만 무시해서 두 번 째 입력값 바로 나옴" << std::endl;

	std::cin >> ch;
	std::cout << ch << std::endl;

	std::cin.ignore();

	std::cin >> ch;
	std::cout << ch << std::endl;

	// cin도 길이 지정가능
	std::cout << "문자열 abc, b입력 ㄱㄱ 이번엔 두 글자 무시" << std::endl;

	std::cin >> ch;
	std::cout << ch << std::endl;

	std::cin.ignore(2);

	std::cin >> ch;
	std::cout << ch << std::endl;

	// cin 몇개를 받던 하나만 
	std::cout << "문자열 abcasdajsds, b입력 ㄱㄱ 몇개를 받던 하나만, 개행문자가 나올 때까지 무시하고 입력을 받음" << std::endl;

	std::cin >> ch;
	std::cout << ch << std::endl;

	std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

	std::cin >> ch;
	std::cout << ch << std::endl;

	// 숫자를 받아야하는데, 문자열을 입력하면?
	std::cout << "숫자를 입력값으로 받는데, 문자열 입력하면? 문자열 c 입력 " << std::endl;

	int num;
	std::cin >> num;
	std::cout << "문자열을 입력받아서 0(실패시 불리언 값)으로 반환" << std::endl;
	std::cout << num << endl;

	std::cout << std::cin.fail() << "\ncin.fail() => 실패시 1, 성공시 0을 반환" << std::endl;
	if (std::cin.fail())
		// 초기화
		std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "이제 숫자를 입력해줍시다. 1을 입력" << std::endl;
	std::cin >> num;
	std::cout << num << std::endl;

	std::cout << "불리언 true, false로 받아봅시다. 플래그 세팅 전 ture를 입력 => 0(false) true를 문자열 취급함 " << std::endl;

	bool b;
	std::cin >> b;
	std::cout << b << std::endl;
	
	std::cin.clear();

	std::cin.setf(std::ios_base::boolalpha);

	std::cin >> b;
	std::cout << b << std::endl;
	std::cout << "boolalpha를 설정했습니다. true가 변수에 남아있어서 요기까지 알아서 실행됩니다." << std::endl;
	std::cout << "cin.clear를 지우면 b변수가 이미 값이 남아있어서 고대로 아래로 내려오고 에러가 나서 프로세스가 종료됩니다." << std::endl;


	cout << "숫자 10 입력 , 16진수 반환" << endl;
	int num1;
	cin.setf(ios_base::hex, ios_base::basefield); // basefield가 8 10 16진수 를 받음 (정의 가서 확인해보기)
	cin >> num1;
	cout << num1 << endl;

	cout << "아래와 같이 hex >> num2의 구조도 가능 int라 256까지 표현됩니다." << endl;
	int num2;
	cin >> hex >> num2;
	cout << num2;


	cout << "\nfreopen으로 입력값을 불러와봅시다. 알아서 input.txt를 읽습니다" << endl;
	cin.unsetf(ios_base::hex);
	//	cin.setf(ios_base::dec);
	freopen("input.txt", "r", stdin);
	int numm;
	cin >> numm;
	cout << numm << endl;
}