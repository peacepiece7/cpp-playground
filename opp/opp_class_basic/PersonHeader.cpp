
#include<iostream>
#include "PersonHeader.h"
using namespace std; 

// �Լ� ����
// PersonHeader.h�� ����Ǿ� �־ PersonHeader.h�� �����ϴ����Ͽ��� ������ foo�� ȣ�� �� �� ����
void foo() {
	PersonHeader p(50.5f, 155.5f, "foo : daniel");
	p.print();
}

// Ŭ���� ����
// Ŭ������ ������ ������Ͽ����ϰ�, Ŭ���� �� �Լ��� �ܺο��� ������ �� ����
PersonHeader::PersonHeader(float w, float h, const std::string& name) : _w(w), _h(h), _name(name) {
	std::cout << "PersonHeaderŬ���� ����" << "\n";
}
void PersonHeader::print() {
	std::cout << _name << "\n";
}
void PersonHeader::sum(int _w, int _h) {
	int a = _w * _h;
	return;
}
