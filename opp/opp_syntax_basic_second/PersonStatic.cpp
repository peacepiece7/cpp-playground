#include<iostream>
#include "PersonStatic.h"

// ������� 0���� �ʱ�ȭ�ϸ�, PersonStatic����� include�� ������ 0���� �ʱ�ȭ ��
int PersonStatic::num = 0;
int PersonStatic::publicNum = 0;

PersonStatic::PersonStatic() {
	num++;
	publicNum++;
};

void PersonStatic::printPerson() {
	std::cout << num << "\n";
}
void PersonStatic::staticPrintPerson() {
	std::cout << num << " ";
	// private ������ ���� �Ұ���, this�� ���� ������
}
