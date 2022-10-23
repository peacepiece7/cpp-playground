#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include<map>
#include<vector>
#include<cstring>

void intro();
void classAndStructSummary();
void constructorSummary();
void buyCoffee();
void destructorSummary();
void destructorSummary2();
void DeclarationAndDefinitionSummary();

int main() {
	// intro();
	// classAndStructSummary();
	// constructorSummary();
	// buyCoffee();
	// destructorSummary();
	// destructorSummary2();
	DeclarationAndDefinitionSummary();
}

void intro() {
	using namespace std;
	cout << "1. opp, ���� ���� ��" << "\n";
	// opp
	string s0 = "Hello, ";// ���� ������ �Ű澵 �ʿ� ����
	string s1 = "world!";
	s0.append(s1); // string ��ü�� append��� �޼��带 ����, �� ¥���� �ڵ�� �����尰�� ������ ��, ������ ������ ������
	cout << s0 << endl;
	s0 += s1; // ��ü���� ��������� �߻�ȭ �Ǿ� ����

	// ���� ����
	char s2[100] = "hello, "; // 100�� ���� ���Ͽ����Ѵٴ°� �Ű�����
	char s3[] = "world!";
	strcat(s2, s3); // ���� �������ڵ� s2, s3 �־ �𸣰���
	cout << s2 << endl;
}

class Player1 {
public:
	int _health;
	int _power;
	std::string _name;
};
class Player2 {
public: 
	int _health;
	int _power;
	std::string _name;
public:
	int health;
	void attack(Player2& target) {
		// ���� Ŭ���� �������� private�� ������ �� ����(target._name) == private�� ���� �������� ����� �� ����
		std::cout << "Attack " << _name << "->" << target._name << "\n";
		target.damaged(_power);
	}
	void damaged(int power) {
		_health -= power;
		if (_health <= 0)
			std::cout << "Died. " << _name << " !" << "\n";
	}

};
class Player3 {
private:
	int _health;
	int _power;
	std::string _name;
public:
	// constructor(������), ���� Ÿ���� ���� �Լ�
	Player3(int health, int power, std::string name) {
		_health = health;
		_power = power;
		_name = name;
	}
	int health;
	void attack(Player3& target) { // �ɹ��Լ� || �޼���
		// ���� Ŭ���� �������� private�� ������ �� ����(target._name) == private�� ���� �������� ����� �� ����
		std::cout << "Attack " << _name << "->" << target._name << "\n";
		target.damaged(_power);
	}
	void damaged(int power) {
		_health -= power;
		if (_health <= 0)
			std::cout << "Died. " << _name << " !" << "\n";
	}
};
void classAndStructSummary() {
	using namespace std;

	cout << "1. Ŭ���� ����" << "\n";
	Player1 player0; // player0�� Player�� �ν��Ͻ�

	cout << "2. calss struct ������" << "\n";
	// struct��
	// Player player0{10,20}; �ʱ�ȭ ����
	// player0.health = 10; ���ٰ���

	// class�� public:�̶�� ���̾� �ȿ� �ۼ�����߸� ����, �ʱ�ȭ ����
	player0._health = 10;
	// player0.power ���� �Ұ���


	cout << "3. �÷��̾� ������" << "\n";
	Player2 david{ 200,100,"David" };
	Player2 daniel{ 200,100,"Daniel" };
	
	david.attack(daniel);
	david.attack(daniel);

	david._health -= 200; // public���� �����͸� �ܺο� �����ϸ� david,_health -= 200; �̷���������

	cout << "4. private���� _health�����" << "\n";
	Player3 john{ 200,100,"John" };
	Player3 bob{ 200,100,"Bob" };

	john.attack(bob); // �߻�ȭ (attack ���� ������ ����)
	john.attack(bob);

	// john._health -= 200; ���� ���� �Ұ���!
}

class Player4 {
private:
	int _health;
	int _power;
public:
	std::string hi = "Hello, world!";
	Player4(int health, int power) {
		_health = health;
		_power = power;
		std::cout << "�Ķ���Ͱ� �ִ� Player :" << _health << ", " << _power << std::endl;
	};
	// ������ �����ε�
	Player4() {
		_health = 10;
		_power = 5;
		std::cout << "����Ʈ Player :" << _health << ", " << _power << "\n";
	}
};
class Ư�������� {
public:
	int _test;
};
class Player5 {
private:
	// ����Ʈ ������ �Լ��� ������ ���⿡ �ʱ�ȭ �� ���� ������(����Ʈ ���� ����� ���� ���Ѻ���)
	int _health = 100;
	int _power = 200;
	const std::string _name ="Undefined";
public:
	Player5() : Player5(100, 50, "noname") // ���� ������, :_heath(1000) // ���� �ʱ�ȭ�ϸ� �������� private�� ���� �����
	{
		// Player5(100,50) =>  Player5 player = Player5(100,50)�̷� �ν��Ͻ��� �ٽ� ����� ���� ���� x
	}
	// Player5() = default; �� ����Ʈ �������Լ� ���� ����
	Player5(int health, int power, std::string name)
		: _health(health), _power(power), _name(name) 
		// = �����ڷ�(���Կ���) const char�� �ʱ�ȭ �� ��������� �������� �ʱ�ȭ (member initialize list, �ɹ� �ʱ�ȭ ����Ʈ), ������ �̷��� �ʱ�ȭ��
		// ���� �ʱ�ȭ�ϴ°Ŷ� ������ ������ ����
	{
		// _health = health; => �ʱ�ȭ �� ���Կ����̶� ������ ������
		// _power = power;
		// _name = name; �Ұ���!
		std::cout << "Player :"<< _name << ", " << _health << ", " << _power << "\n";
	}
	void print() {
		std::cout << _name << " : " << _health << " : " << _power << "\n";
	}
};
void constructorSummary() {
	using namespace std;

	cout << "1. �پ��� ���� ���" << "\n";
	Player4 player0(100, 50);
	Player4 player1 = Player4(100, 50);
	Player4* player2 = new Player4(100, 50);

	cout << "2. ������ �����ε� (default �����ڸ� �ڿ�� �Ʒ� �÷��̾�� ������ ��)" << "\n";
	Player4 player3;
	Player4 player4 = Player4();
	Player4* player5 = new Player4;

	cout << "3. Ʋ�� ������ �Լ�" << "\n";
	// �����Ϸ��� �˾Ƽ� default �����ڸ� ����� �ʱ�ȭ�� �Ͻ������� ������
	Ư�������� sp; 
	Player5 player6;

	cout << "4. �ʱ�ȭ" << "\n";
	player6.print();

}

// Ŀ�Ǹ� ��� ���� ���� ����!
class User {
private:
	const std::string _name;
	int _coins;
public:
	User(std::string name, int coins) : _coins(coins), _name(name)
	{
		std::cout << "User name : " << _name << " : " << "coin : " << _coins << "\n";
	}
	int getCoinOnHand(int coins)
	{
		std::cout << "getCoinOnHand" << "\n";
		if (coins <= 0) return 0; // ������ ������ ��� 0�� ��ȯ
		if (_coins - coins < 0)
		{
			coins = _coins;
			_coins = 0;
			return coins;
		}
		else
		{
			_coins -= coins;
			return coins;
		}
	}
	void checkPocket() 
	{
		std::cout << "name :" << _name << " coin :" << _coins << "\n";
	}
};
class ProductInfomation {
private:
	std::string _name = "undefined";
	int _stack = 0;
	int _price = 0;
public:
	ProductInfomation(std::string name, int stack, int price) : _name(name), _stack(stack), _price(price) {
	};
	void checkProductInfomation() {
		std::cout << _name << " " << _stack << " " << _price << "\n";
	}
};
class CoffeeMachine {
private:
	struct MenuInfomation {
		int stack;
		int price;
	};
	std::map<std::string, MenuInfomation> _menuList;
	int _earnedCoins;
public: 
	CoffeeMachine() : _earnedCoins(0) {
		_menuList.insert({ "Americano", {.stack = 5 ,.price = 3} });
		_menuList.insert({ "Lattee", {.stack = 3, .price = 5} });
		_menuList.insert({ "Juice", {.stack = 5, .price = 10} });
	};
	void getCoins(int* coins) {
		_earnedCoins += *coins;
		*coins = 0;
	}
	int pushMenuBtn(std::string menu) {
		std::map<std::string, MenuInfomation>::iterator it = _menuList.find(menu);
		if (it == _menuList.end())
		{
			std::cout << "Incollected Btn, Please check the button" << "\n";
			return 0;
		}
		else 
		{
			std::cout << "push the button : " << menu << ", price : " << _menuList[menu].price << ", stack : " << _menuList[menu].stack << "\n";
			if (_earnedCoins - _menuList[menu].price < 0) 
			{
				std::cout << "���� �����մϴ�. " << menu << " Inserted coins :" << _earnedCoins << ", price :" << _menuList[menu].price << "\n";
				return 0;
			}
			else if(_menuList[menu].stack <= 0) 
			{
				std::cout << menu << "�� ��� �����մϴ�" << "\n";
				return 0;
			}
			else {
				std::cout << menu << "�� ���Խ��ϴ�. �ܵ��� ��ȯ�˴ϴ�. ���ְ� �弼��." << "\n";
				--_menuList[menu].stack;
				int remainder = _earnedCoins - _menuList[menu].price;
				_earnedCoins = 0;
				return remainder;
			}
		}
	}
	void checkEarnedCoins() {
		std::cout << "inserted coin : " << _earnedCoins << "\n";
	}
	void checkStackAndPrice() {
		std::cout << "\ncoffee machine menu" << "\n";
		for (auto menu : _menuList) {
			std::cout << menu.first << " price : " << menu.second.price << " stack :" << menu.second.stack << "\n";
		}
	}
};
void buyCoffee() {
	User user1("Lyn", 20);
	CoffeeMachine coffeeMachine;

	int coins = user1.getCoinOnHand(5);
	user1.checkPocket();

	coffeeMachine.getCoins(&coins);
	coffeeMachine.checkEarnedCoins();

	int remainder = coffeeMachine.pushMenuBtn("Americano");
	std::cout << "remainder :" << remainder << "\n";
	coffeeMachine.checkEarnedCoins();
	coffeeMachine.checkStackAndPrice();
	// �ܵ� ��ȯ, �ָӴϿ� ������ �ݾ� �ֱ� �ȸ���..!
}

//! cout �ּ� Ǯ�� ����
class Player6 {
private:
	int _num;
public:
	Player6(int num) : _num(num)
	{
		//std::cout << "Constructor :" << _num << std::endl;
	}
	~Player6() 
	// destructor ����, �������� ������ �����Ϸ��� �Ͻ������� �Ҹ��ڸ� ������, 
	// ~Player6() delete�̷����ϸ� �����Ϸ��� �Ҹ��ڸ� ������ ���ؼ� �ν��Ͻ��� ���� �� ����
	// �� ���, Ŭ���� �����Ϳ� ���� �Ҵ��� �� �� ������ Ŭ���� �����Ͱ� ����Ű�� �޸𸮸� delete�� �� ����,,,,
	{
		//std::cout << "Destructor :" << _num << std::endl; 
	}
};
Player6 player00 = Player6(0);
Player6* player01 = new Player6(1);
void func() {
	static Player6 player02 = Player6(2); // �������� �����ϸ� ���α׷��� ����� �� ���� ����

}
void destructorSummary() {
	Player6 player03 = Player6(3);
	Player6* player04 = new Player6(4);
	{
		Player6 player05 = Player6(5); // �������� ����� �ı���
		Player6* player06 = new Player6(6); // �������� ����� �ı����� ����, ���������
	}
	delete player01; // �޸𸮸� �����ϸ� destructor�� �۵�
	// free(player01); // �� �������� �ʴµ� ����?
	func();
	func(); // static���� �����ؼ� �� �� ȣ�������� �� ���� ����

	// ���α׷��� ����ǰ� 03, 02, 00������� �ı�
}

class String {
private:
	char* _str;
public:
	String(const char* str)
	{
		int len = strlen(str);
		_str = new char[len + 1]; // '\0'
		strcpy(_str, str);
	}
	void print() {
		std::cout << _str << "\n";
	}
	~String() {
		delete[] _str;
		// free(_str); => �޸� Ȯ���غ��� ���� �ߵ� 
	}
};
void destructorSummary2() {
	while (true) {
		String str("abc");
	}

}

// C++, one definition role (���Ǵ� �ѹ��� ����)
// �ٸ�, �Ȱ��� ����� ���ư�
class Person
{
private:
	float _w;
	float _h;
	const std::string _name;
public:
	Person(float w, float h, const std::string name) : _w(w), _h(h), _name(name) {

	}
	void print() {
		std::cout << _name << "\n";
	}
};
#include "PersonHeader.h"
void DeclarationAndDefinitionSummary() {
	std::cout << "1. Declaration" << "\n";
	// Declaration
	// 1. Defining Declaration, Def Definition (����) => ���Ǹ� �����ϴ� ���� (�Լ� ����)
	// 2. Referencing Declaration, Declaration (����) => ���ǰ� ���Ե��� �ʴ� ���� (������ Ÿ�� ����)
	
	int x; // 1�� (���ǰ� ���ԵǾ �ٷ� ��밡��)
	x = 10; 

	// void func(){ ...logic }; => 1. ����
	// void func(); => 2. ����
	std::cout << "2. ������Ͼ��� Ŭ���� ������ ����" << "\n";
	Person p(55.5f, 155.5f, "david");
	p.print();
	std::cout << "3. include�� ������� ����ϱ�" << "\n";
	Person p1(55.5f, 155.5f, "header : david ");
	p1.print();

	std::cout << "4. function�� ������Ͽ� �����ϱ�" << "\n";
	// function�� ���Ǹ� �� �� �� �� �� �ִµ� ����� �Լ��� �����ϰ� ���� ���Ͽ� include�ϸ�?
	// => ������ ���ǵǴϱ� �翬�� ������ => PersonHeader.cpp (PersonHeader.h�� �̸��� ����, ��������)�� ���� �Լ��� �������ָ��
	foo(); 

	
}
