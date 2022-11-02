#include <iostream>

using namespace std;
void thisPointerSummary();
void constantSummary();
void staticMemberSummary(); 
void memberFunctionPotinerSummary();

int main() {
	// thisPointerSummary();
	// constantSummary();
	staticMemberSummary();
}

class Person
{
private:
	float weight;
	float height;
	const string name;
public:
	Person(float weight, float height, const string& name) : weight(weight), height(height), name(name) {}
	void loseWeight(float weight) {
		//this->height == height 같음
		this->height -= weight;
	}
	float getBMI() {
		return weight / (height * 100 * height * 100);
	}
	Person& complete(Person& person) {
		if (this->getBMI() < person.getBMI()) {
			return *this;
		}
		else {
			return person;
		}
	}
	void doCeremony() {
		cout << name << " win!!" << "\n";
	}
};

struct Transaction {
	const int txID;
	const int fromID;
	const int toID;
	const int value;
	class Builder {
	private:
		int _fromID;
		int _toID;
		int _value;
	public:
		Transaction build() {
			int txID = _fromID ^ _toID ^ _value;
			return Transaction{ txID, _fromID, _toID, _value };
		}
		// private 세팅 constructor를 체인 형식으로 구현
		// id를 받아서 해싱해야 할 때 유용할 
		// Builder& => Builder 인스턴스의 주소를 반환
		Builder& setFromID(int fromID) {
			this->_fromID = fromID;
			return *this; // this의 값 (인스턴스)를 반환하기 떄문에 메서드 체이닝을 할 수 있음
		}
		Builder& setToID(int toID) {
			_toID = toID;
			return *this;
		}
		Builder& setValue(int value) {
			_value = value;
			return *this;
		}
	};
};

void thisPointerSummary() {
	cout << "1. this 포인터" << "\n";
	// this => Person의 객체 자체임 *person0인것
	Person person0(74, 172.4f, "daniel");
	Person person1(72, 169.3f, "alice");
	person0.complete(person1).doCeremony();
	cout << "2. builder " << "\n";
	Transaction a = Transaction::Builder().setFromID(1234).setToID(111).setValue(91919).build();
}

class Person1 {
private:
	const string _name = "abc";
	float _height;
	float _weight;
public:
	Person1(const string& name,int height, int weight) : _name(name), _height(height), _weight(weight)// const는 초기자 맴버 변수에서 한 번 만 변경 가능
	{
		// _name = name; const라 변경 불가능
	}
	float getWeight(/* const Person* this */) const // const 인스턴스만 호출가능함!
		// getWeight(Person* this) const => getWeight(const Person* this)임
	{
		// _weight => this->_weight;
		// _weight 변경이 불가능함 (this가 가르키는 건 모두 변경 안됨)
		return _weight;
	}
};
void constantSummary() {
	// const 인스턴스는 const Person this임
	const Person1* person0 = new Person1("daniel", 55.4f, 166.6f);
	// Person1* person1 = person0; <= const포인터를 const아닌 다른 변수에 할당하면 해당 변수에서 변경가능하니까 이건 불가능함
	person0->getWeight();
	Person1* person1 = new Person1("ddd", 55.5f, 4544.4f);
	// person1.getWeight() : Person* this인데, person1.getWeight() : const Person* this이거만 받을 수 있음
}
#include "personStatic.h"
void staticMemberSummary() {
	cout << "1. Static member" << "\n";
	PersonStatic p0;
	p0.printPerson();
	PersonStatic p1;
	p0.printPerson();

	cout << "1. static member 특징" << "\n";
	// 접근 제한이 PersonStatic으로 되어 있는 전역변수 클래스에서 public바로 접근 가능함!
	cout << PersonStatic::publicNum << "\n";
	// 맴버함수도 static이면 접근 가능
	// static 함수는 static만 접근가능, 그 외 맴버함수, 변수에 접근할 수 없음(this가 넘어가지 않기때문에 (생성자가 없을떄 선언하니까, 구체화가 안되서))
	PersonStatic::staticPrintPerson();

	
}
void memberFunctionPotinerSummary() {
	// .... 개어렵 ...
}