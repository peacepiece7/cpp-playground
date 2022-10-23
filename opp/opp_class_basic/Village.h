#pragma once // �� �� �ϳ� ���� ��
#ifndef __VILLAGE_H__
#define __VILLAGE_H__

// header file�� pragma once; 
// ���� ���Ͽ��� include "personHeader"�� �� ��, ���ǰ� �ߺ��Ǵϱ� �װ� ������
// pragma => ��ǥ����, �����Ϸ� �����翡�� �˾Ƽ��ϼ���~ (pragma���� ǥ���ΰ͵�����)	
#include<vector>
// #include�� �ϴ� �� => PersonHeader������ ���� �ٿ��ֱ��ϴ� ������ ��
// PersonHeader������ �����ϸ�, include�ϰ��ִ� ��� ������ �� ������ �� (���� ����)
// ���� ���� �Ǿ�������, ���� ������ ������ ������ �ȵ�

class PersonHeader; // forward declaration, ���漱��, #include "PersonHeader.h"���� ����
class Village
{
private:
	std::vector<PersonHeader> persons;
public:
	void add(PersonHeader);
};


#endif 
