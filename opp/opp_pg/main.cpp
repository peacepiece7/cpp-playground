#include<iostream>;
using namespace std;

class Person {
private:
	const string _name;
	float _weight;
	float _height;

public:
	Person(const string name, float w, float h) : _name(name), _weight(w), _height(h) {}
	float getBMI() {
		return _weight / (_weight * 100 * this->_height * 100);
	}
	Person* complete(Person* person) {
		if (this->getBMI() >= person->getBMI()) {
			return this;
		}
		else {
			return person;
		}
	}
	string ceremony() {
		return " win!!  " + this->_name;
	}
};

int main() {
	Person person0("foo", 77.6f, 190.f);
	Person* person1 = new Person("bar", 67.5f, 180.5f);
	cout << person0.complete(person1)->ceremony() << "\n";
	Person* winner = person0.complete(person1);
	cout << (*winner).ceremony() << "\n";
}