#include<iostream>
using namespace std;

class Vector {
private:
	float x;
	float y;
	float z;
public:
	Vector(float x, float y, float z) : x(x), y(y), z(z) {};
	Vector operator+(const Vector& v) const {
		return Vector{ x + v.x, y + v.y, z + v.z };
	}
	Vector operator-() const {
		return Vector{ -x, -y, -z };
	}
	void print() const // const 포인터를 가져옴 (void형이라도 인스턴스가 const로 선언되었다면 const붙여야함) 
	{
		cout << "x : " << x << ", y : " << y << ", z : " << z << '\n';
	}
	friend Vector operator*(float f, const Vector& v);
};
class VectorMe
{
public:
	float x;
	float y;
	float z;
	// VectorMe(float x, float y, float z) : x(x), y(y), z(z) {};
	VectorMe operator+(VectorMe& vec) const {
		return VectorMe{ x + vec.x, y + vec.y, z + vec.z };
	}
	VectorMe operator+=(VectorMe& vec) {
		this->x = x + vec.x;
		this->y = y + vec.y;
		this->z = z + vec.z;
		return *this;
	}
	VectorMe operator-(VectorMe& vec) const {
		return VectorMe{ x - vec.x, y - vec.y, z - vec.z };
	}
	VectorMe operator-=(VectorMe& vec) {
		this->x = x - vec.x;
		this->y = y - vec.y;
		this->z = z - vec.z;
		return *this;
	}
	float operator*(VectorMe& v) const {
		return x * v.x + y * v.y + z * v.z; // 백터의 내접을 구하는 공식이 원래 이럼
	}
	VectorMe operator*(float f) const {
		return VectorMe{ x * f , y * f , z * f };
	}
	VectorMe operator/(float f) {
		return VectorMe{ x / f , y / f , z / f };
	}
	void print() {
		cout << "x : " << x << ", y : " << y << ", z : " << z << "\n";
	}
	VectorMe& operator++() {
		this->x + 1;
		this->y + 1;
		this->z + 1;
		return *this; // 값을 반환
	}
	VectorMe operator++(int) {
		VectorMe temp = *this;
		++(*this);
		return temp;
	}
};
VectorMe operator*(float f, const VectorMe& v) {
	return VectorMe{ v.x * f, v.y * f, v.z * f };
}
Vector operator*(float f, const Vector& v) {
	return Vector{ v.x * f, v.y * f, v.z * f };
}
class VectorF;
class VectorI {
	friend class VectorF; // 친구 클래스한테는 비밀이 없음
private:
	int x;
	int y;
	int z;
};
class VectorF {
private:
	float x;
	float y;
	float z;
public:
	VectorF(float x, float y, float z) : x(x), y(y), z(z) {

	};
	VectorF operator+(VectorI& v) const {
		return VectorF{ x + v.x,y + v.y,z + v.z }; // 이게 안된다는데 이유는 모르겠음.. 
		// 이런게 있다~ 정도만 알아두자 가능하면 헤더파일을 분리하고, 강사 코드를 보자
	}
};
int main() {

	cout << "1. 연산자 오퍼레이터 " << "\n";
	Vector v0{ 0,1,2 };
	const Vector v1{ 1,2,3 };

	Vector v2 = v0 + v1;// v0.operator+(v1)
	Vector v3 = -v1; // v1.operator-()

	v0.print();
	v1.print();
	v2.print();
	v3.print();

	cout << "2. 직접 구현해보기" << "\n";

	VectorMe vm0{ 0,1,2 };
	VectorMe vm1{ 1,2,3 };

	// 단항 연산자 +, +vector => vector
	VectorMe vm2 = vm0 + vm1;
	vm0 += vm1;
	vm0.print();
	vm2.print();
	// 이항 연산자 -, vector - vecotr => vector
	VectorMe vm3 = vm0 - vm1;
	vm0 -= vm1;
	vm0.print();
	// 이항 연산자 *, vector * 3.0f => vector, vector * vector => float (내접)
	float innner1 = vm0 * vm1;
	VectorMe vm4 = vm0 * 10.5f;
	VectorMe vm5 = vm0 / 4;
	vm0.print();
	vm4.print();
	// 이항 연산자 /, vector / 3.0f => vector
	// 전위 연산자 ++. --. ++vector, --vector
	// 후위 연산자 ++, --, vector++, vector--

	cout << " 	VectorMe v7 = 3.0f * vm0 를 하려면?" << "\n";
	VectorMe v7 = vm0 * 3.0f; // v7 = vm0.operator*(3.0f)
	VectorMe vm7 = 3.0f * vm0; // 3.0f.operator*(vm7) => 전역함수를 만들어야함 

	cout << "  x,y,z가 private일 경우 friend를 등록해주면 됨" << "\n";
	Vector v8{ 1,2,3 };
	Vector v9 = 3.0f * v8;

}