// #pragma once
#ifndef __PERSON_HEADER_H__
#define __PERSON_HEADER_H__

#include<iostream>
#include<string>
// using namespace std; => 여기서 하면 Person.h를 포함하는 모든파일은 다 적용됨
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
	void sum(int _w, int _h); // 캡슐화, 추상화로 sum이 _w, _h를 받아서 void를 출력한다는걸 누구나 보면 알 수 있음, 내부 로직은 안 궁금함
};

#endif // !__PERSON_HEADER_H__