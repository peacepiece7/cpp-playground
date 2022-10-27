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
		//this->height == height ����
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
		// private ���� constructor�� ü�� �������� ����
		// id�� �޾Ƽ� �ؽ��ؾ� �� �� ������ 
		// Builder& => Builder �ν��Ͻ��� �ּҸ� ��ȯ
		Builder& setFromID(int fromID) {
			this->_fromID = fromID;
			return *this; // this�� �� (�ν��Ͻ�)�� ��ȯ�ϱ� ������ �޼��� ü�̴��� �� �� ����
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
	cout << "1. this ������" << "\n";
	// this => Person�� ��ü ��ü�� *person0�ΰ�
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
	Person1(const string& name,int height, int weight) : _name(name), _height(height), _weight(weight)// const�� �ʱ��� �ɹ� �������� �� �� �� ���� ����
	{
		// _name = name; const�� ���� �Ұ���
	}
	float getWeight(/* const Person* this */) const // const �ν��Ͻ��� ȣ�Ⱑ����!
		// getWeight(Person* this) const => getWeight(const Person* this)��
	{
		// _weight => this->_weight;
		// _weight ������ �Ұ����� (this�� ����Ű�� �� ��� ���� �ȵ�)
		return _weight;
	}
};
void constantSummary() {
	// const �ν��Ͻ��� const Person this��
	const Person1* person0 = new Person1("daniel", 55.4f, 166.6f);
	// Person1* person1 = person0; <= const�����͸� const�ƴ� �ٸ� ������ �Ҵ��ϸ� �ش� �������� ���氡���ϴϱ� �̰� �Ұ�����
	person0->getWeight();
	Person1* person1 = new Person1("ddd", 55.5f, 4544.4f);
	// person1.getWeight() : Person* this�ε�, person1.getWeight() : const Person* this�̰Ÿ� ���� �� ����
}
#include "personStatic.h"
void staticMemberSummary() {
	cout << "1. Static member" << "\n";
	PersonStatic p0;
	p0.printPerson();
	PersonStatic p1;
	p0.printPerson();

	cout << "1. static member Ư¡" << "\n";
	// ���� ������ PersonStatic���� �Ǿ� �ִ� �������� Ŭ�������� public�ٷ� ���� ������!
	cout << PersonStatic::publicNum << "\n";
	// �ɹ��Լ��� static�̸� ���� ����
	// static �Լ��� static�� ���ٰ���, �� �� �ɹ��Լ�, ������ ������ �� ����(this�� �Ѿ�� �ʱ⶧���� (�����ڰ� ������ �����ϴϱ�, ��üȭ�� �ȵǼ�))
	PersonStatic::staticPrintPerson();

	
}
void memberFunctionPotinerSummary() {
	// .... ����� ...
}