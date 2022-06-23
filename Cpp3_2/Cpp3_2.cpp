
#pragma warning(disable :4996)
// c4996에러를 막음 (cpp에서 보안 이슈 scanf
#include <cstdio>
#include <iostream>

int main() {
    
	std::cout << "숫자 입력 엔터 => n은 1개" << std::endl;
	int num = 0;
	// scanf("%d", num);
	int n= scanf("%d", &num); // scanf는 c에서 제공하는 함수, c에서 제공하는 함수에 외부 변수를 할당하려면 &를 써야함 (외부 참조 주소를 넘김)
	printf("%d\n", n);

	std::cout << "숫자 문자 입력 엔터 => n은 2개" << std::endl;
	// a a = 0개 첫 번째에서 에러 
	// 1 a = 2개
	
	int num1 = 0;
	char ch;
	int n1 = scanf("%d %c", &num1, &ch);
	printf("%d\n", n1);
	
	std::cout << "if 숫자 입력 엔터 => n은 1개" << std::endl;
	int num2;
	if (scanf("%d", &num2) != 0)
		printf("%d\n", num2);
	std::cout << "숫자 + 숫자 = 숫자 => 출력" << std::endl;
	int nn0, nn1, nn2;
	scanf("%d + %d = %d", &nn0, &nn1, &nn2);
	printf("%d 더하기 %d 는 %d\n", nn0, nn1, nn2);

	std::cout << "입력 : 0x16(hax) = 16(decimal)" << std::endl;
	int in0;
	scanf("%i", &in0);
	printf("%i\n", in0);

	std::cout << "입력 : 010(octar) = 8(decimal)" << std::endl;
	int in1;
	scanf("%i", &in1);
	printf("%i\n", in1);

	std::cout << "문자입력 = 아스키 || 문자 출력" << std::endl;
	char chh11;
	scanf("%c", &chh11);
	printf("%c\n", chh11);
	printf("%i\n", chh11);
}
