#pragma warning(disable : 4996)
#include<iostream>
#include<iomanip>



using namespace std;

int main() {
	cout << '1' << endl;
	cout << 1 << endl;
	cout << 'a' << endl;
	// �� �ڵ�� ���������� �Ʒ� �ڵ带 ����
	operator<<(cout, 'a');
	cout << (char)97 << endl;
	cout << 97 << endl;

	cout.put('a');
	cout.put('\n');
	cout.write("hello, world!", 5);
	// ���� #���� ä���
	cout.width(10);
	cout.fill('#');
	cout << 1 << endl;

	// ���е� 
	float num = 0.1234567f;
	cout << num << endl; //  0.123457 �Ҽ��� 6�ڸ�� �����ϱ� �ݿø���

	cout.precision(2);
	cout << num << endl;

	cout.precision(10);
	cout << num << endl; // �������� 0.1234567�� ��ȯ�� �����ϱ� �ٻ�ġ�� ����� �׷��� 0.123456016 (������ �޸𸮿� 2������ ����� ����)

	// flag


	// +��ȣ �߰�
	cout.setf(ios_base::showpos); // show positive
	cout << 1 << endl;
	cout << 2 << endl;
	cout.unsetf(ios_base::showpos);
	cout << 3 << endl;

	// 0, 1 => true, false
	cout << true << endl;
	cout << false << endl;
	cout.setf(ios_base::boolalpha);
	cout << true << endl;
	cout << false << endl;

	// ����
	cout.width(10);
	cout << -10 << 20 << endl;

	// internel
	cout.setf(ios_base::right, ios_base::adjustfield);
	cout.width(10);
	cout.fill('\*');
	cout << -10 << 20 << endl;

	cout.setf(ios_base::left, ios_base::adjustfield);
	cout.width(10);
	cout.fill('\*');
	cout << -10 << 20 << endl;

	cout.setf(ios_base::internal, ios_base::adjustfield);
	cout.width(10);
	cout.fill('\*');
	cout << -10 << 20 << endl;

	// base
	cout.setf(ios_base::hex, ios_base::basefield);
	cout.width(10);
	cout.fill('\*');
	cout << 16 << endl;

	cout.setf(ios_base::oct, ios_base::basefield);
	cout.width(10);
	cout.fill('\*');
	cout << 16 << endl;

	cout.setf(ios_base::dec, ios_base::basefield);
	cout.width(10);
	cout.fill('\*');
	cout << 16 << endl;

	// �Լ��ϱ� �Ʒ�ó���� ok
	std::cout << std::hex << 16 << endl;
	std::hex(std::cout);
	cout << 24 << endl;
	cout << setw(10) << setfill('@') << setprecision(1) << showpos << 1.1f << endl;
	cout << setw(10) << setfill('@') << setprecision(1) << showpos << 0.1f << endl;
	cout << setw(10) << setfill('@') << setprecision(10)<< showpos << 1.1f << endl;
 
	freopen("output.txt", "w", stdout);
	cout << setw(10) << setfill('@') << setprecision(10) << showpos << 1.1f << endl;
}
