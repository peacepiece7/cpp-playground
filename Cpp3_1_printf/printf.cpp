#include <cstdio> // c standard input output
// stdio.h c
int main()
{
	// Prints formatted output to stdout(stadard output, 표준 출력)
	// 형식 문자열
	// %d %i 정수
	// %u unsigned
	printf("hello %d\n", 10);
	printf("%d + %d = %i\n", 2, 2, 3);
	printf("%u\n", -1); // unsigned integer
	printf("%hhu\n", -1); // unsigned charecter

	printf("%010d\n", 1); // 전체 개수를 10으로 맞춰줌
	printf("%010d\n", -1);
	printf("%010f\n", 1.1); // 소수점 6자리 수까지 표현
	printf("%010f\n", -1.1);

	// 메모리에 10개의 칸을 만들고 빈 칸에 0을 넣음
	printf("%010d\n", 1); 
	printf("%010d\n", -1);
	printf("%010.1f\n", 1.1);
	printf("%010.1f\n", -1.1);

	printf("%10d\n", 1);
	printf("%10d\n", -1);
	printf("%10f\n", 1.1);
	printf("%10f\n", -1.1);
	printf("%10.1f\n", 1.1);

	printf("%-10da\n", 1);
	printf("%-10da\n", -1);
	printf("%-10fa\n", 1.1);
	printf("%-10fa\n", -1.1);
	printf("%da\n", 1);

	printf("%10da\n", 1);
	printf("%10da\n", -1);
	printf("%10fa\n", 1.1);
	printf("%10fa\n", -1.1);

	printf("%%10da\n", 1);
	printf("%%10da\n", -1);
	printf("%%10fa\n", 1.1);
	printf("%%10fa\n", -1.1);

	}