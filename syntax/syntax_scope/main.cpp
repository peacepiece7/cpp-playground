#include<iostream>
enum struct RequestType {
	Login,Register,Update
};
static int x; // 1. file 범위
// static extern은 범위를 벗어나도 메모리가 해제되지 않음
int get();

namespace CompanyA {
	int num = 10;
}
namespace CompanyB { // 외부 num은  extern num
	 extern int num = 1000;
}

int main() {
	using std::cout;
	using std::cin;
	cout << "1. extern int x; (정적 공간)" << "\n";
	// 모든 파일에서 전역으로 선언된 변수 x
	x = 200;
	std::cout << get() << "\n";

	cout << " 2. scoped enumeration" << "\n";
	// 범위 지정자 ::를 사용해서 범위 지정가능
	RequestType::Login; 

	cout << "3. namespace std가 있는 이유" << "\n";
	// 다른 회사와 협업할떄 int num이 겹치면?
	std::cout << CompanyA::num << "\n";
	std::cout << CompanyB::num << "\n";
	// 스텐다드 라이브러리가 std::에 감춰든 이유가 저거임 우리가 만든 함수랑 겹칠까봐..

	// 이렇게 줄이고 싶은 함수만 사용할수도 있음
	using std::cout;
	using std::cin;


	

	
	cout << "자동공간, 범위를 벗어나면 해제됨 (static, extern)" << "\n";
	cout << "정적공간, 범위를 벗어나도 해제되지 범위 외부에서 접근 불가능 {int a;}" << "\n";
	cout << "동적공간, 이름이 없음, new를사용 사용후 반드시 해제해줘야함 int a = new int[10]; free(a)" << "\n";

	// static, 선언시 한번만 초기화 됨, 전역으로 쓰면 파일 스코프를 가짐
	for (int i = 0; i < 5; i++) {
		static int a = 1;
		a++;
		cout << a << " ";
	}
	// a => error 메모리가 해제되지 않았지만 지역 변수라서 접근 불가능

	// 동적공간, 이름이 따로 없기떄문에 new키워드로 동적 공간을 할당하고, 해당 위치를 가리키는 주소를 변수에 담음
	// 주소를 잃어버리면 해제할수없음
	int* c = new int[10];
}
