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
	// ���ڿ��� �� = '\0'
	char str1[] = "abc";
	std::cout << str1[1] << "\n";
	std::cout << strlen(str1) << "\n";

	std::cout << "\n���ڿ���\n";
	char str2[] = "abc";
	char str3[] = "abc";
	char str4[] = "dcf";
	if (str2 == str3) printf("%s", "true"); // false;

	// strcpy strcat strcmp�� ���� ������..
	std::cout << strcmp(str2, str3) << std::endl; // ���� 0
	std::cout << strcmp(str3, str4) << std::endl; // �ٸ� -1

	// strcpy(str2,str3) c�ε� �̰� �޸� ħ���� �� ����
	// strcat(str2, str3); �̰͵� c�ε� ������

	std::cout << "\n���ڿ��� ���ڷ�\n";
	char stri1[] = "1";
	char stri2[] = "1.1";
	int i = atoi(stri1); // ascii to int
	float f = atof(stri2); // ascii to float
	std::cout << i << " " << f << "\n";

	return;
}
void stringSummary() {
	std::string str;
	// cin >> str; helloooooooo ��� �޾Ƶ� ����
	printf("%s", "1. ���ڿ� ��\n");
	std::string str1("abc");
	std::string str2("abc");
	if (str1 == str2) std::cout << "True" << "\n"; // ����
	str1 += str2;
	std::cout << str1 << "\n";

	std::string str3("cdf");
	std::string str4("hij");

	printf("%s", "2. string�� char�� ��ȯ �� strcmp����ϱ�\n");
	int result = strcmp(str3.c_str(), str4.c_str());
	std::cout << result << "\n";

	printf("%s", "3. string ������\n");
	std::cout << str3.length() << " " << str3.size() << "\n";

	printf("%s", "4. ���ڸ� string����\n");

	std::string str5 = std::to_string(123);
	std::string str6 = std::to_string(123.234);


	std::cout << std::fixed; // <= �Ҽ��� �����ص� str6�� 123.234000��
	std::cout.precision(3);

	std::cout << str5 << " " << std::to_string(true) << " " << str6 << " " << str6[5] << "\n";

	std::cout << "\n���ڿ��� ���ڷ�\n";
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
	Person person1 = person; //  struct �Ҵ� ����
	// if (person == person1) operator overloading�� �ʿ�

	Person persons[5];
	Person& person2 = persons[2]; // ���� �ּҸ� ������
	Person person3 = persons[3]; // ���ο� ��ü�� ����
	person2.grade = 5; // persons[2]�� �����
	person3.grade = 5; // ���ο� ��ü�� �����
	std::cout << "person1 : �� ���ɴϴ�            " << persons[2].grade << "\n";
	std::cout << "person2 : ���ǵǾ� ���� �ʽ��ϴ� " << persons[3].grade << "\n";

	//* �޸� ȿ���� ���� �߰� ����
	// ����ū �ڷ������� btye�� ����
	struct aligntest1 {
		float a;   // 4 => 4
		short b;   // 2 => 2(2)
		float c;   // 4 => 4
		char d[10];// 2 => 10(2) ->4�� ��������ϴµ� 22��(2)�߰�
		// => 24btye
	};
	std::cout << "aligntest1 :" << sizeof(aligntest1) << "\n";
	struct aligntest2 {
		float a;   // 4 => 4
		float c;   // 4 => 4
		char d[10];// 10 => 10 // char�� 1btye * 10�� => 18
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
	std::cout << "union == ���� Ÿ���� �Ӽ� �� �ϳ��� �ʿ��� ���" << "\n";
	// !! .idChars������ ,�Ӽ� => ���� �Ӽ� �Ϲ� => C++���ǥ�� �ֽ����� !!
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
	std::cout << "union�� ������� ���� ���" << "\n";
	Product1 item1 = { 1, 12 };
	if (item1.idType == 0) std::cout << item1.idInteger << "\n"; // id�� type�� int���� char ã�ƺ��� ������ �� �� ����
	else std::cout << item1.idChars << "\n";

	std::cout << "union�� ����ϸ� �Ʒ��� ���� ����� �� ����" << "\n";
	Product2 item2 = { 2, {.idChars = "abc"} }; // ���� ������ int, char�� �����ؼ� ����� ��
	Product2 item3 = { 3, {.idInteger = 13} };
	if (item2.idType == 2) std::cout << item2.id.idChars << "\n";
	else std::cout << item3.id.idInteger << "\n";

	std::cout << "union�ȿ��� align�� �������� padding(������� �ʴ� btye)�� �� �۽��ϴ�\n";
	std::cout << sizeof(Product1) << " " << sizeof(Product2) << "\n";// 20 16 (p
}
void unscopedEnumSummary() {
	// type�� �̸� �� �� ���� = enum
	// type�� �� �� �ִ� = struct 
	enum Color1 {
		Red, Blue, Green, Alpha, SIZE // 1, 2, 3, 4, 5�� ���� default�� ������ �� ����
	};

	int colors1[Color1::SIZE] = { 244,255,123 };
	// ������ 0�� Alpha�� ���ǵ��� �ʾƼ� 0��
	for (int i = 0; i < SIZE; i++) std::cout << colors1[i] << " ";
	std::cout << "\n";
	colors1[Alpha] = 444;
	for (int i = 0; i < SIZE; i++) std::cout << colors1[i] << " ";

	struct Color2 {
		int red, blue, green, alpha, size = 4;
	};
	Color2 colors2 = { 255,254,253,111 };

	std::cout << "�ؽ�Ʈ�� ���� �Ӽ� �߰��ϱ�" << "\n";
	enum TextAttribute {
		// 1 2 4 8
		Bold = 0b0001,
		Underline = 0b0010,
		Italic = 0b0100,
		Strikethrough = 0b1000
	};
	int textAttrs = 0;
	textAttrs |= TextAttribute::Bold; // �������� ������, scope��������, c++11���� ����
	textAttrs |= Underline;

	std::cout << "textAttrs�� italic�� �ֳ���? : ";
	if (textAttrs & Italic) std::cout << "YES\n";
	else std::cout << "NO\n";
	std::cout << "textAttrs�� Bold�� �ֳ���? : ";
	if (textAttrs & Bold) std::cout << "YES\n";
	else std::cout << "NO\n";
	std::cout << "textAttrs�� ����? : 0b0011 = ";
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
	std::cout << "scoped�� �� ��ȯ�� �ʼ�\n";
	// a1 |= scopedAttribute::Bold => Error!
	a1 |= (int)scopedAttribute::Bold; // Works!
	int sum1 = Bar + (int)scopedAttribute::Underline;

	std::cout << "unscoped�� �� ��ȯ�� �ʼ��� �ƴ�\n";
	// int sum =  Bold + Underline => Error!
	int sum = Bar + unscopedEnumFoo::Foo; // Works!


	std::cout << "enum���� �迭�� ������ ���ϱ�\n";
	int scopedColors[(int)scopedColor::SIZE] = { 255,128,64 }; // String type Good!
	// int unscopedColor[SIZE] = { 255,128,64 }; // SIZE�� �� && �̸��� �ߺ� ����

	std::cout << "��Ʈ������\n";
	enum class textAttribute : int64_t { // �۰� ���ٸ� int16_t
		Bold = 1, Italic = 2, Underline = 4,
		SuperText = 8589934592 // 2^33
	};
	long long textAttrs = 0;
	textAttrs |= (int64_t)textAttribute::SuperText;
	textAttrs |= (int)textAttribute::Bold;
	std::cout << "32bit�� ǥ���� �� ���� ������ ��� : " << textAttrs << "\n"; // 8589934592 + 1

	std::cout << "if������ ��� ����\n";
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
	std::cout << "�迭 ����" << "\n";
	int nums[3]{ 1,2,3 };
	int nums1[]{ 1,2,3 };
	std::cout << "sizeof :" << sizeof(nums) << "\n";
	std::cout << "size :" << sizeof(nums) / sizeof(int) << "\n";
	std::cout << "std::size " << std::size(nums) << "\n";
	for (auto i : nums) std::cout << i << "\n";
	for (auto i : nums1) std::cout << i << "\n";

	std::cout << "�迭 ����" << "\n";
	int nums2[]{ 1,2,3 };
	int nums3[]{ 4,5,6 };
	memcpy(&nums2, &nums3, sizeof(nums2));
	// memcpy(nums2, nums3, sizeof(nums2)); �ּҰ� ���� ����
	// copy(nums2, nums3 + 3 , nums2);  // integer pointer, +1�� 4btye�� ���� => num3������ ~ num3������ + 12btye
	for (auto i : nums2) std::cout << i << "\n";

	std::cout << "Ȧ�� ��� ���ϱ�" << "\n";
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

	std::cout << "��Ʈ���� ����" << "\n";
	int matrix[3][3] = {
		{1,2,3}, {4,5,6},{7,8,9}
	};

	int matrix1[3][3] = {};
	std::cout << sizeof(matrix) << "\n";
	memcpy(&matrix1, &matrix, sizeof(matrix));
	std::copy(&matrix[0][0], &matrix[0][0] + 3 * 3, &matrix1[0][0]); // fill�� ����

	std::cout << "��Ʈ���� �޸� �ʱ�ȭ" << "\n";
	memset(&matrix, 0, sizeof(&matrix)); // 0 or 1
	std::fill(&matrix[0][0], &matrix[0][0] + 3 * 3, 0); // ��κ� ����

	return;
}
void array2Summary() {

	std::array<int, 1000> arr1 = { 1,2,3 };
	int arr2[1000] = { 1,2,3 };

	std::cout << "1. at���� �����ϸ� ������� ���� üũ" << "\n";
	std::cout << arr1.at(0) << std::endl;
	// std::cout << arr2.at(1) << "\n"; Error! at�� �������� ����

	std::cout << "2. size üũ�ϱ�" << "\n";
	std::cout << arr1.size() << " " << sizeof(arr2) / sizeof(int) << "\n";

	std::cout << "3. front, back ���ϱ�" << "\n";
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

	std::cout << "4. ���̰� ���� �迭�� ��� asignment, �� ����" << "\n";
	if (a2 > a1) std::cout << "a2[0] �� a[0]���� ŭ ���ٸ� ���� ���� ��\n";
	a2 = a1;
	for (auto i : a1) std::cout << i << " ";
	std::cout << std::endl;
	if (a1 == a2) std::cout << "a2 is a1";

	std::cout << "5. �迭�� �ּ� ����" << "\n";
	std::cout << a1.data() << "\n";
	std::cout << a1.data()[0] << "\n";

	// �׿�
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

	std::cout << "1. rang-based for�� ���� �����´�." << "\n";
	for (Person person : persons) { // for (Person& person : persons) => �̷��� �ּҸ� �������� ����
		std::cout << person.weight << " ";
		person.weight = 0; // weight�� ���̶� persons[i].weight�� ������ ���� ����
	};
	std::cout << "\n";
	std::cout << "rang-based for 1 : " << "\n";
	for (Person person : persons) {
		std::cout << person.weight << " ";
	};
	std::cout << "\n";
	std::cout << "�Ϲ� for������ persons[i].weight�� �ǵ�� ���� �ּҸ� �����ͼ� ���� ���������� ���� : " << "\n";
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
	 pointer = �޸� �ּҸ� ������ �ִ� ����
	 int p =  1995 : (address)aaaazx123
	 int* p = (value)aaaazx123  : (memory adress)ex123a12asd
	*************************************************** */

	/*
	1. *val => ���� ����Ŵ, &val => �ּҸ� �⸣Ŵ
	2. pointer = �ּҸ� ����Ű�� ���� ����
	3. int* pointer = &val; *&val == *pointer
	*/

	std::cout << "1.�޸��� �ּ�, ������ => ������ �ּҸ� ������ ����, ������ �ּ�, ������ ��" << "\n";
	int num = 147;
	int num2 = 147;
	int* pointer = &num; // ������ �ּҸ� ���� �� Ÿ���� int*���� �����ؾ� ��
	std::cout << "num�� value : " << num << "\n";
	std::cout << "num�� address : " << &num << "\n";
	std::cout << "pointer�� value : " << pointer << " = " << &num << "\n";
	std::cout << "potiner�� address : " << &pointer << "\n";

	std::cout << "2. ������, dereferencing" << "\n";
	*pointer = 0; // *pointer == *&num
	if (num != num2) std::cout << num << "\n";
	std::cout << *&num << "\n"; //(�ּ�)&num�� ����Ű�� �� == *&num

	std::cout << "3. warning : undefined behiver" << "\n";
	int* pnum = 0;
	// pnum = NULL;
	std::cout << "�ּҸ� ����Ű�� �� : " << pnum << "\n";
	// std::cout << "�ּҰ� ������ �ִ� �� : " << *pnum << "\n";// ERROR! ���������� nullptr
	std::cout << "0�̶�� �ּ� ���� ����Ű�� �ִ� �޸��� �ּ� :" << &pnum << "\n";

	std::cout << "4. int* pointer���� int�� ������?" << "\n";

	union Union { // i f d�� �޸� �ּҴ� ����
		int i;
		float f;
		double d;
	};
	struct Struct {
		float f;
		double d;
		int i;
	};

	Union u; // union = ���� �Ӽ� �� �ϳ��� ����, �׷� ������ �Ӽ��� ���� ��� ���ϳ�?
	std::cout << "union : �޸� �ּ� ����" << "\n";
	std::cout << &u << " " << &u.i << " " << &u.f << " " << &u.d << "\n";
	Struct s;
	std::cout << "struct : �޸� �ּ� �ٸ�" << "\n";
	std::cout << &s << " " << &s.i << " " << &s.f << " " << &s.d << "\n";

	int* ip = (int*)&u; // u�� �ּҸ� �̸� int ������ �ּҰ����� ���� ��ȯ
	float* fp = (float*)&u; // �̸� float ������ �ּҰ����� ���� ��ȯ
	double* dp = (double*)&u;  // �̸� double ������ �ּҰ����� ���� ��ȯ

	u.i = 1; // Union u�� int�� ����
	std::cout << *ip << "\n";
	std::cout << *fp << "\n";
	std::cout << *dp << "\n";

	std::cout << "�������� ���� ���� ��ȯ => false" << "\n";
	std::cout << *ip << "\n";
	std::cout << (int)*fp << "\n";
	std::cout << (int)*dp << "\n";

	std::cout << "������ �� constant" << "\n";
	int n1 = 10;
	int n2 = 20;
	const int* p1 = &n1; // const int* p1 => const *p1 => const int n1
	p1 = &n2; // ����!
	// *p1 = n2 �Ұ���!

	int* const p2 = &n1;
	// p2 = &n2; �Ұ���!
	*p2 = n1; // ����!

	const int* const p3 = &n1;
	// p3 = &n2; �Ұ���!
	// *p3 = n2; �Ұ���!

	int n3 = 30;
	int n4 = 40;
	const int* p4 = &n3; // int* p4 = const int &n3; �̰Ŷ� ����� ����
	p4 = &n4;
	std::cout << '\n';
	std::cout << p4 << &n4 << &n3 << "\n"; // �� �� �ٸ�
	std::cout << *p4 << n4 << n3 << "\n"; // �� �� �ٸ�
}
void pointerArraySummary() {
	std::cout << "1. decay, �迭�� �����ͷ� ���� (�迭�� Ư���� �����)" << "\n";
	int nums[]{ 1,2,3 };
	int* pNums1 = nums;
	int* pNums2 = &nums[0]; //int* pNums2 = nums[0]; �̰� �ȵ�
	// int pointer�� �迭�� �ּҸ� �־ ����� �޶��� 64bit�� => 8btye, nums=> 12btye
	std::cout << sizeof(pNums1) << " " << sizeof(nums) << "\n";

	// nums, &nums[0]�� ������, c�� ��Ģ
	std::cout << &nums << "\n";
	std::cout << pNums1 << "\n";
	std::cout << pNums2 << "\n";

	std::cout << "2. int array pointer, int pointer" << "\n";
	std::cout << typeid(1).name() << "\n";
	std::cout << typeid(nums).name() << "\n"; // nums�� array integer��
	std::cout << "(* __ptr64)[3], * __ptr64�� ���� typeid�� �Ѿ�鼭 �迭�� �پ ������ �� ��" << "\n";
	std::cout << typeid(&nums).name() << "\n"; // &nums == &nums[0]�� ���� c ��Ģ
	std::cout << typeid(&nums[0]).name() << "\n";

	std::cout << "3. �����Ϳ� ���ȣ ������ ��� ����" << "\n";  // �����ʹ� �迭�� ���ٰ� ���ϴ� ����� �ִ�
	std::cout << pNums1[0] << pNums1[1] << pNums1[2] << "\n";

	std::cout << "4. �����Ϳ� ���ڸ� ���� �� ����" << "\n";
	/// <summary>
	/// integer potiner�̱� ������ +1���ϸ� 4btype�� ������ ��
	/// asdasd0�� nums[0]�϶�, nums[0]�� �ּҰ����� 4btye���ؼ� asdasd4���� asdasd4�� nums[1]�� ���� 
	/// </summary>

	int nums1[]{ 1,2,3 };
	int* pNums3 = nums1;
	std::cout << pNums3 + 1 << "\n"; // 4btye�� �ּҰ� ����
	std::cout << pNums3 + 2 << "\n";
	std::cout << pNums3 + 3 << "\n";

	std::cout << *(pNums3) << "\n";
	std::cout << *(pNums3 + 1) << "\n";
	std::cout << *(pNums3 + 2) << "\n";

	std::cout << "5. �����ʹ� �̷� ���� ������ (������ ++�ϱ�)" << "\n";
	int nums2[]{ 1,2,3 };
	int* pNums4 = nums2;
	std::cout << *pNums4 << "\n"; // *pNums4 => *pNums4[0]
	// 
	pNums4++;
	std::cout << *pNums4 << "\n";
	// nums2++ �̰� �ȵ� nonmodifiable��
	return;
}
void pointerStringSummary() {
	char str0[] = "abcd";
	char* str1 = str0;
	const char* str2 = str0;
	std::cout << typeid(str1).name() << std::endl;
	std::cout << typeid(str2).name() << std::endl;

	std::cout << "1. const char*" << "\n";
	// str1[0] =  'c'; // �̷����� �Ұ����ϰ� char potiner�� const char*�� �����������, char�� �����?
	// �ٵ� int*�� �Ʒ�ó�� ���� �����ѵ�?
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

	std::cout << "2. char pointer�� char�Լ� �����" << "\n";
	char str3[100] = "foo";
	const char* pstr1 = &str3[0]; // ==  const char* pstr2 = str3;
	const char* pstr2 = "barbo";
	strcpy(str3, pstr2);
	// strcpy(pstr2, str3)�� �Ұ���
	std::cout << str3 << "\n";
	std::cout << strcmp(str3, pstr2) << "\n";
}
void dynamicAssignSummary() {
	// �����Ҵ� Heap�� ��ġ�� int a = new int[4];
	// �ڵ��Ҵ� stack�� ���� int a = 0;

	int* pNum = new int;// unnamed, ���� �Ҵ�
	delete pNum;// ������� �޸� ��� �þ..

	std::cout << "1. �޸� ����" << "\n";
	//while (true) { int* num = new int; }

	std::cout << "2. ����� �� ����ų�, �����ϰ� �ִ� ������ �������� ������ ��" << "\n"; // ��û �����ؾ���!
	int* pnum1 = new int(123);
	int* pnum2 = pnum1;
	delete pnum1;
	// delete pnum1;
	std::cout << *pnum2 << "\n"; // �����͸� �������ϱ� ���� ������ �����Ⱚ�� ���� 
	int* pnum3;
	{
		int n = 10;
		pnum3 = &n;
	}
	std::cout << *pnum3 << "\n"; // n�� �����Ǿ��⶧���� �ٸ� os���� �ȴٴ� ������ ����

	std::cout << "3. ���� �迭�Ҵ� (cin ���� �����ֱ�)" << "\n";

	int s;
	std::cin >> s;
	int* arr = new int[s] {1, 2, 3};
	if (sizeof(*arr) / sizeof(int) > 1) {
		arr[1] = 1;
		std::cout << arr[1] << "\n";
	}
	std::cout << "4. delete[]" << "\n";
	delete[] arr; // delete[]�� ����


	std::cout << "4. ����ü �����Ҵ�" << "\n";
	struct Person {
		float weight;
		float height;
	};
	// �����Ͱ� ����Ű�� ���� �޼��� ȣ�� "->"
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
	cout << "1. �����͸� delete�ϸ� nullptr�� �Ҵ����ִ� ������ ������" << "\n";
	int* p = new int;
	delete p;
	p = nullptr;
	// ...��û �� ����...
	cout << p << "\n";
	cout << nullptr << "\n";
	if (p != nullptr) cout << p << "\n";
	else cout << "p is nullptr" << "\n";
	cout << "2. func(nullptr)�� �ȵ� func(NULL)�� 0�� ��.. c11 �̻�� nullptr����ϱ�" << "\n";
}
void
pointerVoldSummary() {
	using namespace std;
	cout << "1. void�� ���� ���ٴ� �� ��Ÿ���� ��" << "\n";
	// vold i; �Ұ���
	int num = 10;
	int* p = &num;
	cout << p << "\n";

	cout << "2. void*�� �ٸ� Ÿ�������͸� �Ҵ簡��" << "\n";
	void* vp = p;
	// cout << *vp << "\n"; // vp�� �д� �� ������ �ȵ�
	float* p0 = (float*)vp;
	int* p1 = (int*)vp; // integer pointer�� void pointer�� ��ȯ
	cout << *p0 << "\n"; // int*�� int*�� ��ȯ�ؾ���
	cout << *p1 << "\n";

	cout << "3. void*�� ��� �� => � type�� ���������� �� �� ���� ��" << "\n";
	void* vp0 = malloc(sizeof(int) * 3); // 12btye��  heap��򰡿� �Ҵ��ϰ�(���� �Ҵ�) ���̵� �����ͷ� ��ȯ��(�޸� �ּҸ�����Ű�� ������)
	int* intp = (int*)vp0;

	free(vp0); // delete�� ����  �������ϴ� �������� Ÿ������ �� �� ��밡��
	free(intp);
}
void pointerVectorSummary() {
	using namespace std;
	int s;
	// cin >> s;
	// array<int,s>* arr = new array<int.s> ..?
	// array<int, s>�� �ȵ�..
	cout << "1. ���� ū �� �ƹ��ų� �Է� : ";
	cin >> s;
	std::vector<int> vec0(s); // ���� ������ ���� ����
	std::vector<int> vec1(5, 2);

	cout << "2. ���� ������ ����" << "\n";
	vec0.resize(3);
	for (auto i : vec1) cout << i << " ";
	cout << endl;
	vec1.resize(6, 3);
	for (auto i : vec1) cout << i << " ";
	cout << endl;

	cout << "3. ���� �迭�̶� ����� �ø��� ���Ҵ��� �Ͼ �� ����" << "\n";
	vector<int> vec3;

	for (int i = 0; i < 10; i++) {
		vec3.push_back(i);
		cout << vec3.size() << " " << vec3.data() << "\n";
	}

	cout << "4. capacity�� �̸� ���صθ� ���� �Ҵ��� ���Ͼ" << "\n";
	vector<int> vec4;
	vec4.reserve(1000);
	for (int i = 0; i < 10; i++) {
		vec4.push_back(i);
		cout << vec4.size() << " " << vec4.data() << "\n";
	}

	cout << "5. ���� �޶� ��, �Ҵ� ����" << "\n";
	vector<int> vec5 = { 1,2 };
	vector<int> vec6 = { 5,4,3,2,1 };
	vec6 = vec5;
	for (auto i : vec5) cout << i << " ";
}
void referenceSummary() {

	std::cout << "1. ���� �ϱ�" << "\n";
	int num0 = 10;
	const int& num1 = num0; // num0 ���� �ּҸ� ���� ����, const -> (�Ҵ�x, ����x), const ���� (�Ҵ�o, ����o)
	int* num2 = &num0;
	// 	int* num2 = &num1; const�� �Ұ���! 


	// ���� ������ ���� �� �����ּҸ� ������ �� ����!
	// int& num3; �Ұ���
	// cont int* nul3 = 1�� ����
	// �����ʹ� �Ʒ�ó�� �ٲٴ� �� ����!
	int* ptr1 = nullptr;
	ptr1 = &num0;

	std::cout << "2. �������� ���� ����� " << "\n";
	int num3 = 9;
	// num1 = num3; const�� �Ұ���!
	*num2 = num3;
	std::cout << num1 << *num2 << num3 << "\n"; // ���� ������ dereferencing�ʿ���� ������!

	std::vector<int> v;
	std::vector<int>& vr = v;
	std::vector<int>* vp = &vr;

	std::cout << "3. vector �����ϱ�" << "\n";
	v.push_back(1); vr.push_back(2); vp->push_back(3);
	for (auto i : v) std::cout << i << " ";
	std::cout << "\n";

	std::cout << "4. �������� ������ ��" << "\n";
	int* n0 = new int(12);
	int& n1 = *n0;

	std::cout << n1 << "\n";
	delete n0;
	std::cout << n1 << "\n"; // undefined behavior
	n0 = nullptr;
	std::cout << n1 << "\n"; // undefined behavior

	std::cout << "5. ������ �����Ͷ� ����� ���� ����" << "\n";

	// www.compiler explorer
	// �Ʒ� �ڵ带 ���غ��� ���� �ڵ尡 ���� (���������� reference�� pointer�� ����)
	// reference�� �����͸� ����ϱ� ���� ������ �� (�����ε�, �н�����)
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
	// a2, a3�� ���� ������

}
void functionBasicSummary(int argc, char* argv[]) {
	std::cout << argc << "\n";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << "\n"; // C:\Users\interbird\source\repos\peacepiece7\cpp-playground\x64\Debug\syntax_basic.exe
	}
	// cd C:\Users\interbird\source\repos\peacepiece7\cpp-playground\x64\Debug�� .exe������ ����


	// summary
	// cd C:\Users\interbird\source\repos\peacepiece7\cpp-playground\x64\Debug
	// syntax_basic.exe Hello world! �����غ���
	// argc => �迭�� ����
	// argv => �������� �Ķ���͸� �����ؼ� ���� �迭
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
	// �̷���¥�� px, py�� x,y�� ����ϱ� x,y����ȵ� &�� �ּҸ� �����
	std::cout << "px :" << &px << ", py :" << &py << "\n";
	int temp = px;
	px = py;
	py = temp;
}
void swap2(int* px, int* py) {
	// �̷���¥�� px, py�� x,y�� ����ϱ� x,y����ȵ� &�� �ּҸ� �����
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
	// ������ ����
	swap(x, y);
	std::cout << "x :" << &x << ", y :" << &y << "\n";
	// �ּҷ� ����
	swap2(&x, &y);
	std::cout << "x :" << &x << ", y :" << &y << "\n";
}

// => ���� �Ʒ����� ���� ���ϰ� �ٽ� ���ô� !!
void upgread1(Weapon* weapon) {
	(*weapon).price += 10;
	weapon->power += 10;
}
void print(const Weapon* weapon) {
	// const Weapon* �̷��� �ۼ��ϸ� �������� ���� ������ �� ����
	std::cout << weapon->power << "\n";
	std::cout << weapon->price << "\n";

	const Weapon* weapon0 = weapon; // ����
	// Weapon* weapon1 = weapon; const Weapon�� const�� �޾ƾ��� (�����Ͱ� ����Ű�� ���� ������ ���ϵ���)
}
void func(int nums[4]) {
	std::cout << typeid(nums).name() << "\n"; // pointer�� �ޱ� ������ �迭�� ������ ������ �Ҿ����(decay��), �̷��� vector array������
	//for (int i : nums) { } range base for �Ұ��� �Ϲ� for�� ����
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
	// char (*argv)[5] => char 5��¥���� ����Ű�� ������
	// char* argv[5] => ���� ��������
	for (int i = 0; i < argc; ++i) {
		std::cout << argv[i] << "\n";
	}
}
void passByAddressSummary(int argc, char** argv) {
	std::cout << "1. ������ ����" << "\n";
	Weapon weapon(10, 20);
	upgread1(&weapon);
	// print(weapon);// -> ���� �����ϴµ� ����� �߻�

	std::cout << "2. const Weapon* => ���� ������� ������ ��������" << "\n";
	print(&weapon);

	std::cout << "3. �迭�� ���ڷ� ������ ��� �迭 �����ͷ� �޾Ƽ� �Ӽ�(������)�� �Ҿ����" << "\n";
	int nums[4]{ 1,2,3,4 };
	func(nums);
	//	func1(); �̷������� ¥�� �Լ��� ������鼭 ���� �������� ����, �����Ұ�

	// ���� �Ʒ��� ���� ���߽�
	std::cout << "4. argv[]�� ���� ��������" << "\n";
	func2(argc, argv);
	char strs[][5] = { "abcd", "efgh" };
	func3(2, strs);
	// char** => 8byte�� ����
	// |8����Ʈ �ּ�|8����Ʈ �ּ�|8����Ʈ �ּ�|8����Ʈ �ּ�| ...
	// -> |"syntax_basic.exe"| ...
	// char[2][5] => 5byte�� ���ؾ� �Ѵ�
	//->  |"abcd\0"|"efgh\0"|
}

void swap4(int& px, int& py) {
	int tmp = px;
	py = px;
	px = tmp;
}
void passByReferenceSummary() {
	// ����üó�� ����� Ŭ��, ������ ������ �� ���� ���� �����ϰ� �͵�� const int&�� ���
	// int���� ��� �����ϰ� �Ѱܵ� ��
	std::cout << "1. �����͸� �߻�ȭ(������ ������ ����) => ����" << "\n";
	int x = 10, y = 20;
	swap(x, y);
	std::cout << x << " " << y << '\n';

	int num[] = { 1,2,3,4 };
	for (const int& num : num) {
		// ��ü�� �ٲ��� �����Ÿ� const int& (�ǵ��� ��Ȯ�ϰ� �ϱ�)
	}
	// const int&�� �ӽð�ü�� �����ϰ� �ӽ� ��ü�� ����Ŵ, ������ �ٸ� ���� �� ����Ű�ϱ� 10 ���� ������ const int&�� �Ҵ� ����
	const int& n = 10;



}

int ppow(int base, int exp = 2) { //int pow(int base = 2, int exp) �̷��Դ� �ȵ� default�� �Ķ���ʹ� ���� default�� �ʿ���
	int ret = 1;
	for (int i = 0; i < exp; i++) {
		ret *= base;
	}
	return ret;
}
// int ppow(int, int = 3); // ����Ʈ �Ű������� �� �� �� ���� ������ �� ���Ͽ��� ���� �ڵ带 �����ϸ� �� 
struct Person {
	float height;
	float weight;
};
Person p{ 66.6f, 166.6f };
void foo(Person p0 = p) { //  �ν��Ͻ� ��ü�� default������ �Ҵ�
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
	std::cout << "1. ����Ʈ �Ű����� " << "\n";
	std::cout << ppow(2) << "\n";

	std::cout << "2. ����ü ����Ʈ �Ű�����" << "\n";
	foo();
	foo({ 77.7f, 177.7f });

	std::cout << "3, �Ű����� ����ó���ϱ�" << "\n";
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
	std::cout << "1. �Լ� �����ε� " << "\n";
	// �Ķ������ Ÿ��, ������ ���ؼ��� �����ε��� ���� ��ȯŸ���� ���ƾ� ��
	cout << countDigit(12345) << "\n";
	cout << countDigit("12345") << "\n";

	std::cout << "2. static binding" << "\n";
	// �������Ҷ� ������ �Լ��� �Ķ���� Ÿ�Կ� �°� ���ε� ������
	// ��ü������ �������� �ش�ȴٰ� ��..
	func11(10, 10); // func11#int-int
	func11('a'); // func11#char

	cout << "3. cout �Լ� �����ε�, cout�Լ� �ڼ��� �����ϸ� �ٸ� �Լ��� �����ε���" << "n";
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
	// �Լ��� �б� ���� �޸� ���� ������ => �ּҸ� ������ �� ������?
	// �Լ��� �ּҴ�? �Լ��� ���Ե� ���� �ڵ� �޸𸮺���� ���� �ּҿ� ��
	std::cout << "1. �Լ� ������ " << "\n";
	int (*f)(int, int) = &sum; // int* f(int,int)�� int�����͸� ��ȯ�ϴ°Ŷ� (*f)�ؾ���
	int (*f2)(int, int) = sum; // &�Ƚᵵ �Լ��� �������
	std::cout << (*f)(1, 2) << "\n";
	std::cout << f(1, 3) << "\n"; // �������� ��� �������

	std::cout << "2. �Լ� reference" << "\n";
	int(&r)(int, int) = sum;
	std::cout << r(4, 6) << "\n";

	// �Լ��� �������ϸ� �Լ�����....
	std::cout << (*r)(4, 7) << "\n";
	std::cout << (*sum)(1, 2) << "\n";

	std::cout << "3. �α��� ��� �����ϱ�" << "\n";
	// �Լ� �����͸� �޴� �迭
	bool (*callbacks[])(std::string, std::string) {
		onLogin, onRegister, onDelete, onUpdate  // 0,1,2,3
	};

	// (int)RequestType::Login = 0�̴ϱ� callbacks[0]("david","1234") �̷��� ����
	callbacks[(int)RequestType::Login]("david", "1234");
	callbacks[(int)RequestType::Login]("John", "2222");
	callbacks[(int)RequestType::Delete]("david", "1234");
	// callbacks[(int)RequestType::Update]("John", "3333", "1234"); �̷��� ��� �ұ�?

	std::cout << "4. �ɸ��� ü�� �����" << "\n";
	Character character0{ 200, nullptr }; // ���Ͱ� ������ ���ӿ��� �ȶ�
	Character character1{ 200 , gameOver }; // �÷��̾ ������ ���ӿ���

	damaged(character0);
	damaged(character0);

	damaged(character1);
	damaged(character1);

	std::cout << "5. �Լ� ������ ���� ��Ÿ���� ������ auto�� �ϸ� ���ϴ�" << "\n";
	auto f5 = &gameOver; // void (*)()
	auto f6 = gameOver; // �˾Ƽ� ���� ������, �Լ������ʹ� �ּҸ� ����� �ȴ�.
	auto& f7 = gameOver;


	std::cout << "6. callable�ϰ� ����ϱ�.." << "\n";
	std::function<void()> fff = gameOver;
	std::function<void(int)> ff = gameOverBySignal;
	ff(1);
	fff();
}