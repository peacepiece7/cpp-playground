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
	cout << "1. opp, 절차 지향 비교" << "\n";
	// opp
	string s0 = "Hello, ";// 문자 개수를 신경쓸 필요 없음
	string s1 = "world!";
	s0.append(s1); // string 객체는 append라는 메서드를 가짐, 잘 짜여진 코드는 영문장같은 느낌이 듬, 내부적 구현이 숨겨짐
	cout << s0 << endl;
	s0 += s1; // 객체간의 연산과정이 추상화 되어 있음

	// 절자 지향
	char s2[100] = "hello, "; // 100개 문자 이하여야한다는걸 신경써야함
	char s3[] = "world!";
	strcat(s2, s3); // 절차 지향적코드 s2, s3 주어를 모르겠음
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
		// 같은 클레스 내에서는 private에 접근할 수 있음(target._name) == private은 같은 레벨에선 사용할 수 있음
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
	// constructor(생성자), 리턴 타입이 없는 함수
	Player3(int health, int power, std::string name) {
		_health = health;
		_power = power;
		_name = name;
	}
	int health;
	void attack(Player3& target) { // 맴버함수 || 메서드
		// 같은 클레스 내에서는 private에 접근할 수 있음(target._name) == private은 같은 레벨에선 사용할 수 있음
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

	cout << "1. 클레스 선언" << "\n";
	Player1 player0; // player0는 Player의 인스턴스

	cout << "2. calss struct 차이점" << "\n";
	// struct는
	// Player player0{10,20}; 초기화 가능
	// player0.health = 10; 접근가능

	// class는 public:이라는 레이어 안에 작성해줘야만 접근, 초기화 가능
	player0._health = 10;
	// player0.power 접근 불가능


	cout << "3. 플레이어 떄리기" << "\n";
	Player2 david{ 200,100,"David" };
	Player2 daniel{ 200,100,"Daniel" };
	
	david.attack(daniel);
	david.attack(daniel);

	david._health -= 200; // public으로 데이터를 외부에 노출하면 david,_health -= 200; 이럴수도있음

	cout << "4. private으로 _health숨기기" << "\n";
	Player3 john{ 200,100,"John" };
	Player3 bob{ 200,100,"Bob" };

	john.attack(bob); // 추상화 (attack 내부 로직을 감춤)
	john.attack(bob);

	// john._health -= 200; 이제 접근 불가능!
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
		std::cout << "파라메터가 있는 Player :" << _health << ", " << _power << std::endl;
	};
	// 생성자 오버로딩
	Player4() {
		_health = 10;
		_power = 5;
		std::cout << "디폴트 Player :" << _health << ", " << _power << "\n";
	}
};
class 특별생성자 {
public:
	int _test;
};
class Player5 {
private:
	// 디폴트 생성자 함수가 없으면 여기에 초기화 한 값이 지정됨(디폴트 생를 지우고 실행 시켜보자)
	int _health = 100;
	int _power = 200;
	const std::string _name ="Undefined";
public:
	Player5() : Player5(100, 50, "noname") // 위임 생성자, :_heath(1000) // 으로 초기화하면 나머지는 private의 값이 적용됨
	{
		// Player5(100,50) =>  Player5 player = Player5(100,50)이런 인스턴스를 다시 만드는 거임 적용 x
	}
	// Player5() = default; 로 디폴트 생성자함수 실행 가능
	Player5(int health, int power, std::string name)
		: _health(health), _power(power), _name(name) 
		// = 연산자로(대입연산) const char를 초기화 할 수없을경우 옆과같이 초기화 (member initialize list, 맴버 초기화 리스트), 참조도 이렇게 초기화함
		// 직접 초기화하는거라 성능의 이점이 있음
	{
		// _health = health; => 초기화 후 대입연산이라서 성능이 안좋음
		// _power = power;
		// _name = name; 불가능!
		std::cout << "Player :"<< _name << ", " << _health << ", " << _power << "\n";
	}
	void print() {
		std::cout << _name << " : " << _health << " : " << _power << "\n";
	}
};
void constructorSummary() {
	using namespace std;

	cout << "1. 다양한 선언 방법" << "\n";
	Player4 player0(100, 50);
	Player4 player1 = Player4(100, 50);
	Player4* player2 = new Player4(100, 50);

	cout << "2. 생성자 오버로딩 (default 생성자를 자우면 아래 플레이어는 에러가 뜸)" << "\n";
	Player4 player3;
	Player4 player4 = Player4();
	Player4* player5 = new Player4;

	cout << "3. 틀별 생성자 함수" << "\n";
	// 컴파일러가 알아서 default 생성자를 만들고 초기화를 암식적으로 시켜줌
	특별생성자 sp; 
	Player5 player6;

	cout << "4. 초기화" << "\n";
	player6.print();

}

// 커피를 사는 로직 대충 만들어봄!
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
		if (coins <= 0) return 0; // 코인이 음수일 경우 0을 반환
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
				std::cout << "돈이 부족합니다. " << menu << " Inserted coins :" << _earnedCoins << ", price :" << _menuList[menu].price << "\n";
				return 0;
			}
			else if(_menuList[menu].stack <= 0) 
			{
				std::cout << menu << "의 재고가 부족합니다" << "\n";
				return 0;
			}
			else {
				std::cout << menu << "가 나왔습니다. 잔돈이 반환됩니다. 맛있게 드세요." << "\n";
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
	// 잔돈 반환, 주머니에 나머지 금액 넣기 안만듬..!
}

//! cout 주석 풀고 보자
class Player6 {
private:
	int _num;
public:
	Player6(int num) : _num(num)
	{
		//std::cout << "Constructor :" << _num << std::endl;
	}
	~Player6() 
	// destructor 정의, 정의하지 않으면 컴파일러가 암시적으로 소멸자를 생성함, 
	// ~Player6() delete이렇게하면 컴파일러가 소멸자를 만들지 못해서 인스턴스를 만들 수 없음
	// 이 경우, 클래스 포인터에 동적 할당을 할 수 있으나 클래스 포인터가 가르키는 메모리를 delete할 수 없음,,,,
	{
		//std::cout << "Destructor :" << _num << std::endl; 
	}
};
Player6 player00 = Player6(0);
Player6* player01 = new Player6(1);
void func() {
	static Player6 player02 = Player6(2); // 정적으로 생성하면 프로그램이 종료될 때 까지 존재

}
void destructorSummary() {
	Player6 player03 = Player6(3);
	Player6* player04 = new Player6(4);
	{
		Player6 player05 = Player6(5); // 스코프를 벗어나면 파괴됨
		Player6* player06 = new Player6(6); // 스코프를 벗어나도 파괴되지 않음, 지워줘야함
	}
	delete player01; // 메모리를 제거하면 destructor가 작동
	// free(player01); // 은 동작하지 않는데 왜지?
	func();
	func(); // static으로 선언해서 두 번 호출하지만 한 번만 생성

	// 프로그램이 종료되고 03, 02, 00순서대로 파괴
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
		// free(_str); => 메모리 확인해보면 삭제 잘됨 
	}
};
void destructorSummary2() {
	while (true) {
		String str("abc");
	}

}

// C++, one definition role (정의는 한번만 가능)
// 다만, 똑같이 만들면 돌아감
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
	// 1. Defining Declaration, Def Definition (정의) => 정의를 포함하는 선언 (함수 선언)
	// 2. Referencing Declaration, Declaration (선언) => 정의가 포함되지 않는 선언 (프로토 타입 선언)
	
	int x; // 1번 (정의가 포함되어서 바로 사용가능)
	x = 10; 

	// void func(){ ...logic }; => 1. 정의
	// void func(); => 2. 선언
	std::cout << "2. 헤더파일없이 클래스 일일이 관리" << "\n";
	Person p(55.5f, 155.5f, "david");
	p.print();
	std::cout << "3. include한 헤더파일 사용하기" << "\n";
	Person p1(55.5f, 155.5f, "header : david ");
	p1.print();

	std::cout << "4. function을 헤더파일에 정의하기" << "\n";
	// function은 정의를 한 번 만 할 수 있는데 헤더에 함수를 정의하고 여러 파일에 include하면?
	// => 여러번 정의되니까 당연히 에러남 => PersonHeader.cpp (PersonHeader.h와 이름을 같게, 컨벤션임)를 만들어서 함수를 선언해주면됨
	foo(); 

	
}
