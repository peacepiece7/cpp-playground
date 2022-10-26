#pragma once
class PersonStatic
{
private:
	static int num;
	// static const int num이면 아래와 같이 초기화 가능
	// 1. cinst static int num = 0;
	// 2. PersonStatic.cpp에서 초기화할때 아래와 같이 해야함
	// const int PersonStatic::num = 0; (다른 곳에서 num변경 불가능!)
public:
	static int publicNum;
	PersonStatic();
	void printPerson();
	static void staticPrintPerson();
	// static void staticPrintpersin() const; 불가능, static은 this가 넘어가지 않음
};

