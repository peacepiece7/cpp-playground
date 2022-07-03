#pragma warning (disable:4996);
#include <bits/stdc++.h>

using namespace std;

vector<string> split(string input, string delimiter) {
	vector<string> ret;
	long long pos = 0;
	string token = "";
	while (input.find(delimiter) != string::npos) {

		pos = input.find(delimiter);
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	ret.push_back(input);
	return ret;
}

int main()
{
	string s = "the brown fox jumps over the lazy dog";
	string del = "brown";

	vector<string> answer = split(s, del);

	for (string str : answer)
	{
		cout << str << endl;
	}
}