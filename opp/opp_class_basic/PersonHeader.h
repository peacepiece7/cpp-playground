// #pragma once
#ifndef __PERSON_HEADER_H__
#define __PERSON_HEADER_H__

#include<iostream>
#include<string>
// using namespace std; => ���⼭ �ϸ� Person.h�� �����ϴ� ��������� �� �����
void foo();

class PersonHeader
{
private:
	float _w;
	float _h;
	const std::string _name;
public:
	PersonHeader(float w, float h, const std::string& name);
	void print();
	void sum(int _w, int _h); // ĸ��ȭ, �߻�ȭ�� sum�� _w, _h�� �޾Ƽ� void�� ����Ѵٴ°� ������ ���� �� �� ����, ���� ������ �� �ñ���
};

#endif // !__PERSON_HEADER_H__