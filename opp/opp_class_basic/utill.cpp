#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include<map>
#include<vector>
#include<cstring>
using namespace std;

// 똑같이 정의하면 on definetion role에 위배되지 않음
// class, struct, enum 등 몇개가 이런 애들이 있음
// 하지만 전부다 바꿔주는건 너무 귀찮음 -> header file
class Person
{
private:
	float _w;
	float _h;
	const std::string _name;
public:
	Person(float w, float h, const std::string name) : _w(w), _h(h), _name(name) {
		std::cout << "Person클래스 생성" << "\n";
	}
	void print() {
		std::cout << _name << "\n";
	}
};
