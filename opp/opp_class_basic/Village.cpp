#include "Village.h"

#include "PersonHeader.h" // PersonHeader 내부를 알아야해서 include함, (참조라던가 내부 private 값이라던가 필요해서)
void Village::add(PersonHeader person) {
	persons.push_back(person);
}