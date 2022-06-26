#include <iostream>

int main() {
	// ~ not , & and, | or, ^ xor, << >> (lt rt shift operator)
	int num = 0; //default : signed int
	unsigned int  num1 = 0;

	std::cout << ~num << std::endl;
	// 1(+, -)1111111111111111111111111111111 => -1
	std::cout << ~num1 << std::endl;
	// 1111111111111111111111111111111111 => 4,3xx,xxx,xxx (2^32 -1)

	// 00000101 = 5  = 4 + 1 = 2^2 + 2^0 
	// 00001010 = 10 = 8 + 2 = 2^3 + 2^1
	// 00000000 = 0

	uint32_t attendanceBook = 5u;
		
	if (attendanceBook &(int) std::pow(2,0)) // 1
		printf("1st");
	if (attendanceBook & (int)std::pow(2, 1)) // 2
		printf("2nd");
	if (attendanceBook & (int)std::pow(2, 2)) // 4
		printf("3th");
	int flag = (int)std::pow(2, 0) + (int)std::pow(2, 1);
	if ((attendanceBook & flag) == flag)
		printf("1 and 2");
	if(attendanceBook & ((int)std::pow(2,0) + (int)std::pow(2,1)))
		printf("1 or 2");
	// 0000000000000000000101 // 32(day) 5u

	//  0000000000000000000001  1day = 1
	//  0000000000000000000010  2day = 2
	//	0000000000000000000100  3day = 4

	// on
	attendanceBook |= ((int)std::pow(2, 2) + (int)std::pow(2, 0));
	// off
	attendanceBook &= ((int)std::pow(2, 0) | (int)std::pow(2, 2));

	std::cout << (1 << 3);

	signed int overNum = 2200000000;
	std::cout << (overNum << 3); // overflow (check decimal to binary)	
}