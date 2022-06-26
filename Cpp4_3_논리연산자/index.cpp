#include <iostream>

int main() {
	int num = 0, num1(1);
	int num20 = 20, num30(30);
	// 연산자 우선순위
	if (num == num1 && num20 != num30)
		printf("!!");
	int numt = 1 && 1;
	int numd = (1 &&1 );
	// emplicitly
	if ((num == num1) && (num20 != num30))
		printf("!!");
	// && || 
	printf("length\n");
	bool res = printf("aa");
	std::cout << "result length :" << res << std::endl;

	// short circuit evaluation
	bool result = printf("") && printf("foo");
	std::cout << "short curcit ecalution :" << result << std::endl;

	if (!(false || false))
		printf("not operator");
	std::cout << !10 << std::endl;
}
 