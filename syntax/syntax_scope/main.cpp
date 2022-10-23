#include<iostream>
enum struct RequestType {
	Login,Register,Update
};
static int x; // 1. file ����
// static extern�� ������ ����� �޸𸮰� �������� ����
int get();

namespace CompanyA {
	int num = 10;
}
namespace CompanyB { // �ܺ� num��  extern num
	 extern int num = 1000;
}

int main() {
	using std::cout;
	using std::cin;
	cout << "1. extern int x; (���� ����)" << "\n";
	// ��� ���Ͽ��� �������� ����� ���� x
	x = 200;
	std::cout << get() << "\n";

	cout << " 2. scoped enumeration" << "\n";
	// ���� ������ ::�� ����ؼ� ���� ��������
	RequestType::Login; 

	cout << "3. namespace std�� �ִ� ����" << "\n";
	// �ٸ� ȸ��� �����ҋ� int num�� ��ġ��?
	std::cout << CompanyA::num << "\n";
	std::cout << CompanyB::num << "\n";
	// ���ٴٵ� ���̺귯���� std::�� ����� ������ ������ �츮�� ���� �Լ��� ��ĥ���..

	// �̷��� ���̰� ���� �Լ��� ����Ҽ��� ����
	using std::cout;
	using std::cin;


	

	
	cout << "�ڵ�����, ������ ����� ������ (static, extern)" << "\n";
	cout << "��������, ������ ����� �������� ���� �ܺο��� ���� �Ұ��� {int a;}" << "\n";
	cout << "��������, �̸��� ����, new����� ����� �ݵ�� ����������� int a = new int[10]; free(a)" << "\n";

	// static, ����� �ѹ��� �ʱ�ȭ ��, �������� ���� ���� �������� ����
	for (int i = 0; i < 5; i++) {
		static int a = 1;
		a++;
		cout << a << " ";
	}
	// a => error �޸𸮰� �������� �ʾ����� ���� ������ ���� �Ұ���

	// ��������, �̸��� ���� ���⋚���� newŰ����� ���� ������ �Ҵ��ϰ�, �ش� ��ġ�� ����Ű�� �ּҸ� ������ ����
	// �ּҸ� �Ҿ������ �����Ҽ�����
	int* c = new int[10];
}
