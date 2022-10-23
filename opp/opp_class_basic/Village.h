#pragma once // 둘 중 하나 쓰면 됨
#ifndef __VILLAGE_H__
#define __VILLAGE_H__

// header file의 pragma once; 
// 여러 파일에서 include "personHeader"를 할 떄, 정의가 중복되니까 그걸 막아줌
// pragma => 비표준임, 컴파일러 벤더사에서 알아서하세요~ (pragma에서 표준인것도있음)	
#include<vector>
// #include가 하는 일 => PersonHeader파일을 복사 붙여넣기하는 행위를 함
// PersonHeader파일을 변경하면, include하고있는 모든 파일이 다 변경이 됨 (의존 관계)
// 전방 선언 되어있으면, 전방 선언한 파일은 변경이 안됨

class PersonHeader; // forward declaration, 전방선언, #include "PersonHeader.h"보다 좋음
class Village
{
private:
	std::vector<PersonHeader> persons;
public:
	void add(PersonHeader);
};


#endif 
