
#include<iostream>
#include "PersonHeader.h"
using namespace std; 

// 함수 정의
// PersonHeader.h에 선언되어 있어서 PersonHeader.h를 포함하는파일에서 어디든지 foo를 호출 할 수 있음
void foo() {
	PersonHeader p(50.5f, 155.5f, "foo : daniel");
	p.print();
}

// 클래스 정의
// 클래스의 선언은 헤더파일에서하고, 클래스 내 함수는 외부에서 정의할 수 있음
PersonHeader::PersonHeader(float w, float h, const std::string& name) : _w(w), _h(h), _name(name) {
	std::cout << "PersonHeader클래스 생성" << "\n";
}
void PersonHeader::print() {
	std::cout << _name << "\n";
}
void PersonHeader::sum(int _w, int _h) {
	int a = _w * _h;
	return;
}
