#include <iostream>
#include <compare>

using namespace std;
int main() {
	int num10 = 10, num11(11);
	printf("아래는 num10 에 11을 할당, ==랑 =랑 구분 잘하기");
	if (num10 = num11)
		printf("%i", num10);

	int num1 = 1, num0(0);
	printf("==, <=, >= , <, >, != 가능\n");
	// 프로젝트 => 속성 => 일반 => C++ 언어표준 초안의 기능으로 변경 시 아래코드(<=>) 사용가능
	// <=> (what, how)
	cout.setf(ios_base::boolalpha);
	// 1 과 1의 관계는 어때? => 결과값 == 0 => true
	cout << ((1 <=> 1) == 0) << endl;

	// 이거 뭔지 모르겠음, 결과다 다 true가 나옴 일단 20에 추가됐다는 거만 알고 넘기자
	cout << ((2 <=> 1) > 0) << endl;
	cout << ((1 <=> 2) > 0) << endl;
	cout << ((1 <=> 2) >= 0) << endl;
	cout << is_eq(1 <=> 1) << endl;;
	cout << is_neq(1 <=> 2) << endl;;
	cout << is_lt(1 <=> 2) << endl;;
	cout << is_lteq(1 <=> 2) << endl;;
	cout << is_gt(2 <=> 1) << endl;; 

	cout << typeid(1 <=> 1).name() << endl; // string odering (같음)
	cout << typeid(1 <=> 1.0).name() << endl; // equivalent (같은 건 아니고 동등함)
	cout << ((1 <=> 1.0) == partial_ordering::equivalent) << endl; // true
	cout << ((1 <=> 1.0) == strong_ordering::equal) << endl; // false
	cout << ((1 <=> 1) == strong_ordering::equal) << endl; // true


}