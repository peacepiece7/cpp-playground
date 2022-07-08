#include<bits/stdc++.h>

std::vector<int> input = { 1,6,11 ,99,124,554,1665 };
std::vector<int> check(input.size());
std::string answer = "NO";

void permutation(int L) {
	if (L == input.size()) {
		int cmp1 = 0;
		int cmp2 = 0;
		for(int i = 0; i < check.size(); ++i)
		{
			if (check[i]) cmp1 += input[i];
			else cmp2 += input[i];
		}
		std::cout << "compare 1 :" << cmp1 << " " << "compare 2 : " << cmp2 << std::endl;
		std::cout << std::endl;

		if (cmp1 == cmp2) answer = "YES";
		return;
	}	
	check[L] = 1;
	permutation(L + 1);
	check[L] = 0;
	permutation(L + 1);
}

int main() {
	permutation(0);
	std::cout << answer << std::endl;
	return 0;
}