#pragma warning(disable : 4996)
#include <iostream>
#include <limits>

using namespace std;

int main() {




	char bb = 'c';


	int a;
	std::cout << "���� �ϳ��� �Է� ���� (��ŵ�� �����ϳ� ����) " << std::endl;
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
	std::cout << "���ڿ� ab, b�Է� ���� cin.ignore�� �� ���� ����" << std::endl;

	std::cin >> ch;
	std::cout << ch << std::endl;

	std::cin.ignore();
	
	std::cin >> ch;
	std::cout << ch << std::endl;

	// cin�� ���� ��������
	std::cout << "���ڿ� abc�Է� ����, cin.ignore�� �ѱ��ڸ� �����ؼ� �� �� ° �Է°� �ٷ� ����" << std::endl;

	std::cin >> ch;
	std::cout << ch << std::endl;

	std::cin.ignore();

	std::cin >> ch;
	std::cout << ch << std::endl;

	// cin�� ���� ��������
	std::cout << "���ڿ� abc, b�Է� ���� �̹��� �� ���� ����" << std::endl;

	std::cin >> ch;
	std::cout << ch << std::endl;

	std::cin.ignore(2);

	std::cin >> ch;
	std::cout << ch << std::endl;

	// cin ��� �޴� �ϳ��� 
	std::cout << "���ڿ� abcasdajsds, b�Է� ���� ��� �޴� �ϳ���, ���๮�ڰ� ���� ������ �����ϰ� �Է��� ����" << std::endl;

	std::cin >> ch;
	std::cout << ch << std::endl;

	std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

	std::cin >> ch;
	std::cout << ch << std::endl;

	// ���ڸ� �޾ƾ��ϴµ�, ���ڿ��� �Է��ϸ�?
	std::cout << "���ڸ� �Է°����� �޴µ�, ���ڿ� �Է��ϸ�? ���ڿ� c �Է� " << std::endl;

	int num;
	std::cin >> num;
	std::cout << "���ڿ��� �Է¹޾Ƽ� 0(���н� �Ҹ��� ��)���� ��ȯ" << std::endl;
	std::cout << num << endl;

	std::cout << std::cin.fail() << "\ncin.fail() => ���н� 1, ������ 0�� ��ȯ" << std::endl;
	if (std::cin.fail())
		// �ʱ�ȭ
		std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "���� ���ڸ� �Է����ݽô�. 1�� �Է�" << std::endl;
	std::cin >> num;
	std::cout << num << std::endl;

	std::cout << "�Ҹ��� true, false�� �޾ƺ��ô�. �÷��� ���� �� ture�� �Է� => 0(false) true�� ���ڿ� ����� " << std::endl;

	bool b;
	std::cin >> b;
	std::cout << b << std::endl;
	
	std::cin.clear();

	std::cin.setf(std::ios_base::boolalpha);

	std::cin >> b;
	std::cout << b << std::endl;
	std::cout << "boolalpha�� �����߽��ϴ�. true�� ������ �����־ ������ �˾Ƽ� ����˴ϴ�." << std::endl;
	std::cout << "cin.clear�� ����� b������ �̹� ���� �����־ ���� �Ʒ��� �������� ������ ���� ���μ����� ����˴ϴ�." << std::endl;


	cout << "���� 10 �Է� , 16���� ��ȯ" << endl;
	int num1;
	cin.setf(ios_base::hex, ios_base::basefield); // basefield�� 8 10 16���� �� ���� (���� ���� Ȯ���غ���)
	cin >> num1;
	cout << num1 << endl;

	cout << "�Ʒ��� ���� hex >> num2�� ������ ���� int�� 256���� ǥ���˴ϴ�." << endl;
	int num2;
	cin >> hex >> num2;
	cout << num2;


	cout << "\nfreopen���� �Է°��� �ҷ��ͺ��ô�. �˾Ƽ� input.txt�� �н��ϴ�" << endl;
	cin.unsetf(ios_base::hex);
	//	cin.setf(ios_base::dec);
	freopen("input.txt", "r", stdin);
	int numm;
	cin >> numm;
	cout << numm << endl;
}