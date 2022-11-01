#include<iostream>
#include "PersonStatic.h"

// 헤더에서 0으로 초기화하면, PersonStatic헤더를 include할 떄마다 0으로 초기화 됨
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
	// private 변수는 접근 불가능, this가 없기 떄문에
}
