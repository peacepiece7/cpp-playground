#include <cstdio> // c standard input output
// stdio.h c
int main()
{
	// Prints formatted output to stdout(stadard output, ǥ�� ���)
	// ���� ���ڿ�
	// %d %i ����
	// %u unsigned
	printf("hello %d\n", 10);
	printf("%d + %d = %i\n", 2, 2, 3);
	printf("%u\n", -1); // unsigned integer
	printf("%hhu\n", -1); // unsigned charecter

	printf("%010d\n", 1); // ��ü ������ 10���� ������
	printf("%010d\n", -1);
	printf("%010f\n", 1.1); // �Ҽ��� 6�ڸ� ������ ǥ��
	printf("%010f\n", -1.1);

	// �޸𸮿� 10���� ĭ�� ����� �� ĭ�� 0�� ����
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