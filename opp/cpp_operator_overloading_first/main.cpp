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
	void print() const // const �����͸� ������ (void���̶� �ν��Ͻ��� const�� ����Ǿ��ٸ� const�ٿ�����) 
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
		return x * v.x + y * v.y + z * v.z; // ������ ������ ���ϴ� ������ ���� �̷�
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
		return *this; // ���� ��ȯ
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
	friend class VectorF; // ģ�� Ŭ�������״� ����� ����
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
		return VectorF{ x + v.x,y + v.y,z + v.z }; // �̰� �ȵȴٴµ� ������ �𸣰���.. 
		// �̷��� �ִ�~ ������ �˾Ƶ��� �����ϸ� ��������� �и��ϰ�, ���� �ڵ带 ����
	}
};
int main() {

	cout << "1. ������ ���۷����� " << "\n";
	Vector v0{ 0,1,2 };
	const Vector v1{ 1,2,3 };

	Vector v2 = v0 + v1;// v0.operator+(v1)
	Vector v3 = -v1; // v1.operator-()

	v0.print();
	v1.print();
	v2.print();
	v3.print();

	cout << "2. ���� �����غ���" << "\n";

	VectorMe vm0{ 0,1,2 };
	VectorMe vm1{ 1,2,3 };

	// ���� ������ +, +vector => vector
	VectorMe vm2 = vm0 + vm1;
	vm0 += vm1;
	vm0.print();
	vm2.print();
	// ���� ������ -, vector - vecotr => vector
	VectorMe vm3 = vm0 - vm1;
	vm0 -= vm1;
	vm0.print();
	// ���� ������ *, vector * 3.0f => vector, vector * vector => float (����)
	float innner1 = vm0 * vm1;
	VectorMe vm4 = vm0 * 10.5f;
	VectorMe vm5 = vm0 / 4;
	vm0.print();
	vm4.print();
	// ���� ������ /, vector / 3.0f => vector
	// ���� ������ ++. --. ++vector, --vector
	// ���� ������ ++, --, vector++, vector--

	cout << " 	VectorMe v7 = 3.0f * vm0 �� �Ϸ���?" << "\n";
	VectorMe v7 = vm0 * 3.0f; // v7 = vm0.operator*(3.0f)
	VectorMe vm7 = 3.0f * vm0; // 3.0f.operator*(vm7) => �����Լ��� �������� 

	cout << "  x,y,z�� private�� ��� friend�� ������ָ� ��" << "\n";
	Vector v8{ 1,2,3 };
	Vector v9 = 3.0f * v8;

}