#include "Village.h"

#include "PersonHeader.h" // PersonHeader ���θ� �˾ƾ��ؼ� include��, (��������� ���� private ���̶���� �ʿ��ؼ�)
void Village::add(PersonHeader person) {
	persons.push_back(person);
}