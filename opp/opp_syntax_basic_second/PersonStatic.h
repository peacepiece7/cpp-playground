#pragma once
class PersonStatic
{
private:
	static int num;
	// static const int num�̸� �Ʒ��� ���� �ʱ�ȭ ����
	// 1. cinst static int num = 0;
	// 2. PersonStatic.cpp���� �ʱ�ȭ�Ҷ� �Ʒ��� ���� �ؾ���
	// const int PersonStatic::num = 0; (�ٸ� ������ num���� �Ұ���!)
public:
	static int publicNum;
	PersonStatic();
	void printPerson();
	static void staticPrintPerson();
	// static void staticPrintpersin() const; �Ұ���, static�� this�� �Ѿ�� ����
};

