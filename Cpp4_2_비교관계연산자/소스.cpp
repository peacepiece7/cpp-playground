#include <iostream>
#include <compare>

using namespace std;
int main() {
	int num10 = 10, num11(11);
	printf("�Ʒ��� num10 �� 11�� �Ҵ�, ==�� =�� ���� ���ϱ�");
	if (num10 = num11)
		printf("%i", num10);

	int num1 = 1, num0(0);
	printf("==, <=, >= , <, >, != ����\n");
	// ������Ʈ => �Ӽ� => �Ϲ� => C++ ���ǥ�� �ʾ��� ������� ���� �� �Ʒ��ڵ�(<=>) ��밡��
	// <=> (what, how)
	cout.setf(ios_base::boolalpha);
	// 1 �� 1�� ����� �? => ����� == 0 => true
	cout << ((1 <=> 1) == 0) << endl;

	// �̰� ���� �𸣰���, ����� �� true�� ���� �ϴ� 20�� �߰��ƴٴ� �Ÿ� �˰� �ѱ���
	cout << ((2 <=> 1) > 0) << endl;
	cout << ((1 <=> 2) > 0) << endl;
	cout << ((1 <=> 2) >= 0) << endl;
	cout << is_eq(1 <=> 1) << endl;;
	cout << is_neq(1 <=> 2) << endl;;
	cout << is_lt(1 <=> 2) << endl;;
	cout << is_lteq(1 <=> 2) << endl;;
	cout << is_gt(2 <=> 1) << endl;; 

	cout << typeid(1 <=> 1).name() << endl; // string odering (����)
	cout << typeid(1 <=> 1.0).name() << endl; // equivalent (���� �� �ƴϰ� ������)
	cout << ((1 <=> 1.0) == partial_ordering::equivalent) << endl; // true
	cout << ((1 <=> 1.0) == strong_ordering::equal) << endl; // false
	cout << ((1 <=> 1) == strong_ordering::equal) << endl; // true


}