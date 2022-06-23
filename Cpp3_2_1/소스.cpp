#pragma warning(disable : 4996)
#include <cstdio>
#include<iostream>

int main() {
	// 1.
	// a 만 입력해도 b가 자동으로 받아짐 
	// \n = acil 10임, scanf가 \n을 받아서 엔터까지 치니까 다음단어가 씹혀버림
	// ab를 하면 두번쨰값까지 입력이 됨, scanf가 a를 받으면 엔터를 치니까그럼
	char cch;
	scanf("%c", &cch);
	// %c는 문자열 출력

	printf("1. %c", cch);

//	cch = getchar();
//	printf("%c\n", cch);

	while (getchar() != '\n');
	// \n이 나올 떄까지 getchar가 반복됨 (엔터 칠때까지 문자열을 받는 다는 뜻)

	scanf("#c", &cch);
	// %d는 받은 데이터를 그대로 출력
	printf("2. %d", cch);
	printf("3. %c", cch);

	// 2.
	std::cout << "char => char || ascil" << std::endl;
	char ch;
	scanf("%c", &ch);
	printf("%c\n", ch);
	printf("%i\n", ch);

	// 3.
	// float
	float f0; // 4btye
	double d0, d1; // 8btye
	// scanf = & => 주소로 넘겨줌을 말함 (포인터), double = 8btye, float = 4btye, 넘겨줄 때 %lf %f로 double float 구분함
	// printf = double형으로 형변환됨
	std::cout << "1.0 1.0 1.0" << std::endl;
	scanf("%lf %lf %f\n", &d0, &d1, &f0);
	printf("%lf %lf %f\n", d0, d1, f0);


//	float ff0;
//	scanf("%lf\n", &ff0); // 8byte로 4byte를 받음 이렇게하면 에러남
//	printf("%f", f0);

//	int num0;
//	std::cout << "10" << std::endl;
//	scanf("%o\n", &num0); // octar
//	scanf("%d", num0);

//	int num1;
//	std::cout << "10" << std::endl;
//	scanf("%x\n", &num1);
//	scanf("%d\n", num1);

}