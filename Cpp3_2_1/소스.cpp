#pragma warning(disable : 4996)
#include <cstdio>
#include<iostream>

int main() {
	// 1.
	// a �� �Է��ص� b�� �ڵ����� �޾��� 
	// \n = acil 10��, scanf�� \n�� �޾Ƽ� ���ͱ��� ġ�ϱ� �����ܾ ��������
	// ab�� �ϸ� �ι��������� �Է��� ��, scanf�� a�� ������ ���͸� ġ�ϱ�׷�
	char cch;
	scanf("%c", &cch);
	// %c�� ���ڿ� ���

	printf("1. %c", cch);

//	cch = getchar();
//	printf("%c\n", cch);

	while (getchar() != '\n');
	// \n�� ���� ������ getchar�� �ݺ��� (���� ĥ������ ���ڿ��� �޴� �ٴ� ��)

	scanf("#c", &cch);
	// %d�� ���� �����͸� �״�� ���
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
	// scanf = & => �ּҷ� �Ѱ����� ���� (������), double = 8btye, float = 4btye, �Ѱ��� �� %lf %f�� double float ������
	// printf = double������ ����ȯ��
	std::cout << "1.0 1.0 1.0" << std::endl;
	scanf("%lf %lf %f\n", &d0, &d1, &f0);
	printf("%lf %lf %f\n", d0, d1, f0);


//	float ff0;
//	scanf("%lf\n", &ff0); // 8byte�� 4byte�� ���� �̷����ϸ� ������
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