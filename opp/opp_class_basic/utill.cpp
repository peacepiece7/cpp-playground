#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include<map>
#include<vector>
#include<cstring>
using namespace std;

// �Ȱ��� �����ϸ� on definetion role�� ������� ����
// class, struct, enum �� ��� �̷� �ֵ��� ����
// ������ ���δ� �ٲ��ִ°� �ʹ� ������ -> header file
class Person
{
private:
	float _w;
	float _h;
	const std::string _name;
public:
	Person(float w, float h, const std::string name) : _w(w), _h(h), _name(name) {
		std::cout << "PersonŬ���� ����" << "\n";
	}
	void print() {
		std::cout << _name << "\n";
	}
};
