#include <iostream>
#include <limits>
int main() {
	int a;
	std::cin >> a; // cpp������ �ּ� ������ ���ؼ� cin�Լ��� a�� �ּҸ� �����ش�
	// scanf("%d", &a); // �Լ� �ۿ��� �ּҰ��� �ٿ���� scanf���ο��� ����� �� �ִ�(&�� ������ �ּҰ��� �����ٴ� ��ȣ)
	std::cout << a;

	// cin => ���н� default 0
	// scanf => ���н� �����Ⱚ -912309214 �̷� �� ���� 
	std::cout << "���ڿ� ab, a, b�Է� ����" << std::endl;
	// ���н� ���ۿ� ���� ����
	// ab�Է½� ab\n�� �Էµǰ� \n�� ���ۿ� ���Ƽ� ���� ��ɿ��� ����Ǵ� ������ ����
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
	std::cout << "���ڿ� ab�Է� ����" << std::endl;

	std::cin >> ch;
	std::cout << ch << std::endl;

	std::cin.ignore();
	
	std::cin >> ch;
	std::cout << ch << std::endl;

	// cin�� ���� ��������
	std::cout << "���ڿ� abc�Է� ����" << std::endl;

	std::cin >> ch;
	std::cout << ch << std::endl;

	std::cin.ignore();

	std::cin >> ch;
	std::cout << ch << std::endl;

	// cin�� ���� ��������
	std::cout << "���ڿ� abc�Է� ����" << std::endl;

	std::cin >> ch;
	std::cout << ch << std::endl;

	std::cin.ignore(2);

	std::cin >> ch;
	std::cout << ch << std::endl;

	// cin ��� �޴� �ϳ��� 
	std::cout << "���ڿ� abcasdajsds�Է� ���� ��� �޴� �ϳ��� " << std::endl;

	std::cin >> ch;
	std::cout << ch << std::endl;
	std::cin.ignore(numeric_limits<streamsize>::max();
	std::cin >> ch;
	std::cout << ch << std::endl;
}