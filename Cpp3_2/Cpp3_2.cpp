
#pragma warning(disable :4996)
// c4996������ ���� (cpp���� ���� �̽� scanf
#include <cstdio>
#include <iostream>

int main() {
    
	std::cout << "���� �Է� ���� => n�� 1��" << std::endl;
	int num = 0;
	// scanf("%d", num);
	int n= scanf("%d", &num); // scanf�� c���� �����ϴ� �Լ�, c���� �����ϴ� �Լ��� �ܺ� ������ �Ҵ��Ϸ��� &�� ����� (�ܺ� ���� �ּҸ� �ѱ�)
	printf("%d\n", n);

	std::cout << "���� ���� �Է� ���� => n�� 2��" << std::endl;
	// a a = 0�� ù ��°���� ���� 
	// 1 a = 2��
	
	int num1 = 0;
	char ch;
	int n1 = scanf("%d %c", &num1, &ch);
	printf("%d\n", n1);
	
	std::cout << "if ���� �Է� ���� => n�� 1��" << std::endl;
	int num2;
	if (scanf("%d", &num2) != 0)
		printf("%d\n", num2);
	std::cout << "���� + ���� = ���� => ���" << std::endl;
	int nn0, nn1, nn2;
	scanf("%d + %d = %d", &nn0, &nn1, &nn2);
	printf("%d ���ϱ� %d �� %d\n", nn0, nn1, nn2);

	std::cout << "�Է� : 0x16(hax) = 16(decimal)" << std::endl;
	int in0;
	scanf("%i", &in0);
	printf("%i\n", in0);

	std::cout << "�Է� : 010(octar) = 8(decimal)" << std::endl;
	int in1;
	scanf("%i", &in1);
	printf("%i\n", in1);

	std::cout << "�����Է� = �ƽ�Ű || ���� ���" << std::endl;
	char chh11;
	scanf("%c", &chh11);
	printf("%c\n", chh11);
	printf("%i\n", chh11);
}
