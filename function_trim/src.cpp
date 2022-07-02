#pragma warning (disable:4996);
#include <bits/stdc++.h>

using namespace std;

static inline void ltrim(string& s)
{
	s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) {
		cout << ch << endl;
		return !std::isspace(ch);
		}));
}

static inline void rtrim(string& s)
{
	s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
		return !std::isspace(ch);
		}).base(), s.end());
}
static inline void trim(string& s)
{
	rtrim(s);
	ltrim(s);

}

// trim from start (copying)
static inline std::string ltrim_copy(std::string s) {
	ltrim(s);
	return s;
}

// trim from end (copying)
static inline std::string rtrim_copy(std::string s) {
	rtrim(s);
	return s;
}

// trim from both ends (copying)
static inline std::string trim_copy(std::string s) {
	trim(s);
	return s;
}


vector<string> split(string input, string delimiter) {
	vector<string> ret;
	long long pos = 0;
	string tocken = "";
	while (input.find(delimiter) != string::npos) {

		pos = input.find(delimiter);
		tocken = input.substr(0, pos);
		ret.push_back(tocken);
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
		trim(str);
		cout << str << endl;
	}
}