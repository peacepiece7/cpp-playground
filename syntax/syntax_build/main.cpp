#include <iostream>
#include<string>
using namespace std;

#define SQUARE(X) X*X

int sum(int, int);

int main(int argc, char* argv[]) {
	int total = 0;
	// i[0]은 실행파일 경로
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
// 1. developer command prompt 열기
//    visual studio c++ compilter임
// 2. cl, link
//    where cl, where link하면 path나옴
//    echo &PATH&하면 시스템 환경변수 나옴 ( where cl, where link) 확인가능
// 3. C:\Users\interbird\source\repos\peacepiece7\cpp-playground\syntax_basic_build 경로 대충 알아내기
//    cd C:\Users\interbird\source\repos\peacepiece7\cpp-playground\syntax_basic_build
//	  cl main.cpp utill.cpp 
//	  cl main.cpp utill.cpp /EHsc => warning알아보기
//    
//	  main.exe 30 60
//    90 나옴 ㅎㅎ
//	  del *.cpp
//    del *.exe
// 
//    아래 두 줄 다 안됨
//    cl main.cpp 
//    cl utill.cpp 
// 
//	  cl main.cpp utill. /c (컴파일만하고 link는하지않음), link는 obj를 묶어주는 역할 => .exe파일이 나옴
//    main.cpp => 컴파일 한 결과 main,obj
//	  utill.cpp => 컴파일한 결과 utill.cpp가나옴
// 
//   link main.obj utill.obj
//   main.exe가 생성됨
// 
// 
// 
//   cl main.cpp /P => main.i가 생성됨, 컴파일 전 상태 (읽을 수 있음 main.i 읽어보기)
//   SQUARE(1)이 main.i는 1*1;로 변경됨
// summary