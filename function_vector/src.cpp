#include <bits/stdc++.h>;

std::vector<int> v;
std::vector<int> v1(5, 100);
int main() {


	printf("%s\n", "declare vector explicitly");
	for (int i : v1) std::cout << i << std::endl;

	for (int i = 10; i >= 1; i--) v.push_back(i);
	for (int i : v) std::cout << i << std::endl;

	printf("TEST!\n");
	// std::cout << v << std::endl; <= "cant access directly!"
	std::cout << v.size() << std::endl;
	std::cout << &v << std::endl;
	std::cout << v[0] << v[1] << v[2] << v[3] << v[4] << v[5] << v[6] << std::endl;

	printf("%s\n", "pop back");
	v.pop_back();
	for (int i : v) std::cout << i << std::endl;

	printf("%s\n", "erase");
	v.erase(v.begin(), v.begin() + 1);
	for (int i : v) std::cout << i << std::endl;

	auto a = find(v.begin(), v.end(), 100);
	if (a == v.end()) std::cout << "not found" << std::endl;
	// else std::cout << a << std::endl;

	printf("%s\n", "fill");
	fill(v.begin(), v.end(), 10);
	for (int i : v) std::cout << i << std::endl;

	printf("%s\n", "clear");
	v.clear();
	for (int i : v) std::cout << i << std::endl;

	return 0;

}