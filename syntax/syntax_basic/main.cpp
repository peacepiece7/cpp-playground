#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<array>
#include<vector>
#include<functional>
#include<Windows.h>
// #include<bits/stdc++.h>

void pointerArraySummary(); void array1Summary(); void charSummary(); void stringSummary(); void structSummary(); void unionSummary(); void unscopedEnumSummary(); void scopedEnumSummary(); void array2Summary(); std::pair<int, int> makePair(int a, int b); void array3Summary(); void pointerBasicSummary(); void pointerStringSummary(); void dynamicAssignSummary(); void nullptrSummary(); void pointerVoldSummary(); void  pointerVectorSummary(); void referenceSummary(); void functionBasicSummary(int, char* []); void recursionSummary(); void	passByValueSummary(); void passByAddressSummary(int, char**); void passByReferenceSummary(); void defaultParameterSummmary(); void functionOverloadingSummary(); void functionPointerSummary();


int main(int argc, char* argv[]) {
	Sleep(1000);
	// charSummary();
	// stringSummary();
	// structSummary();
	// unionSummary();
	// unscopedEnumSummary();
	// scopedEnumSummary();
	// array1Summary();
	// array2Summary();
	// array3Summary();
	// pointerBasicSummary();
	// pointerArraySummary();
	// pointerStringSummary();
	// dynamicAssignSummary();
	// nullptrSummary();
	// pointerVoldSummary();
	// pointerVectorSummary();
	// referenceSummary();
	// functionBasicSummary(argc, argv);
	// recursionSummary();
	// passByValueSummary();
	// passByAddressSummary(argc, argv);
	// void passByReferenceSummary();
	// defaultParameterSummmary();
	// functionOverloadingSummary();
	// functionPointerSummary();
}
void charSummary() {
	// 문자열의 끝 = '\0'
	char str1[] = "abc";
	std::cout << str1[1] << "\n";
	std::cout << strlen(str1) << "\n";

	std::cout << "\n문자열비교\n";
	char str2[] = "abc";
	char str3[] = "abc";
	char str4[] = "dcf";
	if (str2 == str3) printf("%s", "true"); // false;

	// strcpy strcat strcmp는 쓸일 없을듯..
	std::cout << strcmp(str2, str3) << std::endl; // 같음 0
	std::cout << strcmp(str3, str4) << std::endl; // 다름 -1

	// strcpy(str2,str3) c인데 이거 메모리 침범할 수 있음
	// strcat(str2, str3); 이것도 c인데 에러남

	std::cout << "\n문자열을 숫자로\n";
	char stri1[] = "1";
	char stri2[] = "1.1";
	int i = atoi(stri1); // ascii to int
	float f = atof(stri2); // ascii to float
	std::cout << i << " " << f << "\n";

	return;
}
void stringSummary() {
	std::string str;
	// cin >> str; helloooooooo 길게 받아도 무관
	printf("%s", "1. 문자열 비교\n");
	std::string str1("abc");
	std::string str2("abc");
	if (str1 == str2) std::cout << "True" << "\n"; // 가능
	str1 += str2;
	std::cout << str1 << "\n";

	std::string str3("cdf");
	std::string str4("hij");

	printf("%s", "2. string을 char로 변환 후 strcmp사용하기\n");
	int result = strcmp(str3.c_str(), str4.c_str());
	std::cout << result << "\n";

	printf("%s", "3. string 사이즈\n");
	std::cout << str3.length() << " " << str3.size() << "\n";

	printf("%s", "4. 숫자를 string으로\n");

	std::string str5 = std::to_string(123);
	std::string str6 = std::to_string(123.234);


	std::cout << std::fixed; // <= 소수점 고정해도 str6는 123.234000임
	std::cout.precision(3);

	std::cout << str5 << " " << std::to_string(true) << " " << str6 << " " << str6[5] << "\n";

	std::cout << "\n문자열을 숫자로\n";
	int num2 = std::stoi("1");// string to int
	float num3 = std::stof("1.1");// string to int
	std::cout << num2 << " " << num3 << "\n";
	return;
}
void structSummary() {
	struct EyeSight
	{
		float left;
		float right;
	};
	struct Person
	{
		float height;
		float weight;
		char name[10];
		short grade;
		EyeSight eyeSight;
	};
	Person person = { 175.32f ,65.2f, "David", 1, {1.1f, 1.0f} };
	std::cout <<
		person.height << " " <<
		person.weight << " " <<
		person.name << " " <<
		person.grade << " " <<
		person.eyeSight.left << " " <<
		person.eyeSight.right << "\n";
	Person person1 = person; //  struct 할당 가능
	// if (person == person1) operator overloading이 필요

	Person persons[5];
	Person& person2 = persons[2]; // 참조 주소를 가져옴
	Person person3 = persons[3]; // 새로운 객체가 생성
	person2.grade = 5; // persons[2]와 연결됨
	person3.grade = 5; // 새로운 객체만 적용됨
	std::cout << "person1 : 잘 나옵니다            " << persons[2].grade << "\n";
	std::cout << "person2 : 정의되어 있지 않습니다 " << persons[3].grade << "\n";

	//* 메모리 효율에 대한 추가 정보
	// 자장큰 자료형으로 btye를 맞춤
	struct aligntest1 {
		float a;   // 4 => 4
		short b;   // 2 => 2(2)
		float c;   // 4 => 4
		char d[10];// 2 => 10(2) ->4의 배수여야하는데 22라서(2)추가
		// => 24btye
	};
	std::cout << "aligntest1 :" << sizeof(aligntest1) << "\n";
	struct aligntest2 {
		float a;   // 4 => 4
		float c;   // 4 => 4
		char d[10];// 10 => 10 // char는 1btye * 10개 => 18
		short b;   // 2 => 2
		// => 20byte
	};
	std::cout << "aligntest2 :" << sizeof(aligntest2) << "\n";
	struct alignas(16) aligntest3 {
		float a;   // 4 => 4
		short b;   // 2 => 2
		float c;   // 4 => 4 (6) => 10
		char d[10];// 2 => 10(12) => 32
		// => 32
	};
	std::cout << "aligntest3 :" << sizeof(aligntest3) << "\n";


	struct Test {
		int r = 10;
		int l = 20;
	};
	return;
}
void unionSummary() {
	std::cout << "union == 여러 타입의 속성 중 하나만 필요할 경우" << "\n";
	// !! .idChars쓰려면 ,속성 => 구성 속성 일반 => C++언어표준 최신으로 !!
	union ID {
		int idInteger;
		char idChars[10];
	};
	struct Product1 {
		int idType;
		int idInteger;
		char idChars[10];

	};
	struct Product2 {
		int idType;
		ID id;
	};
	std::cout << "union을 사용하지 않을 경우" << "\n";
	Product1 item1 = { 1, 12 };
	if (item1.idType == 0) std::cout << item1.idInteger << "\n"; // id의 type이 int인지 char 찾아보지 않으면 알 수 없음
	else std::cout << item1.idChars << "\n";

	std::cout << "union을 사용하면 아래와 같이 사용할 수 있음" << "\n";
	Product2 item2 = { 2, {.idChars = "abc"} }; // 만들 때부터 int, char를 구분해서 만들어 둠
	Product2 item3 = { 3, {.idInteger = 13} };
	if (item2.idType == 2) std::cout << item2.id.idChars << "\n";
	else std::cout << item3.id.idInteger << "\n";

	std::cout << "union안에서 align이 맞춰져서 padding(사용하지 않는 btye)이 더 작습니다\n";
	std::cout << sizeof(Product1) << " " << sizeof(Product2) << "\n";// 20 16 (p
}
void unscopedEnumSummary() {
	// type을 미리 알 수 없다 = enum
	// type을 알 수 있다 = struct 
	enum Color1 {
		Red, Blue, Green, Alpha, SIZE // 1, 2, 3, 4, 5의 값을 default로 가지는 거 같음
	};

	int colors1[Color1::SIZE] = { 244,255,123 };
	// 마지막 0은 Alpha가 정의되지 않아서 0임
	for (int i = 0; i < SIZE; i++) std::cout << colors1[i] << " ";
	std::cout << "\n";
	colors1[Alpha] = 444;
	for (int i = 0; i < SIZE; i++) std::cout << colors1[i] << " ";

	struct Color2 {
		int red, blue, green, alpha, size = 4;
	};
	Color2 colors2 = { 255,254,253,111 };

	std::cout << "텍스트에 여러 속성 추가하기" << "\n";
	enum TextAttribute {
		// 1 2 4 8
		Bold = 0b0001,
		Underline = 0b0010,
		Italic = 0b0100,
		Strikethrough = 0b1000
	};
	int textAttrs = 0;
	textAttrs |= TextAttribute::Bold; // 범위지정 연산자, scope지정가능, c++11부터 지원
	textAttrs |= Underline;

	std::cout << "textAttrs에 italic이 있나요? : ";
	if (textAttrs & Italic) std::cout << "YES\n";
	else std::cout << "NO\n";
	std::cout << "textAttrs에 Bold가 있나요? : ";
	if (textAttrs & Bold) std::cout << "YES\n";
	else std::cout << "NO\n";
	std::cout << "textAttrs의 값은? : 0b0011 = ";
	std::cout << textAttrs << "\n";
}
void scopedEnumSummary() {
	enum unscopedEnumFoo {
		Foo = 1,
		Bar = 2,
	};
	enum class scopedColor {
		Blue,
		Red,
		Green,
		SIZE
	};
	enum struct scopedAttribute {
		Bold = 2,
		Underline = 4,
	};
	int a1 = 0;
	std::cout << "scoped는 형 변환이 필수\n";
	// a1 |= scopedAttribute::Bold => Error!
	a1 |= (int)scopedAttribute::Bold; // Works!
	int sum1 = Bar + (int)scopedAttribute::Underline;

	std::cout << "unscoped는 형 변환이 필수가 아님\n";
	// int sum =  Bold + Underline => Error!
	int sum = Bar + unscopedEnumFoo::Foo; // Works!


	std::cout << "enum으로 배열의 사이즈 정하기\n";
	int scopedColors[(int)scopedColor::SIZE] = { 255,128,64 }; // String type Good!
	// int unscopedColor[SIZE] = { 255,128,64 }; // SIZE의 형 && 이름의 중복 문제

	std::cout << "비트연산자\n";
	enum class textAttribute : int64_t { // 작게 쓴다면 int16_t
		Bold = 1, Italic = 2, Underline = 4,
		SuperText = 8589934592 // 2^33
	};
	long long textAttrs = 0;
	textAttrs |= (int64_t)textAttribute::SuperText;
	textAttrs |= (int)textAttribute::Bold;
	std::cout << "32bit로 표현할 수 없는 숫자일 경우 : " << textAttrs << "\n"; // 8589934592 + 1

	std::cout << "if문으로 사용 가능\n";
	enum struct Colors {
		Red, Green, Blue,
	};
	int colors = (int)Colors::Red;
	if (colors == (int)Colors::Red) printf("%s", "RED\n");
	else if (colors == (int)Colors::Green) printf("%s", "GREEN\n");
	else if (colors == (int)Colors::Blue) printf("%s", "BLUE\n");

	int colors2 = (int)(Colors)1; // 0 == Red, 1 == Green, 2 == Blue
	if (colors2 == (int)Colors::Red) printf("%s", "RED\n");
	else if (colors2 == (int)Colors::Green) printf("%s", "GREEN\n");
	else if (colors2 == (int)Colors::Blue) printf("%s", "BLUE\n");
	;
}
void array1Summary() {
	std::cout << "배열 선언" << "\n";
	int nums[3]{ 1,2,3 };
	int nums1[]{ 1,2,3 };
	std::cout << "sizeof :" << sizeof(nums) << "\n";
	std::cout << "size :" << sizeof(nums) / sizeof(int) << "\n";
	std::cout << "std::size " << std::size(nums) << "\n";
	for (auto i : nums) std::cout << i << "\n";
	for (auto i : nums1) std::cout << i << "\n";

	std::cout << "배열 복사" << "\n";
	int nums2[]{ 1,2,3 };
	int nums3[]{ 4,5,6 };
	memcpy(&nums2, &nums3, sizeof(nums2));
	// memcpy(nums2, nums3, sizeof(nums2)); 주소값 위와 같음
	// copy(nums2, nums3 + 3 , nums2);  // integer pointer, +1당 4btye를 더함 => num3시작점 ~ num3시작점 + 12btye
	for (auto i : nums2) std::cout << i << "\n";

	std::cout << "홀수 모두 더하기" << "\n";
	int nums5[] = { 1,2,3,1,2,3,1,2 };
	int ret = 0;
	for (int i = 0; i < std::size(nums5); i++) ret ^= nums5[i];
	std::cout << ret << "\n";

	std::cout << "bubble sort" << "\n";
	for (int i = 0; i < std::size(nums5); ++i) {
		for (int j = 0; j < std::size(nums5) - i - 1; ++j) {
			if (nums5[j] > nums5[j + 1]) {
				std::swap(nums5[j], nums5[j + 1]);
			};
		}
	}
	for (auto i : nums5) std::cout << i << "\n";

	std::cout << "매트릭스 복사" << "\n";
	int matrix[3][3] = {
		{1,2,3}, {4,5,6},{7,8,9}
	};

	int matrix1[3][3] = {};
	std::cout << sizeof(matrix) << "\n";
	memcpy(&matrix1, &matrix, sizeof(matrix));
	std::copy(&matrix[0][0], &matrix[0][0] + 3 * 3, &matrix1[0][0]); // fill도 같음

	std::cout << "매트릭스 메모리 초기화" << "\n";
	memset(&matrix, 0, sizeof(&matrix)); // 0 or 1
	std::fill(&matrix[0][0], &matrix[0][0] + 3 * 3, 0); // 대부분 가능

	return;
}
void array2Summary() {

	std::array<int, 1000> arr1 = { 1,2,3 };
	int arr2[1000] = { 1,2,3 };

	std::cout << "1. at으로 선언하면 릴리즈시 범위 체크" << "\n";
	std::cout << arr1.at(0) << std::endl;
	// std::cout << arr2.at(1) << "\n"; Error! at이 존재하지 않음

	std::cout << "2. size 체크하기" << "\n";
	std::cout << arr1.size() << " " << sizeof(arr2) / sizeof(int) << "\n";

	std::cout << "3. front, back 구하기" << "\n";
	std::cout << arr1.front() << arr2[0] << "\n";
	std::cout << arr1.back() << arr1[arr1.size() - 1] << arr2[(sizeof(arr2) / sizeof(int)) - 1] << "\n";

	std::cout << "4. swap" << "\n";
	std::array<int, 5> a1{ 1,2,3,4,5 };
	std::array<int, 5> a2{ 6,7,8,9,10 };
	a1.swap(a2);
	for (auto i : a1) std::cout << i << " ";
	swap(a2, a1);
	std::cout << std::endl;
	for (auto i : a1) std::cout << i << " ";

	std::cout << "4. 길이가 같은 배열일 경우 asignment, 비교 가능" << "\n";
	if (a2 > a1) std::cout << "a2[0] 가 a[0]보다 큼 같다면 다음 원소 비교\n";
	a2 = a1;
	for (auto i : a1) std::cout << i << " ";
	std::cout << std::endl;
	if (a1 == a2) std::cout << "a2 is a1";

	std::cout << "5. 배열의 주소 접근" << "\n";
	std::cout << a1.data() << "\n";
	std::cout << a1.data()[0] << "\n";

	// 그외
	std::array<std::string, 5> a3 = { "Hello, world!", "foo" };
	std::array<char, 4> a4 = { "bar" };
	std::array<std::pair<int, int>, 5> a5 = { makePair(1,2),makePair(3,4) ,std::pair<int,int>(5,6) };
}

std::pair<int, int> makePair(int a, int b) {
	return std::pair<int, int>(a, b);
}
void array3Summary() {
	struct Person {
		float weight;
		float height;
	};
	Person persons[]{
		Person(70.7f, 175.6f),
		Person(77.7f, 180.5f)
	};

	std::cout << "1. rang-based for는 값을 가져온다." << "\n";
	for (Person person : persons) { // for (Person& person : persons) => 이렇게 주소를 가져오면 변함
		std::cout << person.weight << " ";
		person.weight = 0; // weight는 값이라서 persons[i].weight에 영향을 주지 못함
	};
	std::cout << "\n";
	std::cout << "rang-based for 1 : " << "\n";
	for (Person person : persons) {
		std::cout << person.weight << " ";
	};
	std::cout << "\n";
	std::cout << "일반 for문으로 persons[i].weight를 건들면 참조 주소를 가져와서 값이 영구적으로 변함 : " << "\n";
	for (int i = 0; i < sizeof(persons) / sizeof(Person); i++) {
		persons[i].weight = 0;
	}
	std::cout << "rang-based for 2 : " << "\n";
	for (Person person : persons) {
		std::cout << person.weight << " ";
	};
};

void pointerBasicSummary() {
	/* ***************************************************
	 pointer = 메모리 주소를 가지고 있는 변수
	 int p =  1995 : (address)aaaazx123
	 int* p = (value)aaaazx123  : (memory adress)ex123a12asd
	*************************************************** */

	/*
	1. *val => 값을 가르킴, &val => 주소를 기르킴
	2. pointer = 주소를 가르키는 값을 가짐
	3. int* pointer = &val; *&val == *pointer
	*/

	std::cout << "1.메모리의 주소, 포인터 => 변수의 주소를 값으로 가짐, 변수의 주소, 변수의 값" << "\n";
	int num = 147;
	int num2 = 147;
	int* pointer = &num; // 값으로 주소를 가질 떈 타입을 int*으로 선언해야 함
	std::cout << "num의 value : " << num << "\n";
	std::cout << "num의 address : " << &num << "\n";
	std::cout << "pointer의 value : " << pointer << " = " << &num << "\n";
	std::cout << "potiner의 address : " << &pointer << "\n";

	std::cout << "2. 역참조, dereferencing" << "\n";
	*pointer = 0; // *pointer == *&num
	if (num != num2) std::cout << num << "\n";
	std::cout << *&num << "\n"; //(주소)&num가 가르키는 값 == *&num

	std::cout << "3. warning : undefined behiver" << "\n";
	int* pnum = 0;
	// pnum = NULL;
	std::cout << "주소를 가르키는 값 : " << pnum << "\n";
	// std::cout << "주소가 가지고 있는 값 : " << *pnum << "\n";// ERROR! 엑세스위반 nullptr
	std::cout << "0이라는 주소 값이 가르키고 있는 메모리의 주소 :" << &pnum << "\n";

	std::cout << "4. int* pointer에서 int의 역할은?" << "\n";

	union Union { // i f d의 메모리 주소는 값음
		int i;
		float f;
		double d;
	};
	struct Struct {
		float f;
		double d;
		int i;
	};

	Union u; // union = 여러 속성 중 하나만 선택, 그럼 나머지 속성의 값은 어떻게 변하나?
	std::cout << "union : 메모리 주소 같음" << "\n";
	std::cout << &u << " " << &u.i << " " << &u.f << " " << &u.d << "\n";
	Struct s;
	std::cout << "struct : 메모리 주소 다름" << "\n";
	std::cout << &s << " " << &s.i << " " << &s.f << " " << &s.d << "\n";

	int* ip = (int*)&u; // u의 주소를 미리 int 포인터 주소값으로 강제 변환
	float* fp = (float*)&u; // 미리 float 포인터 주소값으로 강제 변환
	double* dp = (double*)&u;  // 미리 double 포인터 주소값으로 강제 변환

	u.i = 1; // Union u를 int로 정함
	std::cout << *ip << "\n";
	std::cout << *fp << "\n";
	std::cout << *dp << "\n";

	std::cout << "포인터의 값을 강제 변환 => false" << "\n";
	std::cout << *ip << "\n";
	std::cout << (int)*fp << "\n";
	std::cout << (int)*dp << "\n";

	std::cout << "포인터 와 constant" << "\n";
	int n1 = 10;
	int n2 = 20;
	const int* p1 = &n1; // const int* p1 => const *p1 => const int n1
	p1 = &n2; // 가능!
	// *p1 = n2 불가능!

	int* const p2 = &n1;
	// p2 = &n2; 불가능!
	*p2 = n1; // 가능!

	const int* const p3 = &n1;
	// p3 = &n2; 불가능!
	// *p3 = n2; 불가능!

	int n3 = 30;
	int n4 = 40;
	const int* p4 = &n3; // int* p4 = const int &n3; 이거랑 비슷한 느낌
	p4 = &n4;
	std::cout << '\n';
	std::cout << p4 << &n4 << &n3 << "\n"; // 같 같 다름
	std::cout << *p4 << n4 << n3 << "\n"; // 같 같 다름
}
void pointerArraySummary() {
	std::cout << "1. decay, 배열이 포인터로 변함 (배열의 특성이 사라짐)" << "\n";
	int nums[]{ 1,2,3 };
	int* pNums1 = nums;
	int* pNums2 = &nums[0]; //int* pNums2 = nums[0]; 이건 안됨
	// int pointer에 배열의 주소를 넣어서 사이즈가 달라짐 64bit라서 => 8btye, nums=> 12btye
	std::cout << sizeof(pNums1) << " " << sizeof(nums) << "\n";

	// nums, &nums[0]는 동일함, c의 규칙
	std::cout << &nums << "\n";
	std::cout << pNums1 << "\n";
	std::cout << pNums2 << "\n";

	std::cout << "2. int array pointer, int pointer" << "\n";
	std::cout << typeid(1).name() << "\n";
	std::cout << typeid(nums).name() << "\n"; // nums는 array integer임
	std::cout << "(* __ptr64)[3], * __ptr64는 같음 typeid로 넘어가면서 배열이 붙어서 나오는 거 뿐" << "\n";
	std::cout << typeid(&nums).name() << "\n"; // &nums == &nums[0]랑 같음 c 규칙
	std::cout << typeid(&nums[0]).name() << "\n";

	std::cout << "3. 포인터에 대괄호 연산자 사용 가능" << "\n";  // 포인터는 배열과 같다고 말하는 사람도 있다
	std::cout << pNums1[0] << pNums1[1] << pNums1[2] << "\n";

	std::cout << "4. 포인터에 숫자를 더할 수 있음" << "\n";
	/// <summary>
	/// integer potiner이기 떄문에 +1을하면 4btype가 증가됨 즉
	/// asdasd0가 nums[0]일때, nums[0]의 주소값은는 4btye더해서 asdasd4가됨 asdasd4는 nums[1]과 같음 
	/// </summary>

	int nums1[]{ 1,2,3 };
	int* pNums3 = nums1;
	std::cout << pNums3 + 1 << "\n"; // 4btye씩 주소가 증가
	std::cout << pNums3 + 2 << "\n";
	std::cout << pNums3 + 3 << "\n";

	std::cout << *(pNums3) << "\n";
	std::cout << *(pNums3 + 1) << "\n";
	std::cout << *(pNums3 + 2) << "\n";

	std::cout << "5. 포인터는 이런 짓도 가능함 (포인터 ++하기)" << "\n";
	int nums2[]{ 1,2,3 };
	int* pNums4 = nums2;
	std::cout << *pNums4 << "\n"; // *pNums4 => *pNums4[0]
	// 
	pNums4++;
	std::cout << *pNums4 << "\n";
	// nums2++ 이건 안됨 nonmodifiable임
	return;
}
void pointerStringSummary() {
	char str0[] = "abcd";
	char* str1 = str0;
	const char* str2 = str0;
	std::cout << typeid(str1).name() << std::endl;
	std::cout << typeid(str2).name() << std::endl;

	std::cout << "1. const char*" << "\n";
	// str1[0] =  'c'; // 이런짓이 불가능하게 char potiner는 const char*로 선언해줘야함, char는 상수라서?
	// 근데 int*도 아래처럼 변경 가능한데?
	std::cout << std::strlen(str2) << "\n";
	std::cout << str1 << "\n";
	str1[0] = 'c';
	std::cout << str1 << "\n";

	int a[3] = { 1,2,3 };
	int* pnum = a;
	pnum[0] = 0;
	for (auto i : a) std::cout << i << " ";
	std::cout << "\n";

	//srtcpy, stycmp

	std::cout << "2. char pointer에 char함수 적용됨" << "\n";
	char str3[100] = "foo";
	const char* pstr1 = &str3[0]; // ==  const char* pstr2 = str3;
	const char* pstr2 = "barbo";
	strcpy(str3, pstr2);
	// strcpy(pstr2, str3)는 불가능
	std::cout << str3 << "\n";
	std::cout << strcmp(str3, pstr2) << "\n";
}
void dynamicAssignSummary() {
	// 동적할당 Heap에 위치함 int a = new int[4];
	// 자동할당 stack에 쌓임 int a = 0;

	int* pNum = new int;// unnamed, 동적 할당
	delete pNum;// 안지우면 메모리 계속 늘어남..

	std::cout << "1. 메모리 누수" << "\n";
	//while (true) { int* num = new int; }

	std::cout << "2. 지운걸 또 지우거나, 참조하고 있는 변수가 지워지면 에러가 남" << "\n"; // 엄청 주의해야함!
	int* pnum1 = new int(123);
	int* pnum2 = pnum1;
	delete pnum1;
	// delete pnum1;
	std::cout << *pnum2 << "\n"; // 포인터를 지웠으니까 참조 변수가 쓰레기값이 나옴 
	int* pnum3;
	{
		int n = 10;
		pnum3 = &n;
	}
	std::cout << *pnum3 << "\n"; // n이 해제되었기때문에 다른 os에서 된다는 보장이 없음

	std::cout << "3. 동적 배열할당 (cin 정수 눌러주기)" << "\n";

	int s;
	std::cin >> s;
	int* arr = new int[s] {1, 2, 3};
	if (sizeof(*arr) / sizeof(int) > 1) {
		arr[1] = 1;
		std::cout << arr[1] << "\n";
	}
	std::cout << "4. delete[]" << "\n";
	delete[] arr; // delete[]로 해제


	std::cout << "4. 구조체 동적할당" << "\n";
	struct Person {
		float weight;
		float height;
	};
	// 포인터가 가르키는 값의 메서드 호출 "->"
	Person* person = new Person{ 75.5f, 177.4f };
	std::cout << person->height << (*person).weight << "\n";

	Person* persons[2] = {
		new Person{56.5f, 177.3f},
		new Person{77.7f, 150.55f}
	};

	for (Person* person : persons) person->weight = 0;
	for (Person* person : persons) std::cout << person->weight << " ";
	std::cout << "\n";
}
void nullptrSummary() {
	using namespace std;
	cout << "1. 포인터를 delete하면 nullptr를 할당해주는 습관을 가지자" << "\n";
	int* p = new int;
	delete p;
	p = nullptr;
	// ...엄청 긴 로직...
	cout << p << "\n";
	cout << nullptr << "\n";
	if (p != nullptr) cout << p << "\n";
	else cout << "p is nullptr" << "\n";
	cout << "2. func(nullptr)은 안됨 func(NULL)은 0이 감.. c11 이상시 nullptr사용하기" << "\n";
}
void
pointerVoldSummary() {
	using namespace std;
	cout << "1. void는 형이 없다는 걸 나타내는 형" << "\n";
	// vold i; 불가능
	int num = 10;
	int* p = &num;
	cout << p << "\n";

	cout << "2. void*에 다른 타입포인터를 할당가능" << "\n";
	void* vp = p;
	// cout << *vp << "\n"; // vp는 읽는 거 차제가 안됨
	float* p0 = (float*)vp;
	int* p1 = (int*)vp; // integer pointer로 void pointer를 변환
	cout << *p0 << "\n"; // int*는 int*로 변환해야함
	cout << *p1 << "\n";

	cout << "3. void*를 어따 씀 => 어떤 type의 포인터인지 알 수 없을 떄" << "\n";
	void* vp0 = malloc(sizeof(int) * 3); // 12btye를  heap어딘가에 할당하고(동적 할당) 보이드 포인터로 반환함(메모리 주소를가르키는 포인터)
	int* intp = (int*)vp0;

	free(vp0); // delete랑 같음  지워야하는 포인터의 타입인지 모를 떄 사용가능
	free(intp);
}
void pointerVectorSummary() {
	using namespace std;
	int s;
	// cin >> s;
	// array<int,s>* arr = new array<int.s> ..?
	// array<int, s>가 안됨..
	cout << "1. 숫자 큰 거 아무거나 입력 : ";
	cin >> s;
	std::vector<int> vec0(s); // 동적 사이즈 조정 가능
	std::vector<int> vec1(5, 2);

	cout << "2. 동적 사이즈 조정" << "\n";
	vec0.resize(3);
	for (auto i : vec1) cout << i << " ";
	cout << endl;
	vec1.resize(6, 3);
	for (auto i : vec1) cout << i << " ";
	cout << endl;

	cout << "3. 동적 배열이라 사이즈를 늘리면 재할당이 일어날 수 있음" << "\n";
	vector<int> vec3;

	for (int i = 0; i < 10; i++) {
		vec3.push_back(i);
		cout << vec3.size() << " " << vec3.data() << "\n";
	}

	cout << "4. capacity를 미리 정해두면 동적 할당이 안일어남" << "\n";
	vector<int> vec4;
	vec4.reserve(1000);
	for (int i = 0; i < 10; i++) {
		vec4.push_back(i);
		cout << vec4.size() << " " << vec4.data() << "\n";
	}

	cout << "5. 길이 달라도 비교, 할당 가능" << "\n";
	vector<int> vec5 = { 1,2 };
	vector<int> vec6 = { 5,4,3,2,1 };
	vec6 = vec5;
	for (auto i : vec5) cout << i << " ";
}
void referenceSummary() {

	std::cout << "1. 참조 하기" << "\n";
	int num0 = 10;
	const int& num1 = num0; // num0 값의 주소를 가진 변수, const -> (할당x, 변경x), const 뺴면 (할당o, 변경o)
	int* num2 = &num0;
	// 	int* num2 = &num1; const라서 불가능! 


	// 참조 변수는 선언 후 참조주소를 변경할 수 없음!
	// int& num3; 불가능
	// cont int* nul3 = 1은 가능
	// 포인터는 아래처럼 바꾸는 거 가능!
	int* ptr1 = nullptr;
	ptr1 = &num0;

	std::cout << "2. 참조값은 전부 변경됨 " << "\n";
	int num3 = 9;
	// num1 = num3; const라서 불가능!
	*num2 = num3;
	std::cout << num1 << *num2 << num3 << "\n"; // 참조 변수는 dereferencing필요없음 간단함!

	std::vector<int> v;
	std::vector<int>& vr = v;
	std::vector<int>* vp = &vr;

	std::cout << "3. vector 참조하기" << "\n";
	v.push_back(1); vr.push_back(2); vp->push_back(3);
	for (auto i : v) std::cout << i << " ";
	std::cout << "\n";

	std::cout << "4. 참조쓸때 조심할 거" << "\n";
	int* n0 = new int(12);
	int& n1 = *n0;

	std::cout << n1 << "\n";
	delete n0;
	std::cout << n1 << "\n"; // undefined behavior
	n0 = nullptr;
	std::cout << n1 << "\n"; // undefined behavior

	std::cout << "5. 참조랑 포인터랑 결과가 같게 쓰기" << "\n";

	// www.compiler explorer
	// 아래 코드를 비교해보면 기계어 코드가 같음 (내부적으로 reference는 pointer랑 같음)
	// reference는 포인터를 사용하기 쉽게 변형한 것 (오버로딩, 패스바이)
	/// <summary>
	/// int a = 3;
	/// int& b = a;
	/// int c = a + b;
	/// 
	/// int a = 3;
	/// int *b = &a;
	/// int c = a + *b;
	/// </summary>

	int a1 = 10;
	int& a2 = a1;
	int* const a3 = &a1;
	// a2, a3은 거의 동일함

}
void functionBasicSummary(int argc, char* argv[]) {
	std::cout << argc << "\n";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << "\n"; // C:\Users\interbird\source\repos\peacepiece7\cpp-playground\x64\Debug\syntax_basic.exe
	}
	// cd C:\Users\interbird\source\repos\peacepiece7\cpp-playground\x64\Debug에 .exe파일이 있음


	// summary
	// cd C:\Users\interbird\source\repos\peacepiece7\cpp-playground\x64\Debug
	// syntax_basic.exe Hello world! 실행해보기
	// argc => 배열의 개수
	// argv => 공백으로 파라메터를 구분해서 받은 배열
	// summary
}

struct Node
{
	int value;
	Node* left;
	Node* right;
};
void visit(Node* root) {
	if (root == nullptr) return;
	visit(root->left);
	std::cout << root->value << "\n";
	visit(root->right);
}
void recursionSummary() {
	Node node0{ 0 };
	Node node1{ 1 };
	Node node2{ 2 };
	Node node3{ 3 };
	Node node4{ 4 };
	Node node5{ 5 };
	Node node6{ 6 };
	Node node7{ 7 };
	Node node8{ 8 };
	Node node9{ 9 };
	node0.left = &node1;
	node1.left = &node2;
	node1.right = &node3;
	node3.right = &node4;
	node0.right = &node5;
	node6.right = &node7;
	node5.right = &node8;
	node8.left = &node9;
	visit(&node0);
}

void swap(int px, int py) {
	// 이렇게짜면 px, py는 x,y의 복사니까 x,y변경안됨 &로 주소를 줘야함
	std::cout << "px :" << &px << ", py :" << &py << "\n";
	int temp = px;
	px = py;
	py = temp;
}
void swap2(int* px, int* py) {
	// 이렇게짜면 px, py는 x,y의 복사니까 x,y변경안됨 &로 주소를 줘야함
	std::cout << "px :" << px << ", py :" << py << "\n";
	int temp = *px;
	px = py;
	py = &temp;
}
struct Weapon {
	int price;
	int power;
};
void upgrade(Weapon weapon) {
	weapon.power += 10;
	weapon.price += 10;
}
void passByValueSummary() {
	int x = 10, y = 20;
	// 값으로 전달
	swap(x, y);
	std::cout << "x :" << &x << ", y :" << &y << "\n";
	// 주소로 전달
	swap2(&x, &y);
	std::cout << "x :" << &x << ", y :" << &y << "\n";
}

// => 여기 아래부터 공부 더하고 다시 봅시다 !!
void upgread1(Weapon* weapon) {
	(*weapon).price += 10;
	weapon->power += 10;
}
void print(const Weapon* weapon) {
	// const Weapon* 이렇게 작성하면 포인터의 값을 변경할 수 없음
	std::cout << weapon->power << "\n";
	std::cout << weapon->price << "\n";

	const Weapon* weapon0 = weapon; // 가능
	// Weapon* weapon1 = weapon; const Weapon은 const로 받아야함 (포인터가 가르키는 값을 변경을 못하도록)
}
void func(int nums[4]) {
	std::cout << typeid(nums).name() << "\n"; // pointer로 받기 때문에 배열의 사이즈 정보를 잃어버림(decay됨), 이래서 vector array권장함
	//for (int i : nums) { } range base for 불가능 일반 for은 가능
}
int* func1() {
	int nums2[4]{ 1,2,3,4 };
	return nums2;
}
void func2(int argc, char** argv) {
	for (int i = 0; i < argc; ++i) {
		std::cout << argv[i] << "\n";
	}
}
void func3(int argc, char(*argv)[5]) {
	// char (*argv)[5] => char 5개짜리를 가르키는 포인터
	// char* argv[5] => 더블 포인터임
	for (int i = 0; i < argc; ++i) {
		std::cout << argv[i] << "\n";
	}
}
void passByAddressSummary(int argc, char** argv) {
	std::cout << "1. 참조로 전달" << "\n";
	Weapon weapon(10, 20);
	upgread1(&weapon);
	// print(weapon);// -> 값을 복사하는데 비용이 발생

	std::cout << "2. const Weapon* => 값이 변경되지 않음을 보장해줌" << "\n";
	print(&weapon);

	std::cout << "3. 배열을 인자로 전달할 경우 배열 포인터로 받아서 속성(사이즈)를 잃어버림" << "\n";
	int nums[4]{ 1,2,3,4 };
	func(nums);
	//	func1(); 이런식으로 짜면 함수가 사라지면서 값을 잃을수도 있음, 조심할것

	// 여기 아래는 이해 못했슴
	std::cout << "4. argv[]는 더블 포인터임" << "\n";
	func2(argc, argv);
	char strs[][5] = { "abcd", "efgh" };
	func3(2, strs);
	// char** => 8byte씩 더함
	// |8바이트 주소|8바이트 주소|8바이트 주소|8바이트 주소| ...
	// -> |"syntax_basic.exe"| ...
	// char[2][5] => 5byte씩 더해야 한다
	//->  |"abcd\0"|"efgh\0"|
}

void swap4(int& px, int& py) {
	int tmp = px;
	py = px;
	px = tmp;
}
void passByReferenceSummary() {
	// 구조체처럼 사이즈가 클때, 원본을 변경할 수 없게 값을 전달하고 싶디면 const int&를 사용
	// int같은 경우 간단하게 넘겨도 됨
	std::cout << "1. 포인터를 추상화(내부적 동작을 감춤) => 참조" << "\n";
	int x = 10, y = 20;
	swap(x, y);
	std::cout << x << " " << y << '\n';

	int num[] = { 1,2,3,4 };
	for (const int& num : num) {
		// 객체를 바꾸지 않을거면 const int& (의도를 명확하게 하기)
	}
	// const int&는 임시객체를 생성하고 임시 객체를 가르킴, 어차피 다른 값을 못 가르키니까 10 같은 변수도 const int&에 할당 가능
	const int& n = 10;



}

int ppow(int base, int exp = 2) { //int pow(int base = 2, int exp) 이렇게는 안됨 default뒤 파라메터는 전부 default가 필요함
	int ret = 1;
	for (int i = 0; i < exp; i++) {
		ret *= base;
	}
	return ret;
}
// int ppow(int, int = 3); // 디폴트 매개변수를 한 번 더 쓰고 싶으면 각 파일에서 왼쪽 코드를 선언하면 됨 
struct Person {
	float height;
	float weight;
};
Person p{ 66.6f, 166.6f };
void foo(Person p0 = p) { //  인스턴스 객체를 default값으로 할당
	std::cout << p0.height << "\n";
	std::cout << p0.weight << "\n";
}
void print(Person* p0 = nullptr) {
	if (p0) {
		std::cout << (*p0).weight << "\n";
		std::cout << p0->height << "\n";
	}
	else {
		std::cout << "invalid" << "\n";
	}
}
void defaultParameterSummmary() {
	std::cout << "1. 디폴트 매개변수 " << "\n";
	std::cout << ppow(2) << "\n";

	std::cout << "2. 구조체 디폴트 매개변수" << "\n";
	foo();
	foo({ 77.7f, 177.7f });

	std::cout << "3, 매개변수 예외처리하기" << "\n";
	print();
	Person p{ 55.f,155.f };
	print(&p);
}

int countDigit(int n) {
	int cnt = 0;
	if (n == 0) return 1;
	while (n) {
		n /= 10;
		cnt++;
	}
	return cnt;
}
int countDigit(std::string str) {
	return countDigit(stoi(str));
}
void func11(int, int) { return; } // func11#int-int 
void func11(char) { return; } // func11#char
void functionOverloadingSummary() {
	using namespace std;
	std::cout << "1. 함수 오버로딩 " << "\n";
	// 파라메터의 타입, 개수에 대해서만 오버로딩이 가능 반환타입은 같아야 함
	cout << countDigit(12345) << "\n";
	cout << countDigit("12345") << "\n";

	std::cout << "2. static binding" << "\n";
	// 컴파일할때 실행한 함수를 파라매터 타입에 맞게 바인딩 시켜줌
	// 객체지향의 다형성에 해당된다고 함..
	func11(10, 10); // func11#int-int
	func11('a'); // func11#char

	cout << "3. cout 함수 오버로딩, cout함수 자세히 보기하면 다른 함수로 오버로딩됨" << "n";
	std::cout << 'a' << "\n";
	std::cout << (int)'a' << "\n";
}

int sum(int x, int y) {
	return x + y;
}
enum struct RequestType {
	Login, Register, Delete, Update // 0,1,2,3
};
bool onLogin(std::string id, std::string password) {
	std::cout << "onLogin" << "\n";
	std::cout << id << "\n";
	std::cout << password << "\n";
	return true;
}
bool onRegister(std::string id, std::string password) {
	std::cout << "onRegister" << "\n";
	std::cout << id << "\n";
	std::cout << password << "\n";
	return true;
}
bool onDelete(std::string id, std::string password) {
	std::cout << "onDelete" << "\n";
	std::cout << id << "\n";
	std::cout << password << "\n";
	return true;
}
bool onUpdate(std::string id, std::string oldPassword) {
	std::cout << "onUpdate" << "\n";
	std::cout << id << "\n";
	std::cout << "oldPassword :" << oldPassword << "\n";
	// std::cout << "newPassword :" << newPassword << "\n";
	return true;
}
struct Character {
	int health;
	void (*dieCallback)();
};
void damaged(Character& character) {
	character.health -= 100;
	if (character.health <= 0) {

		if (character.dieCallback) {
			character.dieCallback();
		}
		else {
			std::cout << "died" << "\n";
		}
	}
}
void gameOver()
{
	std::cout << "game over" << "\n";
}
void gameOverBySignal(int signal)
{
	std::cout << "game over" << "\n";
}
void functionPointerSummary() {
	// 함수도 읽기 전용 메모리 블럭에 존재함 => 주소를 가져올 수 있을까?
	// 함수의 주소는? 함수가 포함된 기계어 코드 메모리블록의 시작 주소에 들어감
	std::cout << "1. 함수 포인터 " << "\n";
	int (*f)(int, int) = &sum; // int* f(int,int)는 int포인터를 반환하는거라 (*f)해야함
	int (*f2)(int, int) = sum; // &안써도 함수는 허용해줌
	std::cout << (*f)(1, 2) << "\n";
	std::cout << f(1, 3) << "\n"; // 역참조가 없어도 허용해줌

	std::cout << "2. 함수 reference" << "\n";
	int(&r)(int, int) = sum;
	std::cout << r(4, 6) << "\n";

	// 함수는 역참조하면 함수가됨....
	std::cout << (*r)(4, 7) << "\n";
	std::cout << (*sum)(1, 2) << "\n";

	std::cout << "3. 로그인 기능 구현하기" << "\n";
	// 함수 포인터를 받는 배열
	bool (*callbacks[])(std::string, std::string) {
		onLogin, onRegister, onDelete, onUpdate  // 0,1,2,3
	};

	// (int)RequestType::Login = 0이니까 callbacks[0]("david","1234") 이렇게 실행
	callbacks[(int)RequestType::Login]("david", "1234");
	callbacks[(int)RequestType::Login]("John", "2222");
	callbacks[(int)RequestType::Delete]("david", "1234");
	// callbacks[(int)RequestType::Update]("John", "3333", "1234"); 이런건 어떻게 할까?

	std::cout << "4. 케릭터 체력 만들기" << "\n";
	Character character0{ 200, nullptr }; // 몬스터가 죽으면 게임오버 안뜸
	Character character1{ 200 , gameOver }; // 플레이어가 죽으면 게임오버

	damaged(character0);
	damaged(character0);

	damaged(character1);
	damaged(character1);

	std::cout << "5. 함수 포인터 같은 긴타임의 선언은 auto로 하면 편하다" << "\n";
	auto f5 = &gameOver; // void (*)()
	auto f6 = gameOver; // 알아서 형을 맞춰줌, 함수포인터는 주소를 안적어도 된다.
	auto& f7 = gameOver;


	std::cout << "6. callable하게 사용하기.." << "\n";
	std::function<void()> fff = gameOver;
	std::function<void(int)> ff = gameOverBySignal;
	ff(1);
	fff();
}