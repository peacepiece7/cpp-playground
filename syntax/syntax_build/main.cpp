#include <iostream>
#include<string>
using namespace std;

#define SQUARE(X) X*X

int sum(int, int);

int main(int argc, char* argv[]) {
	int total = 0;
	// i[0]�� �������� ���
	SQUARE(1);
	for (int i = 1; i < argc; ++i) {
		string arg(argv[i]);
		int num = stoi(arg);
		total = sum(total, num);
	}
	cout << total << "\n";
	return 0;
}

// summary
// 1. developer command prompt ����
//    visual studio c++ compilter��
// 2. cl, link
//    where cl, where link�ϸ� path����
//    echo &PATH&�ϸ� �ý��� ȯ�溯�� ���� ( where cl, where link) Ȯ�ΰ���
// 3. C:\Users\interbird\source\repos\peacepiece7\cpp-playground\syntax_basic_build ��� ���� �˾Ƴ���
//    cd C:\Users\interbird\source\repos\peacepiece7\cpp-playground\syntax_basic_build
//	  cl main.cpp utill.cpp 
//	  cl main.cpp utill.cpp /EHsc => warning�˾ƺ���
//    
//	  main.exe 30 60
//    90 ���� ����
//	  del *.cpp
//    del *.exe
// 
//    �Ʒ� �� �� �� �ȵ�
//    cl main.cpp 
//    cl utill.cpp 
// 
//	  cl main.cpp utill. /c (�����ϸ��ϰ� link����������), link�� obj�� �����ִ� ���� => .exe������ ����
//    main.cpp => ������ �� ��� main,obj
//	  utill.cpp => �������� ��� utill.cpp������
// 
//   link main.obj utill.obj
//   main.exe�� ������
// 
// 
// 
//   cl main.cpp /P => main.i�� ������, ������ �� ���� (���� �� ���� main.i �о��)
//   SQUARE(1)�� main.i�� 1*1;�� �����
// summary