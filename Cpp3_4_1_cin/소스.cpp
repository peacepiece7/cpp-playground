#include <iostream>
#include <limits>
int main() {
	int a;
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
	std::cout << "문자열 ab입력 ㄱㄱ" << std::endl;

	std::cin >> ch;
	std::cout << ch << std::endl;

	std::cin.ignore();
	
	std::cin >> ch;
	std::cout << ch << std::endl;

	// cin도 길이 지정가능
	std::cout << "문자열 abc입력 ㄱㄱ" << std::endl;

	std::cin >> ch;
	std::cout << ch << std::endl;

	std::cin.ignore();

	std::cin >> ch;
	std::cout << ch << std::endl;

	// cin도 길이 지정가능
	std::cout << "문자열 abc입력 ㄱㄱ" << std::endl;

	std::cin >> ch;
	std::cout << ch << std::endl;

	std::cin.ignore(2);

	std::cin >> ch;
	std::cout << ch << std::endl;

	// cin 몇개를 받던 하나만 
	std::cout << "문자열 abcasdajsds입력 ㄱㄱ 몇개를 받던 하나만 " << std::endl;

	std::cin >> ch;
	std::cout << ch << std::endl;
	std::cin.ignore(numeric_limits<streamsize>::max();
	std::cin >> ch;
	std::cout << ch << std::endl;
}